#include "HydroPart.h"
#include "InitialConditions1D.h"
#include "smlUnitTest.h"


int main(void) {

  // Particles around the edge have some issues here in the 1D test.
  // In particular, the N=10 multiscale test.

  bool check_all      = false;
  bool verbose        = false;
  bool abort_on_error = true;

  smlUnitTest::runTest(
    initialConditions::ICUniform1D,
    1,
    check_all,
    verbose,
    abort_on_error
  );
  smlUnitTest::runTest(
    initialConditions::ICDisplaced1D_3neighbours,
    1,
    check_all,
    verbose,
    abort_on_error
  );
  smlUnitTest::runTest(
    initialConditions::ICDisplaced1D_5neighbours,
    1,
    check_all,
    verbose,
    abort_on_error
  );
  smlUnitTest::runTest(
    initialConditions::ICDisplaced1D_10neighbours,
    1,
    check_all,
    verbose,
    abort_on_error
  );
  smlUnitTest::runTest(
    initialConditions::ICMultilevelDisplaced1D_3neighbours,
    1,
    check_all,
    verbose,
    abort_on_error
  );
  smlUnitTest::runTest(
    initialConditions::ICMultilevelDisplaced1D_5neighbours,
    1,
    check_all,
    verbose,
    abort_on_error
  );
  smlUnitTest::runTest(
    initialConditions::ICMultilevelDisplaced1D_10neighbours,
    1,
    check_all,
    verbose,
    abort_on_error
  );
}
