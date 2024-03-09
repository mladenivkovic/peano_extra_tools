#include "hydroPart.h"



#include <sstream>
#include <algorithm>

// Just some default values. Will be modified in actual test.
double tests::swift2::testSML1D::globaldata::hydroPart::_hydroDimensions = 1;
double tests::swift2::testSML1D::globaldata::hydroPart::_etaFactor = 2.5819884616099626;

int tests::swift2::testSML1D::globaldata::hydroPart::_smlMaxIterations = 50;
double tests::swift2::testSML1D::globaldata::hydroPart::_smlMin = 1e-06;
double tests::swift2::testSML1D::globaldata::hydroPart::_smlMax = 0.05;
double tests::swift2::testSML1D::globaldata::hydroPart::_smlTolerance = 1e-06;


tests::swift2::testSML1D::globaldata::hydroPart::hydroPart(tarch::la::Vector<Dimensions,double>  __debugX, tarch::la::Vector<Dimensions,double>  __debugH, tarch::la::Vector<Dimensions,double>  __x, tarch::la::Vector<Dimensions,double>  __cellH, double  __searchRadius, ParallelState  __ParallelState, MoveState  __MoveState, bool  __CellHasUpdatedParticle, double  __mass, tarch::la::Vector<Dimensions,double>  __v, tarch::la::Vector<Dimensions,double>  __a, double  __density, double  __pressure, double  __smoothingLength, double  __u, double  __uDot, tarch::la::Vector<Dimensions,double>  __v_full, double  __u_full, double  __wcount, double  __wcount_dh, double  __f, double  __hDot, double  __rho_dh, int  __smoothingLengthIterCount, bool  __hasNoNeighbours, bool  __isBoundaryParticle, bool  __smoothingLengthConverged, int  __smoothingLengthNeighbourCount, int  __partid, double  __balsara, double  __rot_v, double  __div_v, double  __v_sig_AV, double  __soundSpeed, DependencyChecksPeanoEventUsedBySwift  __dependencyChecksPeanoEventUsedBySwift, DependencyChecksAlgorithmStepLastUpdated  __dependencyChecksAlgorithmStepLastUpdated, int  __dependencyChecksAlgorithmStepUpdates[21], int  __dependencyChecksAlgorithmStepMaskOuts[21], DependencyChecksInitStepLastUpdated  __dependencyChecksInitStepLastUpdated, int  __dependencyChecksInitStepUpdates[0], int  __dependencyChecksInitStepMaskOuts[0]){
#if PeanoDebug>0
setDebugX( __debugX);
#endif
#if PeanoDebug>0
setDebugH( __debugH);
#endif
setX( __x);
setCellH( __cellH);
setSearchRadius( __searchRadius);
setParallelState( __ParallelState);
setMoveState( __MoveState);
setCellHasUpdatedParticle( __CellHasUpdatedParticle);
setMass( __mass);
setV( __v);
setA( __a);
setDensity( __density);
setPressure( __pressure);
setSmoothingLength( __smoothingLength);
setU( __u);
setUDot( __uDot);
setV_full( __v_full);
setU_full( __u_full);
setWcount( __wcount);
setWcount_dh( __wcount_dh);
setF( __f);
setHDot( __hDot);
setRho_dh( __rho_dh);
setSmoothingLengthIterCount( __smoothingLengthIterCount);
setHasNoNeighbours( __hasNoNeighbours);
setIsBoundaryParticle( __isBoundaryParticle);
setSmoothingLengthConverged( __smoothingLengthConverged);
#if PeanoDebug > 0
setSmoothingLengthNeighbourCount( __smoothingLengthNeighbourCount);
#endif
setPartid( __partid);
setBalsara( __balsara);
setRot_v( __rot_v);
setDiv_v( __div_v);
setV_sig_AV( __v_sig_AV);
setSoundSpeed( __soundSpeed);
#if PeanoDebug > 0
setDependencyChecksPeanoEventUsedBySwift( __dependencyChecksPeanoEventUsedBySwift);
#endif
#if PeanoDebug > 0
setDependencyChecksAlgorithmStepLastUpdated( __dependencyChecksAlgorithmStepLastUpdated);
#endif
#if PeanoDebug > 0
setDependencyChecksAlgorithmStepUpdates( __dependencyChecksAlgorithmStepUpdates);
#endif
#if PeanoDebug > 0
setDependencyChecksAlgorithmStepMaskOuts( __dependencyChecksAlgorithmStepMaskOuts);
#endif
#if PeanoDebug > 0
setDependencyChecksInitStepLastUpdated( __dependencyChecksInitStepLastUpdated);
#endif
#if PeanoDebug > 0
setDependencyChecksInitStepUpdates( __dependencyChecksInitStepUpdates);
#endif
#if PeanoDebug > 0
setDependencyChecksInitStepMaskOuts( __dependencyChecksInitStepMaskOuts);
#endif
}



tests::swift2::testSML1D::globaldata::hydroPart::hydroPart( const hydroPart& copy ) {
#if PeanoDebug>0
  setDebugX( copy.getDebugX() );
#endif
#if PeanoDebug>0
  setDebugH( copy.getDebugH() );
#endif
  setX( copy.getX() );
  setCellH( copy.getCellH() );
  setSearchRadius( copy.getSearchRadius() );
  setParallelState( copy.getParallelState() );
  setMoveState( copy.getMoveState() );
  setCellHasUpdatedParticle( copy.getCellHasUpdatedParticle() );
  setMass( copy.getMass() );
  setV( copy.getV() );
  setA( copy.getA() );
  setDensity( copy.getDensity() );
  setPressure( copy.getPressure() );
  setSmoothingLength( copy.getSmoothingLength() );
  setU( copy.getU() );
  setUDot( copy.getUDot() );
  setV_full( copy.getV_full() );
  setU_full( copy.getU_full() );
  setWcount( copy.getWcount() );
  setWcount_dh( copy.getWcount_dh() );
  setF( copy.getF() );
  setHDot( copy.getHDot() );
  setRho_dh( copy.getRho_dh() );
  setSmoothingLengthIterCount( copy.getSmoothingLengthIterCount() );
  setHasNoNeighbours( copy.getHasNoNeighbours() );
  setIsBoundaryParticle( copy.getIsBoundaryParticle() );
  setSmoothingLengthConverged( copy.getSmoothingLengthConverged() );
#if PeanoDebug > 0
  setSmoothingLengthNeighbourCount( copy.getSmoothingLengthNeighbourCount() );
#endif
  setPartid( copy.getPartid() );
  setBalsara( copy.getBalsara() );
  setRot_v( copy.getRot_v() );
  setDiv_v( copy.getDiv_v() );
  setV_sig_AV( copy.getV_sig_AV() );
  setSoundSpeed( copy.getSoundSpeed() );
#if PeanoDebug > 0
  setDependencyChecksPeanoEventUsedBySwift( copy.getDependencyChecksPeanoEventUsedBySwift() );
#endif
#if PeanoDebug > 0
  setDependencyChecksAlgorithmStepLastUpdated( copy.getDependencyChecksAlgorithmStepLastUpdated() );
#endif
#if PeanoDebug > 0
  setDependencyChecksAlgorithmStepUpdates( copy.getDependencyChecksAlgorithmStepUpdates() );
#endif
#if PeanoDebug > 0
  setDependencyChecksAlgorithmStepMaskOuts( copy.getDependencyChecksAlgorithmStepMaskOuts() );
#endif
#if PeanoDebug > 0
  setDependencyChecksInitStepLastUpdated( copy.getDependencyChecksInitStepLastUpdated() );
#endif
#if PeanoDebug > 0
  setDependencyChecksInitStepUpdates( copy.getDependencyChecksInitStepUpdates() );
#endif
#if PeanoDebug > 0
  setDependencyChecksInitStepMaskOuts( copy.getDependencyChecksInitStepMaskOuts() );
#endif
}





std::string tests::swift2::testSML1D::globaldata::hydroPart::toString() const {
  std::ostringstream out;
  out << "(";
// #if PeanoDebug>0
//   out << "debugX=" << _debugX;
// #endif
// #if PeanoDebug>0
//   out << ",";
//   out << "debugH=" << _debugH;
// #endif
  // out << ",";
  out << "x=" << _x;
  out << ",";
  // out << "cellH=" << _cellH;
  // out << ",";
  out << "searchRadius=" << _searchRadius;
  out << ",";
  // out << "ParallelState=" << toString(_ParallelState);
  // out << ",";
  // out << "MoveState=" << toString(_MoveState);
  // out << ",";
  // out << "CellHasUpdatedParticle=" << _CellHasUpdatedParticle;
  // out << ",";
  // out << "mass=" << _mass;
  // out << ",";
  // out << "v=" << _v;
  // out << ",";
  // out << "a=" << _a;
  // out << ",";
  out << "density=" << _density;
  out << ",";
  // out << "pressure=" << _pressure;
  // out << ",";
  out << "smoothingLength=" << _smoothingLength;
  out << ",";
/*   out << "u=" << _u; */
  /* out << ",";  */
  /* out << "uDot=" << _uDot; */
  /* out << ",";  */
  /* out << "v_full=" << _v_full; */
  /* out << ",";  */
  /* out << "u_full=" << _u_full; */
  // out << ",";
  out << "wcount=" << _wcount;
  out << ",";
  out << "wcount_dh=" << _wcount_dh;
  out << ",";
  out << "f=" << _f;
  out << ",";
  out << "hDot=" << _hDot;
  out << ",";
  out << "rho_dh=" << _rho_dh;
  out << ",";
  out << "smoothingLengthIterCount=" << _smoothingLengthIterCount;
  out << ",";
  out << "hasNoNeighbours=" << _hasNoNeighbours;
  out << ",";
  // out << "isBoundaryParticle=" << _isBoundaryParticle;
  // out << ",";
  out << "smoothingLengthConverged=" << _smoothingLengthConverged;
#if PeanoDebug > 0
  out << ",";
  out << "smoothingLengthNeighbourCount=" << _smoothingLengthNeighbourCount;
#endif
  out << ",";
  out << "partid=" << _partid;
  out << ",";
/*   out << "cfl=" << _cfl; */
  /* out << ",";  */
  /* out << "initialTimeStepSize=" << _initialTimeStepSize; */
  /* out << ",";  */
  /* out << "adjustTimeStepSize=" << _adjustTimeStepSize; */
  // out << ",";
  out << "hydroDimensions=" << _hydroDimensions;
  out << ",";
  out << "etaFactor=" << _etaFactor;
  out << ",";
  out << "smlMin=" << _smlMin;
  out << ",";
  out << "smlMax=" << _smlMax;
  out << ",";
  out << "smlTolerance=" << _smlTolerance;
  out << ",";
  out << "smlMaxIterations=" << _smlMaxIterations;
  out << ",";
/*   out << "alphaAV=" << _alphaAV; */
/*   out << ",";  */
/*   out << "betaAV=" << _betaAV; */
/*   out << ",";  */
/*   out << "balsara=" << _balsara; */
/*   out << ",";  */
/*   out << "rot_v=" << _rot_v; */
/*   out << ",";  */
/*   out << "div_v=" << _div_v; */
/*   out << ",";  */
/*   out << "v_sig_AV=" << _v_sig_AV; */
/*   out << ",";  */
/*   out << "soundSpeed=" << _soundSpeed; */
/* #if PeanoDebug > 0 */
/*   out << ",";  */
/*   out << "dependencyChecksPeanoEventUsedBySwift=" << toString(_dependencyChecksPeanoEventUsedBySwift); */
/* #endif  */
/* #if PeanoDebug > 0 */
/*   out << ",";  */
/*   out << "dependencyChecksAlgorithmStepLastUpdated=" << toString(_dependencyChecksAlgorithmStepLastUpdated); */
/* #endif  */
/* #if PeanoDebug > 0 */
/*   out << ",";  */
/*   out << "dependencyChecksAlgorithmStepUpdates=" << _dependencyChecksAlgorithmStepUpdates[0] << ",..."; */
/* #endif  */
/* #if PeanoDebug > 0 */
/*   out << ",";  */
/*   out << "dependencyChecksAlgorithmStepMaskOuts=" << _dependencyChecksAlgorithmStepMaskOuts[0] << ",..."; */
/* #endif  */
/* #if PeanoDebug > 0 */
/*   out << ",";  */
/*   out << "dependencyChecksInitStepLastUpdated=" << toString(_dependencyChecksInitStepLastUpdated); */
/* #endif  */
/* #if PeanoDebug > 0 */
/*   out << ",";  */
/*   out << "dependencyChecksInitStepUpdates=" << _dependencyChecksInitStepUpdates[0] << ",..."; */
/* #endif  */
/* #if PeanoDebug > 0 */
/*   out << ",";  */
/*   out << "dependencyChecksInitStepMaskOuts=" << _dependencyChecksInitStepMaskOuts[0] << ",..."; */
// #endif
  out << ")";
  return out.str();
}





#if PeanoDebug>0
tarch::la::Vector<Dimensions,double>   tests::swift2::testSML1D::globaldata::hydroPart::getDebugX() const {
  return   _debugX;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setDebugX(const tarch::la::Vector<Dimensions,double>& value) {
  _debugX = value;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getDebugX(int index) const {
  return   _debugX(index);
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setDebugX(int index, double value) {
  _debugX(index) = value;
}


#endif


#if PeanoDebug>0
tarch::la::Vector<Dimensions,double>   tests::swift2::testSML1D::globaldata::hydroPart::getDebugH() const {
  return   _debugH;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setDebugH(const tarch::la::Vector<Dimensions,double>& value) {
  _debugH = value;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getDebugH(int index) const {
  return   _debugH(index);
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setDebugH(int index, double value) {
  _debugH(index) = value;
}


#endif


tarch::la::Vector<Dimensions,double>   tests::swift2::testSML1D::globaldata::hydroPart::getX() const {
  return   _x;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setX(const tarch::la::Vector<Dimensions,double>& value) {
  _x = value;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getX(int index) const {
  return   _x(index);
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setX(int index, double value) {
  _x(index) = value;
}


tarch::la::Vector<Dimensions,double>   tests::swift2::testSML1D::globaldata::hydroPart::getCellH() const {
  return   _cellH;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setCellH(const tarch::la::Vector<Dimensions,double>& value) {
  _cellH = value;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getCellH(int index) const {
  return   _cellH(index);
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setCellH(int index, double value) {
  _cellH(index) = value;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getSearchRadius() const {
  return _searchRadius;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setSearchRadius(double value) {
  _searchRadius = value;
}


tests::swift2::testSML1D::globaldata::hydroPart::ParallelState   tests::swift2::testSML1D::globaldata::hydroPart::getParallelState() const {
  return _ParallelState;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setParallelState(ParallelState value) {
  _ParallelState = value;
}


const std::string   tests::swift2::testSML1D::globaldata::hydroPart::toString(ParallelState value) {
  std::ostringstream out;
  out  << (value ==ParallelState::Local? "Local" : "")  << (value ==ParallelState::Virtual? "Virtual" : "") ;
  return out.str();
}


tests::swift2::testSML1D::globaldata::hydroPart::MoveState   tests::swift2::testSML1D::globaldata::hydroPart::getMoveState() const {
  return _MoveState;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setMoveState(MoveState value) {
  _MoveState = value;
}


const std::string   tests::swift2::testSML1D::globaldata::hydroPart::toString(MoveState value) {
  std::ostringstream out;
  out  << (value ==MoveState::New? "New" : "")  << (value ==MoveState::NotMovedYet? "NotMovedYet" : "")  << (value ==MoveState::Moved? "Moved" : "") ;
  return out.str();
}


bool   tests::swift2::testSML1D::globaldata::hydroPart::getCellHasUpdatedParticle() const {
  return _CellHasUpdatedParticle;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setCellHasUpdatedParticle(bool value) {
  _CellHasUpdatedParticle = value;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getMass() const {
  return _mass;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setMass(double value) {
  _mass = value;
}


tarch::la::Vector<Dimensions,double>   tests::swift2::testSML1D::globaldata::hydroPart::getV() const {
  return   _v;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setV(const tarch::la::Vector<Dimensions,double>& value) {
  _v = value;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getV(int index) const {
  return   _v(index);
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setV(int index, double value) {
  _v(index) = value;
}


tarch::la::Vector<Dimensions,double>   tests::swift2::testSML1D::globaldata::hydroPart::getA() const {
  return   _a;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setA(const tarch::la::Vector<Dimensions,double>& value) {
  _a = value;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getA(int index) const {
  return   _a(index);
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setA(int index, double value) {
  _a(index) = value;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getDensity() const {
  return _density;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setDensity(double value) {
  _density = value;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getPressure() const {
  return _pressure;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setPressure(double value) {
  _pressure = value;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getSmoothingLength() const {
  return _smoothingLength;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setSmoothingLength(double value) {
  _smoothingLength = value;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getU() const {
  return _u;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setU(double value) {
  _u = value;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getUDot() const {
  return _uDot;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setUDot(double value) {
  _uDot = value;
}


tarch::la::Vector<Dimensions,double>   tests::swift2::testSML1D::globaldata::hydroPart::getV_full() const {
  return   _v_full;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setV_full(const tarch::la::Vector<Dimensions,double>& value) {
  _v_full = value;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getV_full(int index) const {
  return   _v_full(index);
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setV_full(int index, double value) {
  _v_full(index) = value;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getU_full() const {
  return _u_full;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setU_full(double value) {
  _u_full = value;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getWcount() const {
  return _wcount;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setWcount(double value) {
  _wcount = value;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getWcount_dh() const {
  return _wcount_dh;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setWcount_dh(double value) {
  _wcount_dh = value;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getF() const {
  return _f;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setF(double value) {
  _f = value;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getHDot() const {
  return _hDot;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setHDot(double value) {
  _hDot = value;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getRho_dh() const {
  return _rho_dh;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setRho_dh(double value) {
  _rho_dh = value;
}


int   tests::swift2::testSML1D::globaldata::hydroPart::getSmoothingLengthIterCount() const {
  return _smoothingLengthIterCount;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setSmoothingLengthIterCount(int value) {
  _smoothingLengthIterCount = value;
}


bool   tests::swift2::testSML1D::globaldata::hydroPart::getHasNoNeighbours() const {
  return _hasNoNeighbours;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setHasNoNeighbours(bool value) {
  _hasNoNeighbours = value;
}


bool   tests::swift2::testSML1D::globaldata::hydroPart::getIsBoundaryParticle() const {
  return _isBoundaryParticle;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setIsBoundaryParticle(bool value) {
  _isBoundaryParticle = value;
}


bool   tests::swift2::testSML1D::globaldata::hydroPart::getSmoothingLengthConverged() const {
  return _smoothingLengthConverged;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setSmoothingLengthConverged(bool value) {
  _smoothingLengthConverged = value;
}


#if PeanoDebug > 0
int   tests::swift2::testSML1D::globaldata::hydroPart::getSmoothingLengthNeighbourCount() const {
  return _smoothingLengthNeighbourCount;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setSmoothingLengthNeighbourCount(int value) {
  _smoothingLengthNeighbourCount = value;
}


#endif


int   tests::swift2::testSML1D::globaldata::hydroPart::getPartid() const {
  return _partid;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setPartid(int value) {
  _partid = value;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getCfl() {
  return _cfl;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getInitialTimeStepSize() {
  return _initialTimeStepSize;
}


bool   tests::swift2::testSML1D::globaldata::hydroPart::getAdjustTimeStepSize() {
  return _adjustTimeStepSize;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getHydroDimensions() {
  return _hydroDimensions;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getEtaFactor() {
  return _etaFactor;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getSmlMin() {
  return _smlMin;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getSmlMax() {
  return _smlMax;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getSmlTolerance() {
  return _smlTolerance;
}


int   tests::swift2::testSML1D::globaldata::hydroPart::getSmlMaxIterations() {
  return _smlMaxIterations;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getAlphaAV() {
  return _alphaAV;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getBetaAV() {
  return _betaAV;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getBalsara() const {
  return _balsara;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setBalsara(double value) {
  _balsara = value;
}


#if Dimensions < 3
double   tests::swift2::testSML1D::globaldata::hydroPart::getRot_v() const {
  return _rot_v;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setRot_v(double value) {
  _rot_v = value;
}
#else

tarch::la::Vector<Dimensions,double>   tests::swift2::testSML1D::globaldata::hydroPart::getRot_v() const {
  return   _rot_v;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setRot_v(const tarch::la::Vector<Dimensions,double>& value) {
  _rot_v = value;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getRot_v(int index) const {
  return   _rot_v(index);
}

#endif




double   tests::swift2::testSML1D::globaldata::hydroPart::getDiv_v() const {
  return _div_v;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setDiv_v(double value) {
  _div_v = value;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getV_sig_AV() const {
  return _v_sig_AV;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setV_sig_AV(double value) {
  _v_sig_AV = value;
}


double   tests::swift2::testSML1D::globaldata::hydroPart::getSoundSpeed() const {
  return _soundSpeed;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setSoundSpeed(double value) {
  _soundSpeed = value;
}


#if PeanoDebug > 0
tests::swift2::testSML1D::globaldata::hydroPart::DependencyChecksPeanoEventUsedBySwift   tests::swift2::testSML1D::globaldata::hydroPart::getDependencyChecksPeanoEventUsedBySwift() const {
  return _dependencyChecksPeanoEventUsedBySwift;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setDependencyChecksPeanoEventUsedBySwift(DependencyChecksPeanoEventUsedBySwift value) {
  _dependencyChecksPeanoEventUsedBySwift = value;
}


const std::string   tests::swift2::testSML1D::globaldata::hydroPart::toString(DependencyChecksPeanoEventUsedBySwift value) {
  std::ostringstream out;
  out  << (value ==DependencyChecksPeanoEventUsedBySwift::touchVertexFirstTime? "touchVertexFirstTime" : "")  << (value ==DependencyChecksPeanoEventUsedBySwift::cellKernel? "cellKernel" : "")  << (value ==DependencyChecksPeanoEventUsedBySwift::touchVertexLastTime? "touchVertexLastTime" : "")  << (value ==DependencyChecksPeanoEventUsedBySwift::count? "count" : "") ;
  return out.str();
}


#endif


#if PeanoDebug > 0
tests::swift2::testSML1D::globaldata::hydroPart::DependencyChecksAlgorithmStepLastUpdated   tests::swift2::testSML1D::globaldata::hydroPart::getDependencyChecksAlgorithmStepLastUpdated() const {
  return _dependencyChecksAlgorithmStepLastUpdated;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setDependencyChecksAlgorithmStepLastUpdated(DependencyChecksAlgorithmStepLastUpdated value) {
  _dependencyChecksAlgorithmStepLastUpdated = value;
}


const std::string   tests::swift2::testSML1D::globaldata::hydroPart::toString(DependencyChecksAlgorithmStepLastUpdated value) {
  std::ostringstream out;
  out  << (value ==DependencyChecksAlgorithmStepLastUpdated::Drift? "Drift" : "")  << (value ==DependencyChecksAlgorithmStepLastUpdated::PredictHydro? "PredictHydro" : "")  << (value ==DependencyChecksAlgorithmStepLastUpdated::DensityLoopWithConstantSearchRadius? "DensityLoopWithConstantSearchRadius" : "")  << (value ==DependencyChecksAlgorithmStepLastUpdated::ForceLoop? "ForceLoop" : "")  << (value ==DependencyChecksAlgorithmStepLastUpdated::Kick2? "Kick2" : "")  << (value ==DependencyChecksAlgorithmStepLastUpdated::ReduceGlobalQuantities? "ReduceGlobalQuantities" : "")  << (value ==DependencyChecksAlgorithmStepLastUpdated::Kick1? "Kick1" : "")  << (value ==DependencyChecksAlgorithmStepLastUpdated::count? "count" : "") ;
  return out.str();
}


#endif


#if PeanoDebug > 0
const int*   tests::swift2::testSML1D::globaldata::hydroPart::getDependencyChecksAlgorithmStepUpdates() const {
  return    _dependencyChecksAlgorithmStepUpdates;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setDependencyChecksAlgorithmStepUpdates(const int value[21]) {
  std::copy_n(value, 21,   _dependencyChecksAlgorithmStepUpdates );
}


int   tests::swift2::testSML1D::globaldata::hydroPart::getDependencyChecksAlgorithmStepUpdates(int index) const {
  return    _dependencyChecksAlgorithmStepUpdates[index];
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setDependencyChecksAlgorithmStepUpdates(int index, int value) {
  _dependencyChecksAlgorithmStepUpdates[index] = value;
}


#endif


#if PeanoDebug > 0
const int*   tests::swift2::testSML1D::globaldata::hydroPart::getDependencyChecksAlgorithmStepMaskOuts() const {
  return    _dependencyChecksAlgorithmStepMaskOuts;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setDependencyChecksAlgorithmStepMaskOuts(const int value[21]) {
  std::copy_n(value, 21,   _dependencyChecksAlgorithmStepMaskOuts );
}


int   tests::swift2::testSML1D::globaldata::hydroPart::getDependencyChecksAlgorithmStepMaskOuts(int index) const {
  return    _dependencyChecksAlgorithmStepMaskOuts[index];
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setDependencyChecksAlgorithmStepMaskOuts(int index, int value) {
  _dependencyChecksAlgorithmStepMaskOuts[index] = value;
}


#endif


#if PeanoDebug > 0
tests::swift2::testSML1D::globaldata::hydroPart::DependencyChecksInitStepLastUpdated   tests::swift2::testSML1D::globaldata::hydroPart::getDependencyChecksInitStepLastUpdated() const {
  return _dependencyChecksInitStepLastUpdated;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setDependencyChecksInitStepLastUpdated(DependencyChecksInitStepLastUpdated value) {
  _dependencyChecksInitStepLastUpdated = value;
}


const std::string   tests::swift2::testSML1D::globaldata::hydroPart::toString(DependencyChecksInitStepLastUpdated value) {
  std::ostringstream out;
  out  << (value ==DependencyChecksInitStepLastUpdated::count? "count" : "") ;
  return out.str();
}


#endif


#if PeanoDebug > 0
const int*   tests::swift2::testSML1D::globaldata::hydroPart::getDependencyChecksInitStepUpdates() const {
  return    _dependencyChecksInitStepUpdates;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setDependencyChecksInitStepUpdates(const int value[0]) {
  std::copy_n(value, 0,   _dependencyChecksInitStepUpdates );
}


int   tests::swift2::testSML1D::globaldata::hydroPart::getDependencyChecksInitStepUpdates(int index) const {
  return    _dependencyChecksInitStepUpdates[index];
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setDependencyChecksInitStepUpdates(int index, int value) {
  _dependencyChecksInitStepUpdates[index] = value;
}


#endif


#if PeanoDebug > 0
const int*   tests::swift2::testSML1D::globaldata::hydroPart::getDependencyChecksInitStepMaskOuts() const {
  return    _dependencyChecksInitStepMaskOuts;
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setDependencyChecksInitStepMaskOuts(const int value[0]) {
  std::copy_n(value, 0,   _dependencyChecksInitStepMaskOuts );
}


int   tests::swift2::testSML1D::globaldata::hydroPart::getDependencyChecksInitStepMaskOuts(int index) const {
  return    _dependencyChecksInitStepMaskOuts[index];
}


void   tests::swift2::testSML1D::globaldata::hydroPart::setDependencyChecksInitStepMaskOuts(int index, int value) {
  _dependencyChecksInitStepMaskOuts[index] = value;
}


#endif






#ifdef Parallel

#if !defined(__MPI_ATTRIBUTES_LANGUAGE_EXTENSION__)
MPI_Datatype tests::swift2::testSML1D::globaldata::hydroPart::Datatype = MPI_DATATYPE_NULL;
#endif


[[clang::map_mpi_datatype]]
MPI_Datatype tests::swift2::testSML1D::globaldata::hydroPart::getForkDatatype() {
  return Datatype;
}


[[clang::map_mpi_datatype]]
MPI_Datatype tests::swift2::testSML1D::globaldata::hydroPart::getGlobalCommunciationDatatype() {
  return Datatype;
}


[[clang::map_mpi_datatype]]
MPI_Datatype tests::swift2::testSML1D::globaldata::hydroPart::getJoinDatatype() {
  return Datatype;
}


[[clang::map_mpi_datatype]]
MPI_Datatype tests::swift2::testSML1D::globaldata::hydroPart::getBoundaryExchangeDatatype() {
  return Datatype;
}


[[clang::map_mpi_datatype]]
MPI_Datatype tests::swift2::testSML1D::globaldata::hydroPart::getMultiscaleDataExchangeDatatype() {
  return Datatype;
}


[[clang::map_mpi_datatype]]
void tests::swift2::testSML1D::globaldata::hydroPart::freeForkDatatype() {
  if (Datatype != MPI_DATATYPE_NULL){
    MPI_Type_free(&Datatype);
    Datatype = MPI_DATATYPE_NULL;
  }
}


[[clang::map_mpi_datatype]]
void tests::swift2::testSML1D::globaldata::hydroPart::freeGlobalCommunciationDatatype() {
  if (Datatype != MPI_DATATYPE_NULL){
    MPI_Type_free(&Datatype);
    Datatype = MPI_DATATYPE_NULL;
  }
}


[[clang::map_mpi_datatype]]
void tests::swift2::testSML1D::globaldata::hydroPart::freeJoinDatatype() {
  if (Datatype != MPI_DATATYPE_NULL){
    MPI_Type_free(&Datatype);
    Datatype = MPI_DATATYPE_NULL;
  }
}


[[clang::map_mpi_datatype]]
void tests::swift2::testSML1D::globaldata::hydroPart::freeBoundaryExchangeDatatype() {
  if (Datatype != MPI_DATATYPE_NULL){
    MPI_Type_free(&Datatype);
    Datatype = MPI_DATATYPE_NULL;
  }
}


[[clang::map_mpi_datatype]]
void tests::swift2::testSML1D::globaldata::hydroPart::freeMultiscaleDataExchangeDatatype() {
  if (Datatype != MPI_DATATYPE_NULL){
    MPI_Type_free(&Datatype);
    Datatype = MPI_DATATYPE_NULL;
  }
}


int tests::swift2::testSML1D::globaldata::hydroPart::getSenderRank() const {
  return _senderDestinationRank;
}



void tests::swift2::testSML1D::globaldata::hydroPart::initDatatype() {
  #if !defined(__MPI_ATTRIBUTES_LANGUAGE_EXTENSION__)
  tests::swift2::testSML1D::globaldata::hydroPart  instances[2];

  int NumberOfAttributes = 0;
#if PeanoDebug>0
  NumberOfAttributes++;
#endif
#if PeanoDebug>0
  NumberOfAttributes++;
#endif
  NumberOfAttributes++;
  NumberOfAttributes++;
  NumberOfAttributes++;
  NumberOfAttributes++;
  NumberOfAttributes++;
  NumberOfAttributes++;
  NumberOfAttributes++;
  NumberOfAttributes++;
  NumberOfAttributes++;
  NumberOfAttributes++;
  NumberOfAttributes++;
  NumberOfAttributes++;
  NumberOfAttributes++;
  NumberOfAttributes++;
  NumberOfAttributes++;
  NumberOfAttributes++;
  NumberOfAttributes++;
  NumberOfAttributes++;
  NumberOfAttributes++;
  NumberOfAttributes++;
  NumberOfAttributes++;
  NumberOfAttributes++;
  NumberOfAttributes++;
  NumberOfAttributes++;
  NumberOfAttributes++;
#if PeanoDebug > 0
  NumberOfAttributes++;
#endif
  NumberOfAttributes++;
  NumberOfAttributes++;
  NumberOfAttributes++;
  NumberOfAttributes++;
  NumberOfAttributes++;
  NumberOfAttributes++;
#if PeanoDebug > 0
  NumberOfAttributes++;
#endif
#if PeanoDebug > 0
  NumberOfAttributes++;
#endif
#if PeanoDebug > 0
  NumberOfAttributes++;
#endif
#if PeanoDebug > 0
  NumberOfAttributes++;
#endif
#if PeanoDebug > 0
  NumberOfAttributes++;
#endif
#if PeanoDebug > 0
  NumberOfAttributes++;
#endif
#if PeanoDebug > 0
  NumberOfAttributes++;
#endif

  MPI_Datatype* subtypes = new MPI_Datatype[NumberOfAttributes];
  int*          blocklen = new int[NumberOfAttributes];
  MPI_Aint*     disp     = new MPI_Aint[NumberOfAttributes];

  int counter            = 0;
#if PeanoDebug>0
  subtypes[counter] = MPI_DOUBLE;
  blocklen[counter] = Dimensions;
  counter++;
#endif
#if PeanoDebug>0
  subtypes[counter] = MPI_DOUBLE;
  blocklen[counter] = Dimensions;
  counter++;
#endif
  subtypes[counter] = MPI_DOUBLE;
  blocklen[counter] = Dimensions;
  counter++;
  subtypes[counter] = MPI_DOUBLE;
  blocklen[counter] = Dimensions;
  counter++;
  subtypes[counter] = MPI_DOUBLE;
  blocklen[counter] = 1;
  counter++;
  subtypes[counter] = MPI_INT;
  blocklen[counter] = 1;
  counter++;
  subtypes[counter] = MPI_INT;
  blocklen[counter] = 1;
  counter++;
  subtypes[counter] = MPI_BYTE;
  blocklen[counter] = 1;
  counter++;
  subtypes[counter] = MPI_DOUBLE;
  blocklen[counter] = 1;
  counter++;
  subtypes[counter] = MPI_DOUBLE;
  blocklen[counter] = Dimensions;
  counter++;
  subtypes[counter] = MPI_DOUBLE;
  blocklen[counter] = Dimensions;
  counter++;
  subtypes[counter] = MPI_DOUBLE;
  blocklen[counter] = 1;
  counter++;
  subtypes[counter] = MPI_DOUBLE;
  blocklen[counter] = 1;
  counter++;
  subtypes[counter] = MPI_DOUBLE;
  blocklen[counter] = 1;
  counter++;
  subtypes[counter] = MPI_DOUBLE;
  blocklen[counter] = 1;
  counter++;
  subtypes[counter] = MPI_DOUBLE;
  blocklen[counter] = 1;
  counter++;
  subtypes[counter] = MPI_DOUBLE;
  blocklen[counter] = Dimensions;
  counter++;
  subtypes[counter] = MPI_DOUBLE;
  blocklen[counter] = 1;
  counter++;
  subtypes[counter] = MPI_DOUBLE;
  blocklen[counter] = 1;
  counter++;
  subtypes[counter] = MPI_DOUBLE;
  blocklen[counter] = 1;
  counter++;
  subtypes[counter] = MPI_DOUBLE;
  blocklen[counter] = 1;
  counter++;
  subtypes[counter] = MPI_DOUBLE;
  blocklen[counter] = 1;
  counter++;
  subtypes[counter] = MPI_DOUBLE;
  blocklen[counter] = 1;
  counter++;
  subtypes[counter] = MPI_INT;
  blocklen[counter] = 1;
  counter++;
  subtypes[counter] = MPI_BYTE;
  blocklen[counter] = 1;
  counter++;
  subtypes[counter] = MPI_BYTE;
  blocklen[counter] = 1;
  counter++;
  subtypes[counter] = MPI_BYTE;
  blocklen[counter] = 1;
  counter++;
#if PeanoDebug > 0
  subtypes[counter] = MPI_INT;
  blocklen[counter] = 1;
  counter++;
#endif
  subtypes[counter] = MPI_INT;
  blocklen[counter] = 1;
  counter++;
  subtypes[counter] = MPI_DOUBLE;
  blocklen[counter] = 1;
  counter++;
  subtypes[counter] = MPI_DOUBLE;
  blocklen[counter] = 1;
  counter++;
  subtypes[counter] = MPI_DOUBLE;
  blocklen[counter] = 1;
  counter++;
  subtypes[counter] = MPI_DOUBLE;
  blocklen[counter] = 1;
  counter++;
  subtypes[counter] = MPI_DOUBLE;
  blocklen[counter] = 1;
  counter++;
#if PeanoDebug > 0
  subtypes[counter] = MPI_INT;
  blocklen[counter] = 1;
  counter++;
#endif
#if PeanoDebug > 0
  subtypes[counter] = MPI_INT;
  blocklen[counter] = 1;
  counter++;
#endif
#if PeanoDebug > 0
  subtypes[counter] = MPI_INT;
  blocklen[counter] = 21;
  counter++;
#endif
#if PeanoDebug > 0
  subtypes[counter] = MPI_INT;
  blocklen[counter] = 21;
  counter++;
#endif
#if PeanoDebug > 0
  subtypes[counter] = MPI_INT;
  blocklen[counter] = 1;
  counter++;
#endif
#if PeanoDebug > 0
  subtypes[counter] = MPI_INT;
  blocklen[counter] = 0;
  counter++;
#endif
#if PeanoDebug > 0
  subtypes[counter] = MPI_INT;
  blocklen[counter] = 0;
  counter++;
#endif

  MPI_Aint  baseFirstInstance;
  MPI_Aint  baseSecondInstance;
  MPI_Get_address( &instances[0], &baseFirstInstance );
  MPI_Get_address( &instances[1], &baseSecondInstance );

  counter = 0;

#if PeanoDebug>0
  MPI_Get_address( &(instances[0]._debugX.data()[0]), &disp[counter] );
  counter++;
#endif

#if PeanoDebug>0
  MPI_Get_address( &(instances[0]._debugH.data()[0]), &disp[counter] );
  counter++;
#endif
  MPI_Get_address( &(instances[0]._x.data()[0]), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._cellH.data()[0]), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._searchRadius), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._ParallelState), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._MoveState), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._CellHasUpdatedParticle), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._mass), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._v.data()[0]), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._a.data()[0]), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._density), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._pressure), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._smoothingLength), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._u), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._uDot), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._v_full.data()[0]), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._u_full), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._wcount), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._wcount_dh), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._f), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._hDot), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._rho_dh), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._smoothingLengthIterCount), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._hasNoNeighbours), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._isBoundaryParticle), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._smoothingLengthConverged = false), &disp[counter] );
  counter++;

#if PeanoDebug > 0
  MPI_Get_address( &(instances[0]._smoothingLengthNeighbourCount), &disp[counter] );
  counter++;
#endif
  MPI_Get_address( &(instances[0]._partid), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._balsara), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._rot_v), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._div_v), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._v_sig_AV), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._soundSpeed), &disp[counter] );
  counter++;

#if PeanoDebug > 0
  MPI_Get_address( &(instances[0]._dependencyChecksPeanoEventUsedBySwift), &disp[counter] );
  counter++;
#endif

#if PeanoDebug > 0
  MPI_Get_address( &(instances[0]._dependencyChecksAlgorithmStepLastUpdated), &disp[counter] );
  counter++;
#endif

#if PeanoDebug > 0
  MPI_Get_address( &(instances[0]._dependencyChecksAlgorithmStepUpdates[0]), &disp[counter] );
  counter++;
#endif

#if PeanoDebug > 0
  MPI_Get_address( &(instances[0]._dependencyChecksAlgorithmStepMaskOuts[0]), &disp[counter] );
  counter++;
#endif

#if PeanoDebug > 0
  MPI_Get_address( &(instances[0]._dependencyChecksInitStepLastUpdated), &disp[counter] );
  counter++;
#endif

#if PeanoDebug > 0
  MPI_Get_address( &(instances[0]._dependencyChecksInitStepUpdates[0]), &disp[counter] );
  counter++;
#endif

#if PeanoDebug > 0
  MPI_Get_address( &(instances[0]._dependencyChecksInitStepMaskOuts[0]), &disp[counter] );
  counter++;
#endif

  MPI_Aint offset = disp[0] - baseFirstInstance;
  MPI_Aint extent = baseSecondInstance - baseFirstInstance - offset;
  for (int i=NumberOfAttributes-1; i>=0; i--) {
    disp[i] = disp[i] - disp[0];
  }

  int errorCode = 0;
  MPI_Datatype tmpType;
  errorCode += MPI_Type_create_struct( NumberOfAttributes, blocklen, disp, subtypes, &tmpType );
  errorCode += MPI_Type_create_resized( tmpType, offset, extent, &Datatype );
  errorCode += MPI_Type_commit( &Datatype );
  errorCode += MPI_Type_free( &tmpType );
  if (errorCode) std::cerr << "error constructing MPI datatype in " << __FILE__ << ":" << __LINE__ << std::endl;

  delete[] subtypes;
  delete[] blocklen;
  delete[] disp;

  #else
  // invoke routine once to trigger lazy initialisation
  getForkDatatype();
  getJoinDatatype();
  getBoundaryExchangeDatatype();
  getMultiscaleDataExchangeDatatype();
  getGlobalCommunciationDatatype();
  #endif
}


void tests::swift2::testSML1D::globaldata::hydroPart::shutdownDatatype() {
  #if !defined(__MPI_ATTRIBUTES_LANGUAGE_EXTENSION__)
  freeForkDatatype();
  freeJoinDatatype();
  freeBoundaryExchangeDatatype();
  freeMultiscaleDataExchangeDatatype();
  freeGlobalCommunciationDatatype();
  #else
  MPI_Datatype type = Datatype;
  MPI_Type_free( &type );
  #endif
}


void tests::swift2::testSML1D::globaldata::hydroPart::send(const tests::swift2::testSML1D::globaldata::hydroPart& buffer, int destination, int tag, MPI_Comm communicator ) {
  MPI_Send( &buffer, 1, Datatype, destination, tag, communicator);
}


void tests::swift2::testSML1D::globaldata::hydroPart::receive(tests::swift2::testSML1D::globaldata::hydroPart& buffer, int source, int tag, MPI_Comm communicator ) {
  MPI_Status status;
  MPI_Recv( &buffer, 1, Datatype, source, tag, communicator, &status);
  buffer._senderDestinationRank = status.MPI_SOURCE;
}


void tests::swift2::testSML1D::globaldata::hydroPart::send(
  const tests::swift2::testSML1D::globaldata::hydroPart& buffer,
  int destination,
  int tag,
  std::function<void()> startCommunicationFunctor,
  std::function<void()> waitFunctor,
  MPI_Comm communicator
) {
  MPI_Request sendRequestHandle;
  int         flag = 0;
  MPI_Isend( &buffer, 1, Datatype, destination, tag, communicator, &sendRequestHandle );
  MPI_Test( &sendRequestHandle, &flag, MPI_STATUS_IGNORE );
  startCommunicationFunctor();
  while (!flag) {
    waitFunctor();
    MPI_Test( &sendRequestHandle, &flag, MPI_STATUS_IGNORE );
  }
}


void tests::swift2::testSML1D::globaldata::hydroPart::receive(
  tests::swift2::testSML1D::globaldata::hydroPart& buffer,
  int source,
  int tag,
  std::function<void()> startCommunicationFunctor,
  std::function<void()> waitFunctor,
  MPI_Comm communicator
) {
  MPI_Status  status;
  MPI_Request receiveRequestHandle;
  int         flag = 0;
  MPI_Irecv( &buffer, 1, Datatype, source, tag, communicator, &receiveRequestHandle );
  MPI_Test( &receiveRequestHandle, &flag, &status );
  startCommunicationFunctor();
  while (!flag) {
    waitFunctor();
    MPI_Test( &receiveRequestHandle, &flag, &status );
  }
  buffer._senderDestinationRank = status.MPI_SOURCE;
}
#endif

#ifdef Parallel
void tests::swift2::testSML1D::globaldata::hydroPart::sendAndPollDanglingMessages(const tests::swift2::testSML1D::globaldata::hydroPart& message, int destination, int tag, MPI_Comm communicator ) {
  tests::swift2::testSML1D::globaldata::hydroPart::send(
    message, destination, tag,
    [&]() {
      tarch::mpi::Rank::getInstance().setDeadlockWarningTimeStamp();
      tarch::mpi::Rank::getInstance().setDeadlockTimeOutTimeStamp();
    },
    [&]() {
      tarch::mpi::Rank::getInstance().writeTimeOutWarning( "tests::swift2::testSML1D::globaldata::hydroPart", "sendAndPollDanglingMessages()",destination, tag );
      tarch::mpi::Rank::getInstance().triggerDeadlockTimeOut( "tests::swift2::testSML1D::globaldata::hydroPart", "sendAndPollDanglingMessages()", destination, tag );
      tarch::services::ServiceRepository::getInstance().receiveDanglingMessages();
    },
    communicator
  );
}


void tests::swift2::testSML1D::globaldata::hydroPart::receiveAndPollDanglingMessages(tests::swift2::testSML1D::globaldata::hydroPart& message, int source, int tag, MPI_Comm communicator ) {
  tests::swift2::testSML1D::globaldata::hydroPart::receive(
    message, source, tag,
    [&]() {
      tarch::mpi::Rank::getInstance().setDeadlockWarningTimeStamp();
      tarch::mpi::Rank::getInstance().setDeadlockTimeOutTimeStamp();
    },
    [&]() {
      tarch::mpi::Rank::getInstance().writeTimeOutWarning( "tests::swift2::testSML1D::globaldata::hydroPart", "receiveAndPollDanglingMessages()", source, tag );
      tarch::mpi::Rank::getInstance().triggerDeadlockTimeOut( "tests::swift2::testSML1D::globaldata::hydroPart", "receiveAndPollDanglingMessages()", source, tag );
      tarch::services::ServiceRepository::getInstance().receiveDanglingMessages();
    },
    communicator
  );
}
#endif

::swift2::ParticleSpecies& tests::swift2::testSML1D::globaldata::hydroPart::getSpecies() {
  static ::swift2::ParticleSpecies species;
  return species;
}
