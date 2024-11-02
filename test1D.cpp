#include "HydroPart.h"

#include "smlUnitTest.h"
#include "InitialConditions1D.h"


int main(void){

  bool check_all = true;
  bool verbose = false;
  bool abort_on_error = true;

  smlUnitTest::runTest(initialConditions::oneDim::ICUniform1D, 1, check_all, verbose, abort_on_error);
  smlUnitTest::runTest(initialConditions::oneDim::ICDisplaced1D, 1, check_all, verbose, abort_on_error);
  smlUnitTest::runTest(initialConditions::oneDim::ICMultilevelDisplaced1D, 1, check_all, verbose, abort_on_error);

}
