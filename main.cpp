#include "hydroPart.h"

#include "smlUnitTest.h"
#include "ICUniform1D.h"
#include "ICDisplaced1D.h"
#include "ICMultilevelDisplaced1D.h"
#include "ICUniform2D.h"


/**
 * Set some global/static parameters.
 */
void setStaticParams(int dimension){

  using hydroPart = tests::swift2::testSML1D::globaldata::hydroPart;

  if (dimension == 1){
    hydroPart::_hydroDimensions = 1;
    hydroPart::_etaFactor = 2.5819884616099626;
  } else if (dimension == 2){
    hydroPart::_hydroDimensions = 2;
    hydroPart::_etaFactor = 1.2761313865909358;
  } else {
    std::cerr << "Invalid number of dimensions: "<< dimension << std::endl;
    std::abort();
  }

  hydroPart::_smlMaxIterations = 50;
  hydroPart::_smlMin = 1e-06;
  hydroPart::_smlMax = 0.05;
  hydroPart::_smlTolerance = 1e-06;
}



int main(void){

  // 1D tests
  setStaticParams(1);

  // smlUnitTest::runTest(initialConditions::oneDim::ICUniform());
  // smlUnitTest::runTest(initialConditions::oneDim::ICDisplaced());
  // smlUnitTest::runTest(initialConditions::oneDim::ICMultilevelDisplaced());


  // 2D tests
  setStaticParams(2);
  smlUnitTest::runTest(initialConditions::twoDim::ICUniform());

}
