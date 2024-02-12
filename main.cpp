#include <iostream>
#include <list>
#include <functional>


#include "myconfig.h"
#include "ICUniform1D.h"
#include "hydroPart.h"
#include "swift2/kernels/legacy/Density.h"

using hydroPart = tests::swift2::testSML1D::globaldata::hydroPart;



/**
 * Generate particles, and return list of pointers to them.
 **/
std::list<hydroPart*> initParticles(void){

  std::list<hydroPart*> particleList;

  using namespace initialConditions::oneDim::uniform;

  for (int p = 0; p < sampleSize; p++){

    hydroPart *part = new hydroPart();

    part->setX(0, coords[p][0]);
#if Dimension > 1
    part->setX(1, coords[p][1]);
#endif
#if Dimension > 2
    part->setX(2, coords[p][2]);
#endif

    part->setSmoothingLength(sml[p]);
    part->setPartid(ids[p]);

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

// // Define add and multiply to
// // return respective values
// int add(int x, int y) { return x + y; }
// int multiply(int x, int y) { return x * y; }
//
// // Function that accepts an object of
// // type std::function<> as a parameter
// // as well
// int invoke(int x, int y, function<int(int, int)> func)
// {
//     return func(x, y);
// }
//


/**
 * Loop over all particles in particleList and invoke func on them
 * */
void forAllParticles(std::list<hydroPart*> particleList, std::function<void(hydroPart* particle)> func){
  for (auto& particle : particleList) {
    func(particle);
  }
}


/**
 * Loop over all particles in particleList and interact them with localParticle
 * */
void neighbourLoop(hydroPart* localParticle, std::list<hydroPart*> particleList, std::function<void(hydroPart* localParticle, std::list<hydroPart *>)> func){
  func(localParticle, particleList);
}





int main(void){



  std::list<hydroPart*> particleList = initParticles();

  int localParticleIndex = 10;
  hydroPart *localParticle = getLocalParticle(particleList, localParticleIndex);
  std::cout << localParticle->toString() << std::endl;


  int iteration = 0;
  while (iteration < hydroPart::getSmlMaxIterations() ){

    forAllParticles(particleList, ::swift2::kernels::legacy::prepareDensity);

    break;
  }


}
