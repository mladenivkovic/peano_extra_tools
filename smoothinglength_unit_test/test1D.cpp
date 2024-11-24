#include "HydroPart.h"
#include "smlUnitTest.h"
#include "InitialConditions1D.h"


int main(void){

  bool check_all = true;
  bool verbose = false;
  bool abort_on_error = true;

  smlUnitTest::runTest(initialConditions::ICUniform1D, 1, check_all, verbose, abort_on_error);
  smlUnitTest::runTest(initialConditions::ICDisplaced1D_3neighbours, 1, check_all, verbose, abort_on_error);
  smlUnitTest::runTest(initialConditions::ICDisplaced1D_5neighbours, 1, check_all, verbose, abort_on_error);
  smlUnitTest::runTest(initialConditions::ICDisplaced1D_10neighbours, 1, check_all, verbose, abort_on_error);
  smlUnitTest::runTest(initialConditions::ICMultilevelDisplaced1D_3neighbours, 1, check_all, verbose, abort_on_error);
  smlUnitTest::runTest(initialConditions::ICMultilevelDisplaced1D_5neighbours, 1, check_all, verbose, abort_on_error);
  smlUnitTest::runTest(initialConditions::ICMultilevelDisplaced1D_10neighbours, 1, check_all, verbose, abort_on_error);

}
