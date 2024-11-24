#pragma once

#include <functional>
#include <vector>


// #include "myconfig.h"
#include "HydroPart.h"
#include "InitialConditions.h"


// #include "swift2/kernels/legacy/Density.h"
// #include "swift2/kernels/legacy/SmoothingLength.h"
// #include "swift2/kernels/legacy/Swift.h"
// #include "tarch/tarch.h"


namespace smlUnitTest {

  using hydroPart = tests::swift2::testSML1D::globaldata::HydroPart;


  /**
   * Set some global/static parameters.
   */
  void setStaticParams(
    int                                         dimension,
    struct initialConditions::InitialConditions ic
  );


  /**
   * Grab the pointer to a specific particle
   **/
  hydroPart* getLocalParticle(std::vector<hydroPart*> particleList, int index);


  /**
   * Generate particles, and return list of pointers to them.
   **/
  std::vector<hydroPart*> initParticles(
    struct initialConditions::InitialConditions ic
  );


  /**
   * Clean up allocated particles from the list.
   **/
  void cleanParticleList(std::vector<hydroPart*> particleList);


  /**
   * Run the actual smoothing length computation test.
   *
   * @param ic an initial conditions object, containing particle data and
   * solutions.
   * @param check_all Whether to check all particles. If true, this test
   * will loop over all available particles given in the ICs. If false, it
   * will loop only over the particle indices specified in the IC object
   * as ic.indexBegin and ic.indexEnd. This is to avoid weird constellations
   * with particles around the edges that don't have enough neighbours, as
   * we're not doing periodic boundary conditions here.
   * @param verbose if true, print additional info to screen
   * @param abort_on_error if true, abort on first error
   */
  void runTest(
    struct initialConditions::InitialConditions ic,
    int                                         dimension,
    bool                                        check_all,
    bool                                        verbose,
    bool                                        abort_on_error
  );

} // namespace smlUnitTest
