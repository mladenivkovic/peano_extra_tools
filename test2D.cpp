#include "hydroPart.h"

#include "smlUnitTest.h"
#include "ICUniform1D.h"
#include "ICDisplaced1D.h"
#include "ICMultilevelDisplaced1D.h"
#include "ICUniform2D.h"



int main(void){

  // 2D tests
  smlUnitTest::setStaticParams(2);
  smlUnitTest::runTest(initialConditions::twoDim::ICUniform());

}
