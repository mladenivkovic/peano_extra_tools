
#include <iostream>
#include <iomanip>


#include "HydroPart.h"
#include "smlUnitTest.h"


#include "swift2/kernels/legacy/Density.h"
#include "swift2/kernels/legacy/SmoothingLength.h"
#include "swift2/kernels/legacy/Swift.h"



namespace smlUnitTest {

  using hydroPart = tests::swift2::testSML1D::globaldata::HydroPart;


  /**
   * Set some global/static parameters.
   */
  void setStaticParams(int dimension, struct initialConditions::InitialConditions ic){

    if (dimension == 1){
      hydroPart::_hydroDimensions = 1;
      hydroPart::_etaFactor = ic.resolution_eta;
      hydroPart::_smlMin = 1e-06;
      hydroPart::_smlMax = 0.05;
      hydroPart::_smlTolerance = ic.h_tolerance;
    hydroPart::_smlMaxIterations = 50;
    } else if (dimension == 2){
      hydroPart::_hydroDimensions = 2;
      hydroPart::_etaFactor = ic.resolution_eta;
      hydroPart::_smlMin = 1e-06;
      hydroPart::_smlMax = 0.20;
      hydroPart::_smlMaxIterations = 50;
      hydroPart::_smlTolerance = ic.h_tolerance;
    } else if (dimension == 3){
      hydroPart::_hydroDimensions = 3;
      hydroPart::_etaFactor = ic.resolution_eta;
      hydroPart::_smlMin = 1e-06;
      hydroPart::_smlMax = 0.20;
      hydroPart::_smlMaxIterations = 50;
      hydroPart::_smlTolerance = ic.h_tolerance;
    } else {
      std::cerr << "Invalid number of dimensions: "<< dimension << std::endl;
      std::abort();
    }

    // SML min and max are supposed to be global simulation parameters, not
    // really something we determine from ICs. However, we can make sure
    // that the ICs don't encroach on these limits.
    if (hydroPart::_smlMin > ic.h_min) {
      std::cerr << "Error: hydroPart::_smlMin > h_min in ICs" << std::endl;
      std::abort();
    }
    if (hydroPart::_smlMax < ic.h_max) {
      std::cerr << "Error: hydroPart::_smlMax < h_max in ICs" << std::endl;
      std::abort();
    }
  }


  /**
   * Grab the pointer to a specific particle
   **/
  hydroPart* getLocalParticle(std::list<hydroPart*> particleList, int index){

    int j = 0;
    for (std::list<hydroPart*>::iterator i = particleList.begin(); i != particleList.end(); i++){
      if (j == index) return *i;
      j++;
    }
    return nullptr;
  }



  /**
   * Generate particles, and return list of pointers to them.
   **/
  std::list<hydroPart*> initParticles(struct initialConditions::InitialConditions ic){

    std::list<hydroPart*> particleList;

    for (int p = 0; p < ic.sampleSize; p++){

      hydroPart *part = new hydroPart();

      part->setX(0, ic.coords[p][0]);
#if Dimensions > 1
      part->setX(1, ic.coords[p][1]);
#endif
#if Dimensions > 2
      part->setX(2, ic.coords[p][2]);
#endif

      part->setSmoothingLength(ic.sml_init[p]);
      part->setPartid(ic.ids[p]);

      // TODO: TEMPORARY
      part->setSearchRadius(1.);
      // part->setSearchRadius(1.54919353837087214742e-01);
      part->setMass(1.);
      part->setPressure(1.);
      part->setU(1.);

      part->setV(0, 0.);
#if Dimensions > 1
      part->setV(1, 0.);
#endif
#if Dimensions > 2
      part->setV(2, 0.);
#endif

      part->setSmoothingLengthIterCount(0);
      part->setDensityNeighbourCount(0);

      ::swift2::kernels::legacy::first_init_particle(part);

      particleList.push_back(part);
    }

    return particleList;
  }



  /**
   * Clean up allocated particles from the list.
   **/
  void cleanParticleList(std::list<hydroPart*> particleList){

    for (auto part: particleList){
      delete part;
    }
    particleList.clear();
  }




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
  void runTest(struct initialConditions::InitialConditions ic, int dimension, bool check_all, bool verbose, bool abort_on_error){

    // Talk to me
    std::cout << "Running '" << ic.name << "'\n";

    double mindiff = 1e30;
    double maxdiff = -1.;

    // Set up
    std::list<hydroPart*> particleList = initParticles(ic);
    setStaticParams(dimension, ic);

    if (ic.sampleSize <= 20) {
      std::cerr << "IC sample size must be > 20, is=" << ic.sampleSize << std::endl;
      std::abort();
    }

    int start = ic.indexBegin;
    int stop = ic.indexEnd;
    if (check_all){
      start = 0;
      stop = ic.sampleSize;
    }
    int error = 0;
    int max_iterations = 0;

    // Main loop: Over all particles
    // -----------------------------
    for (int localParticleIndex = start; localParticleIndex < stop; localParticleIndex++){
      // We could to this for all particles simultaneously, but I don't want to.
      // Go particle by particle.

      hydroPart *localParticle = getLocalParticle(particleList, localParticleIndex);

      double h_solution = ic.sml_solution[localParticleIndex];


      // Main smoothing length iteration loop
      // ------------------------------------
      int iteration = 0;
      while (iteration < hydroPart::getSmlMaxIterations() ){
        iteration++;
        // this flag determines whether we reiterate or not.
        localParticle->getSpecies().clearRerunPreviousGridSweepFlag();

        // Setup
        for (hydroPart* particle : particleList) {
          ::swift2::kernels::legacy::hydro_init_particle(particle);
        }

        // Neighbour loop
        for (hydroPart* activeParticle : particleList) {
          ::swift2::kernels::legacy::density_kernel(localParticle, activeParticle);
        }

        // TODO: temporary
        // I'm calling hydro_end_density_copy in hydro_update_smoothing_length_and_rerun_if_required()
        swift2::kernels::legacy::hydro_end_density(localParticle);

        // Finish and do Newton-Raphson iteration.
        swift2::kernels::legacy::hydro_update_smoothing_length_and_rerun_if_required(localParticle);

        // Are we done?
        if (not localParticle->getSpecies().rerunPreviousGridSweep()) break;
      }

      max_iterations = std::max(max_iterations, iteration);

      if (iteration == hydroPart::getSmlMaxIterations()) {
        std::cout << "Error: did not converge after " << iteration << " iterations" << std::endl;
        std::cout << localParticle->getSmoothingLengthIterCount() << std::endl;
      } else {
        if (verbose){
          std::cout << "Particle " << localParticle->getPartid() << " converged after " << iteration << " iterations" << std::endl;
        }

      }

      double h = localParticle->getSmoothingLength();
      double diff = std::abs(h/h_solution - 1.);
      if ( diff > 5e-5) {
        std::cout << std::setprecision(6);
        std::cout << "ERROR: Smoothing lengths don't agree. ";
        std::cout << " Got: h=" << h << "; ";
        std::cout << " Expect: h=" << h_solution << "; ";
        std::cout << " Ratio: h=" << h/h_solution << "; ";
        std::cout << " Error: diff=" << diff << std::endl;
        std::cout << localParticle->toString() << std::endl;
        error++;
      }

      mindiff = std::min(diff, mindiff);
      maxdiff = std::max(diff, maxdiff);

    }

    std::cout << "Finished. Diff min=" << mindiff << "; max=" << maxdiff << "; max nr iterations=" << max_iterations << "\n";
    if (error) {
      std::cout << "Found " << error << " errors for " << ic.name << ". Exiting.";
      std::exit(error);
    }

    // Clean up after yourself.
    cleanParticleList(particleList);

  }
} // namespace smlUnitTest
