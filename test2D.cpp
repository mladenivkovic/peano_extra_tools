#include "hydroPart.h"

#include "smlUnitTest.h"
#include "ICUniform2D.h"
#include "ICDisplaced2D.h"



int main(void){

  smlUnitTest::setStaticParams(2);
  bool check_all = true;
  bool verbose = true;

  // smlUnitTest::runTest(initialConditions::twoDim::ICUniform(), check_all, verbose);
  smlUnitTest::runTest(initialConditions::twoDim::ICDisplaced(), check_all, verbose);

}
