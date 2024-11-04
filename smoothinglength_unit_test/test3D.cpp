#include "HydroPart.h"
#include "smlUnitTest.h"
#include "InitialConditions3D.h"



int main(void){

  bool check_all = false;
  bool verbose = false;
  bool abort_on_error = true;

  smlUnitTest::runTest(initialConditions::ICUniform3D, 3, check_all, verbose, abort_on_error);
  smlUnitTest::runTest(initialConditions::ICDisplaced3D, 3, check_all, verbose, abort_on_error);
  smlUnitTest::runTest(initialConditions::ICMultilevelDisplaced3D, 3, check_all, verbose, abort_on_error);

}
