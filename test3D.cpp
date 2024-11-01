#include "HydroPart.h"

#include "smlUnitTest.h"
#include "ICUniform3D.h"
#include "ICDisplaced3D.h"
#include "ICMultilevelDisplaced3D.h"



int main(void){

  bool check_all = false;
  bool verbose = false;

  smlUnitTest::runTest(initialConditions::threeDim::ICUniform(), 3, check_all, verbose);
  smlUnitTest::runTest(initialConditions::threeDim::ICDisplaced(), 3, check_all, verbose);
  smlUnitTest::runTest(initialConditions::threeDim::ICMultilevelDisplaced(), 3, check_all, verbose);

}
