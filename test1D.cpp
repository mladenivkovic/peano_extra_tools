#include "HydroPart.h"

#include "smlUnitTest.h"
#include "ICUniform1D.h"
#include "ICDisplaced1D.h"
#include "ICMultilevelDisplaced1D.h"


int main(void){

  bool check_all = true;
  bool verbose = false;

  smlUnitTest::runTest(initialConditions::oneDim::ICUniform(), 1, check_all, verbose);
  smlUnitTest::runTest(initialConditions::oneDim::ICDisplaced(), 1, check_all, verbose);
  smlUnitTest::runTest(initialConditions::oneDim::ICMultilevelDisplaced(), 1, check_all, verbose);

}
