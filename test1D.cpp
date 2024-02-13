#include "hydroPart.h"

#include "smlUnitTest.h"
#include "ICUniform1D.h"
#include "ICDisplaced1D.h"
#include "ICMultilevelDisplaced1D.h"



int main(void){

  smlUnitTest::setStaticParams(1);
  bool check_all = true;
  bool verbose = true;

  smlUnitTest::runTest(initialConditions::oneDim::ICUniform(), check_all, verbose);
  smlUnitTest::runTest(initialConditions::oneDim::ICDisplaced(), check_all, verbose);
  smlUnitTest::runTest(initialConditions::oneDim::ICMultilevelDisplaced(), check_all, verbose);

}
