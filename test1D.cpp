#include "hydroPart.h"

#include "smlUnitTest.h"
#include "ICUniform1D.h"
#include "ICDisplaced1D.h"
#include "ICMultilevelDisplaced1D.h"
#include "ICUniform2D.h"



int main(void){

  smlUnitTest::setStaticParams(1);

  smlUnitTest::runTest(initialConditions::oneDim::ICUniform());
  smlUnitTest::runTest(initialConditions::oneDim::ICDisplaced());
  smlUnitTest::runTest(initialConditions::oneDim::ICMultilevelDisplaced());

}
