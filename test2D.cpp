#include "hydroPart.h"

#include "smlUnitTest.h"
#include "ICUniform2D.h"
#include "ICDisplaced2D.h"



int main(void){

  bool check_all = true;
  bool verbose = true;

  smlUnitTest::runTest(initialConditions::twoDim::ICUniform(), 2, check_all, verbose);
  // smlUnitTest::runTest(initialConditions::twoDim::ICDisplaced(), 2, check_all, verbose);

}
