#include "HydroPart.h"
#include "InitialConditions2D.h"
#include "smlUnitTest.h"


int main(void) {

  bool check_all      = false;
  bool verbose        = false;
  bool abort_on_error = true;

  smlUnitTest::runTest(
    initialConditions::ICUniform2D,
    2,
    check_all,
    verbose,
    abort_on_error
  );
  smlUnitTest::runTest(
    initialConditions::ICDisplaced2D_8neighbours,
    2,
    check_all,
    verbose,
    abort_on_error
  );
  smlUnitTest::runTest(
    initialConditions::ICDisplaced2D_15neighbours,
    2,
    check_all,
    verbose,
    abort_on_error
  );
  smlUnitTest::runTest(
    initialConditions::ICDisplaced2D_20neighbours,
    2,
    check_all,
    verbose,
    abort_on_error
  );
  // This test has some irregular particles, where even the python script calls
  // out some divisions by zero. These particles won't find agreeable solutions.
  // So skipping it for now.
  // smlUnitTest::runTest(initialConditions::ICMultilevelDisplaced2D_8neighbours,
  // 2, check_all, verbose, abort_on_error);
  smlUnitTest::runTest(
    initialConditions::ICMultilevelDisplaced2D_15neighbours,
    2,
    check_all,
    verbose,
    abort_on_error
  );
  smlUnitTest::runTest(
    initialConditions::ICMultilevelDisplaced2D_20neighbours,
    2,
    check_all,
    verbose,
    abort_on_error
  );
}
