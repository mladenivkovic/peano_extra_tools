#include "HydroPart.h"
#include "smlUnitTest.h"
#include "InitialConditions2D.h"


int main(void){

  bool check_all = true;
  bool verbose = true;
  bool abort_on_error = true;

  smlUnitTest::runTest(initialConditions::ICUniform2D, 2, check_all, verbose, abort_on_error);
  smlUnitTest::runTest(initialConditions::ICDisplaced2D, 2, check_all, verbose, abort_on_error);
  smlUnitTest::runTest(initialConditions::ICMultilevelDisplaced2D, 2, check_all, verbose, abort_on_error);

}
