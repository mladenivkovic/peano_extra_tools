#include "HydroPart.h"

#include "smlUnitTest.h"
#include "InitialConditions3D.h"



int main(void){

  bool check_all = false;
  bool verbose = false;
  bool abort_on_error = true;

  smlUnitTest::runTest(initialConditions::threeDim::ICUniform3D, 3, check_all, verbose, abort_on_error);
  smlUnitTest::runTest(initialConditions::threeDim::ICDisplaced3D, 3, check_all, verbose, abort_on_error);
  smlUnitTest::runTest(initialConditions::threeDim::ICMultilevelDisplaced3D, 3, check_all, verbose, abort_on_error);

}
