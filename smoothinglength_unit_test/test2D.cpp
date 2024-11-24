#include "HydroPart.h"
#include "smlUnitTest.h"
#include "InitialConditions2D.h"


int main(void){

  bool check_all = false;
  bool verbose = false;
  bool abort_on_error = true;

  smlUnitTest::runTest(initialConditions::ICUniform2D, 2, check_all, verbose, abort_on_error);
  smlUnitTest::runTest(initialConditions::ICDisplaced2D_8neighbours, 2, check_all, verbose, abort_on_error);
  smlUnitTest::runTest(initialConditions::ICDisplaced2D_15neighbours, 2, check_all, verbose, abort_on_error);
  smlUnitTest::runTest(initialConditions::ICDisplaced2D_20neighbours, 2, check_all, verbose, abort_on_error);
  smlUnitTest::runTest(initialConditions::ICMultilevelDisplaced2D_8neighbours, 2, check_all, verbose, abort_on_error);
  smlUnitTest::runTest(initialConditions::ICMultilevelDisplaced2D_15neighbours, 2, check_all, verbose, abort_on_error);
  smlUnitTest::runTest(initialConditions::ICMultilevelDisplaced2D_20neighbours, 2, check_all, verbose, abort_on_error);

}
