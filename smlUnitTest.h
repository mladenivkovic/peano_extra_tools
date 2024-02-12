#pragma once

#include <iostream>
#include <list>
#include <functional>


#include "myconfig.h"
#include "hydroPart.h"




#include "swift2/kernels/legacy/Density.h"
#include "swift2/kernels/legacy/SmoothingLength.h"
#include "tarch/tarch.h"
#include "tarch/la/la.h"


namespace smlUnitTest {

  using hydroPart = tests::swift2::testSML1D::globaldata::hydroPart;


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
  template <typename IC>
  std::list<hydroPart*> initParticles(IC ic){

    std::list<hydroPart*> particleList;

    for (int p = 0; p < ic.sampleSize; p++){

      hydroPart *part = new hydroPart();

      part->setX(0, ic.coords[p][0]);
#if Dimension > 1
      part->setX(1, ic.coords[p][1]);
#endif
#if Dimension > 2
      part->setX(2, ic.coords[p][2]);
#endif

      part->setSmoothingLength(ic.sml_init[p]);
      part->setPartid(ic.ids[p]);

      part->setSearchRadius(1.);
      part->setMass(1.);
      part->setPressure(1.);
      part->setU(1.);

      part->setV(0, 0.);
#if Dimension > 1
      part->setV(1, 0.);
#endif
#if Dimension > 2
      part->setV(2, 0.);
#endif


      particleList.push_back(part);
    }

    return particleList;
  }





  template <typename IC>
  void runTest(IC ic){


    std::cout << "Running '" << ic.name << "'\n";

    std::list<hydroPart*> particleList = initParticles(ic);

    for (int localParticleIndex = 10; localParticleIndex < ic.sampleSize - 10; localParticleIndex++){

      hydroPart *localParticle = getLocalParticle(particleList, localParticleIndex);
      std::cout << localParticle->toString() << std::endl;


      int iteration = 0;
      while (iteration < hydroPart::getSmlMaxIterations() ){
        iteration++;
        localParticle->getSpecies().clearRerunPreviousGridSweepFlag();

        for (hydroPart* particle : particleList) {
          ::swift2::kernels::legacy::hydro_prepare_density(particle);
        }

        for (hydroPart* activeParticle : particleList) {
          ::swift2::kernels::legacy::density_kernel(localParticle, activeParticle);
        }

        // for (hydroPart* particle : particleList) {
        //   swift2::kernels::legacy::hydro_update_smoothing_length_and_rerun_if_required(particle);
        // }
        swift2::kernels::legacy::hydro_update_smoothing_length_and_rerun_if_required(localParticle);


        if (not localParticle->getSpecies().rerunPreviousGridSweep()) break;
      }

      if (iteration == hydroPart::getSmlMaxIterations()) {
        std::cout << "Error: did not converge after " << iteration << " iterations" << std::endl;
        std::cout << localParticle->getSmoothingLengthIterCount() << std::endl;
      } else {
        std::cout << "Finished (converged) after " << iteration << " iterations" << std::endl;
      }



    }
  }
} // namespace smlUnitTest
