#include "HydroPart.h"



#include <sstream>
#include <algorithm>

// Just some default values. Will be modified in actual test.
double tests::swift2::testSML1D::globaldata::HydroPart::_hydroDimensions = 1;
double tests::swift2::testSML1D::globaldata::HydroPart::_etaFactor = 2.5819884616099626;

int tests::swift2::testSML1D::globaldata::HydroPart::_smlMaxIterations = 50;
double tests::swift2::testSML1D::globaldata::HydroPart::_smlMin = 1e-06;
double tests::swift2::testSML1D::globaldata::HydroPart::_smlMax = 0.05;
double tests::swift2::testSML1D::globaldata::HydroPart::_smlTolerance = 1e-06;


tests::swift2::testSML1D::globaldata::HydroPart::HydroPart(tarch::la::Vector<Dimensions,double>  __debugX, tarch::la::Vector<Dimensions,double>  __debugH, tarch::la::Vector<Dimensions,double>  __x, tarch::la::Vector<Dimensions,double>  __cellH, double  __searchRadius, int  __partid, ParallelState  __ParallelState, MoveState  __MoveState, bool  __CellHasUpdatedParticle, double  __mass, tarch::la::Vector<Dimensions,double>  __v, tarch::la::Vector<Dimensions,double>  __a, double  __density, double  __pressure, double  __smoothingLength, double  __u, double  __uDot, tarch::la::Vector<Dimensions,double>  __v_full, double  __u_full, double  __wcount, double  __wcount_dh, double  __f, double  __hDot, double  __rho_dh, int  __smoothingLengthIterCount, double  __smlIterLeftBound, double  __smlIterRightBound, bool  __hasNoNeighbours, bool  __smoothingLengthConverged, int  __densityNeighbourCount, int  __forceNeighbourCount, double  __balsara, double  __rot_v, double  __div_v, double  __v_sig_AV, double  __soundSpeed, DependencyChecksPeanoEventUsedBySwift  __dependencyChecksPeanoEventUsedBySwift, DependencyChecksAlgorithmStepLastUpdated  __dependencyChecksAlgorithmStepLastUpdated, int  __dependencyChecksAlgorithmStepUpdates[24], int  __dependencyChecksAlgorithmStepMaskOuts[24], DependencyChecksInitStepLastUpdated  __dependencyChecksInitStepLastUpdated, int  __dependencyChecksInitStepUpdates[12], int  __dependencyChecksInitStepMaskOuts[12]){
#if PeanoDebug>0
setDebugX( __debugX);
#endif
#if PeanoDebug>0
setDebugH( __debugH);
#endif
setX( __x);
setCellH( __cellH);
setSearchRadius( __searchRadius);
#if PeanoDebug > 0
setPartid( __partid);
#endif
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
setSmlIterLeftBound( __smlIterLeftBound);
setSmlIterRightBound( __smlIterRightBound);
setHasNoNeighbours( __hasNoNeighbours);
setSmoothingLengthConverged( __smoothingLengthConverged);
#if PeanoDebug > 0
setDensityNeighbourCount( __densityNeighbourCount);
#endif
#if PeanoDebug > 0
setForceNeighbourCount( __forceNeighbourCount);
#endif
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



tests::swift2::testSML1D::globaldata::HydroPart::HydroPart( const HydroPart& copy ) {
#if PeanoDebug>0
  setDebugX( copy.getDebugX() );
#endif
#if PeanoDebug>0
  setDebugH( copy.getDebugH() );
#endif
  setX( copy.getX() );
  setCellH( copy.getCellH() );
  setSearchRadius( copy.getSearchRadius() );
#if PeanoDebug > 0
  setPartid( copy.getPartid() );
#endif
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
  setSmlIterLeftBound( copy.getSmlIterLeftBound() );
  setSmlIterRightBound( copy.getSmlIterRightBound() );
  setHasNoNeighbours( copy.getHasNoNeighbours() );
  setSmoothingLengthConverged( copy.getSmoothingLengthConverged() );
#if PeanoDebug > 0
  setDensityNeighbourCount( copy.getDensityNeighbourCount() );
#endif
#if PeanoDebug > 0
  setForceNeighbourCount( copy.getForceNeighbourCount() );
#endif
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





std::string tests::swift2::testSML1D::globaldata::HydroPart::toString() const {
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
#if PeanoDebug > 0
  out << ",";
  out << "partid=" << _partid;
#endif
  // out << ",";
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
  out << ",";
  out << "density=" << _density;
  out << ",";
  // out << "pressure=" << _pressure;
  // out << ",";
  out << "smoothingLength=" << _smoothingLength;
  out << ",";
  // out << "u=" << _u;
  // out << ",";
  // out << "uDot=" << _uDot;
  // out << ",";
  // out << "v_full=" << _v_full;
  // out << ",";
  // out << "u_full=" << _u_full;
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
  out << "smlIterLeftBound=" << _smlIterLeftBound;
  out << ",";
  out << "smlIterRightBound=" << _smlIterRightBound;
  out << ",";
  out << "hasNoNeighbours=" << _hasNoNeighbours;
  out << ",";
  out << "smoothingLengthConverged=" << _smoothingLengthConverged;
#if PeanoDebug > 0
  out << ",";
  out << "densityNeighbourCount=" << _densityNeighbourCount;
#endif
// #if PeanoDebug > 0
//   out << ",";
//   out << "forceNeighbourCount=" << _forceNeighbourCount;
// #endif
  // out << ",";
  // out << "cfl=" << _cfl;
  // out << ",";
  // out << "initialTimeStepSize=" << _initialTimeStepSize;
  // out << ",";
  // out << "adjustTimeStepSize=" << _adjustTimeStepSize;
  out << ",";
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
//   out << ",";
//   out << "alphaAV=" << _alphaAV;
//   out << ",";
//   out << "betaAV=" << _betaAV;
//   out << ",";
//   out << "balsara=" << _balsara;
//   out << ",";
//   out << "rot_v=" << _rot_v;
//   out << ",";
//   out << "div_v=" << _div_v;
//   out << ",";
//   out << "v_sig_AV=" << _v_sig_AV;
//   out << ",";
//   out << "soundSpeed=" << _soundSpeed;
// #if PeanoDebug > 0
//   out << ",";
//   out << "dependencyChecksPeanoEventUsedBySwift=" << toString(_dependencyChecksPeanoEventUsedBySwift);
// #endif
// #if PeanoDebug > 0
//   out << ",";
//   out << "dependencyChecksAlgorithmStepLastUpdated=" << toString(_dependencyChecksAlgorithmStepLastUpdated);
// #endif
// #if PeanoDebug > 0
//   out << ",";
//   out << "dependencyChecksAlgorithmStepUpdates=" << _dependencyChecksAlgorithmStepUpdates[0] << ",...";
// #endif
// #if PeanoDebug > 0
//   out << ",";
//   out << "dependencyChecksAlgorithmStepMaskOuts=" << _dependencyChecksAlgorithmStepMaskOuts[0] << ",...";
// #endif
// #if PeanoDebug > 0
//   out << ",";
//   out << "dependencyChecksInitStepLastUpdated=" << toString(_dependencyChecksInitStepLastUpdated);
// #endif
// #if PeanoDebug > 0
//   out << ",";
//   out << "dependencyChecksInitStepUpdates=" << _dependencyChecksInitStepUpdates[0] << ",...";
// #endif
// #if PeanoDebug > 0
//   out << ",";
//   out << "dependencyChecksInitStepMaskOuts=" << _dependencyChecksInitStepMaskOuts[0] << ",...";
// #endif
  out << ")";
  return out.str();
}





#if PeanoDebug>0
tarch::la::Vector<Dimensions,double>   tests::swift2::testSML1D::globaldata::HydroPart::getDebugX() const {
  return   _debugX;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setDebugX(const tarch::la::Vector<Dimensions,double>& value) {
  _debugX = value;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getDebugX(int index) const {
  return   _debugX(index);
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setDebugX(int index, double value) {
  _debugX(index) = value;
}


#endif


#if PeanoDebug>0
tarch::la::Vector<Dimensions,double>   tests::swift2::testSML1D::globaldata::HydroPart::getDebugH() const {
  return   _debugH;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setDebugH(const tarch::la::Vector<Dimensions,double>& value) {
  _debugH = value;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getDebugH(int index) const {
  return   _debugH(index);
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setDebugH(int index, double value) {
  _debugH(index) = value;
}


#endif


tarch::la::Vector<Dimensions,double>   tests::swift2::testSML1D::globaldata::HydroPart::getX() const {
  return   _x;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setX(const tarch::la::Vector<Dimensions,double>& value) {
  _x = value;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getX(int index) const {
  return   _x(index);
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setX(int index, double value) {
  _x(index) = value;
}


tarch::la::Vector<Dimensions,double>   tests::swift2::testSML1D::globaldata::HydroPart::getCellH() const {
  return   _cellH;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setCellH(const tarch::la::Vector<Dimensions,double>& value) {
  _cellH = value;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getCellH(int index) const {
  return   _cellH(index);
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setCellH(int index, double value) {
  _cellH(index) = value;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getSearchRadius() const {
  return _searchRadius;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setSearchRadius(double value) {
  _searchRadius = value;
}


#if PeanoDebug > 0
int   tests::swift2::testSML1D::globaldata::HydroPart::getPartid() const {
  return _partid;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setPartid(int value) {
  _partid = value;
}


#endif


tests::swift2::testSML1D::globaldata::HydroPart::ParallelState   tests::swift2::testSML1D::globaldata::HydroPart::getParallelState() const {
  return _ParallelState;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setParallelState(ParallelState value) {
  _ParallelState = value;
}


std::string   tests::swift2::testSML1D::globaldata::HydroPart::toString(ParallelState value) {
  std::ostringstream out;
  out  << (value ==ParallelState::Local? "Local" : "")  << (value ==ParallelState::Virtual? "Virtual" : "") ;
  return out.str();
}


tests::swift2::testSML1D::globaldata::HydroPart::MoveState   tests::swift2::testSML1D::globaldata::HydroPart::getMoveState() const {
  return _MoveState;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setMoveState(MoveState value) {
  _MoveState = value;
}


std::string   tests::swift2::testSML1D::globaldata::HydroPart::toString(MoveState value) {
  std::ostringstream out;
  out  << (value ==MoveState::New? "New" : "")  << (value ==MoveState::NotMovedYet? "NotMovedYet" : "")  << (value ==MoveState::Moved? "Moved" : "") ;
  return out.str();
}


bool   tests::swift2::testSML1D::globaldata::HydroPart::getCellHasUpdatedParticle() const {
  return _CellHasUpdatedParticle;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setCellHasUpdatedParticle(bool value) {
  _CellHasUpdatedParticle = value;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getMass() const {
  return _mass;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setMass(double value) {
  _mass = value;
}


tarch::la::Vector<Dimensions,double>   tests::swift2::testSML1D::globaldata::HydroPart::getV() const {
  return   _v;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setV(const tarch::la::Vector<Dimensions,double>& value) {
  _v = value;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getV(int index) const {
  return   _v(index);
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setV(int index, double value) {
  _v(index) = value;
}


tarch::la::Vector<Dimensions,double>   tests::swift2::testSML1D::globaldata::HydroPart::getA() const {
  return   _a;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setA(const tarch::la::Vector<Dimensions,double>& value) {
  _a = value;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getA(int index) const {
  return   _a(index);
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setA(int index, double value) {
  _a(index) = value;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getDensity() const {
  return _density;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setDensity(double value) {
  _density = value;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getPressure() const {
  return _pressure;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setPressure(double value) {
  _pressure = value;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getSmoothingLength() const {
  return _smoothingLength;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setSmoothingLength(double value) {
  _smoothingLength = value;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getU() const {
  return _u;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setU(double value) {
  _u = value;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getUDot() const {
  return _uDot;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setUDot(double value) {
  _uDot = value;
}


tarch::la::Vector<Dimensions,double>   tests::swift2::testSML1D::globaldata::HydroPart::getV_full() const {
  return   _v_full;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setV_full(const tarch::la::Vector<Dimensions,double>& value) {
  _v_full = value;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getV_full(int index) const {
  return   _v_full(index);
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setV_full(int index, double value) {
  _v_full(index) = value;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getU_full() const {
  return _u_full;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setU_full(double value) {
  _u_full = value;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getWcount() const {
  return _wcount;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setWcount(double value) {
  _wcount = value;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getWcount_dh() const {
  return _wcount_dh;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setWcount_dh(double value) {
  _wcount_dh = value;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getF() const {
  return _f;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setF(double value) {
  _f = value;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getHDot() const {
  return _hDot;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setHDot(double value) {
  _hDot = value;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getRho_dh() const {
  return _rho_dh;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setRho_dh(double value) {
  _rho_dh = value;
}


int   tests::swift2::testSML1D::globaldata::HydroPart::getSmoothingLengthIterCount() const {
  return _smoothingLengthIterCount;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setSmoothingLengthIterCount(int value) {
  _smoothingLengthIterCount = value;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getSmlIterLeftBound() const {
  return _smlIterLeftBound;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setSmlIterLeftBound(double value) {
  _smlIterLeftBound = value;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getSmlIterRightBound() const {
  return _smlIterRightBound;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setSmlIterRightBound(double value) {
  _smlIterRightBound = value;
}


bool   tests::swift2::testSML1D::globaldata::HydroPart::getHasNoNeighbours() const {
  return _hasNoNeighbours;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setHasNoNeighbours(bool value) {
  _hasNoNeighbours = value;
}


bool   tests::swift2::testSML1D::globaldata::HydroPart::getSmoothingLengthConverged() const {
  return _smoothingLengthConverged;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setSmoothingLengthConverged(bool value) {
  _smoothingLengthConverged = value;
}


#if PeanoDebug > 0
int   tests::swift2::testSML1D::globaldata::HydroPart::getDensityNeighbourCount() const {
  return _densityNeighbourCount;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setDensityNeighbourCount(int value) {
  _densityNeighbourCount = value;
}


#endif


#if PeanoDebug > 0
int   tests::swift2::testSML1D::globaldata::HydroPart::getForceNeighbourCount() const {
  return _forceNeighbourCount;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setForceNeighbourCount(int value) {
  _forceNeighbourCount = value;
}


#endif


double   tests::swift2::testSML1D::globaldata::HydroPart::getCfl() {
  return _cfl;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getInitialTimeStepSize() {
  return _initialTimeStepSize;
}


bool   tests::swift2::testSML1D::globaldata::HydroPart::getAdjustTimeStepSize() {
  return _adjustTimeStepSize;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getHydroDimensions() {
  return _hydroDimensions;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getEtaFactor() {
  return _etaFactor;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getSmlMin() {
  return _smlMin;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getSmlMax() {
  return _smlMax;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getSmlTolerance() {
  return _smlTolerance;
}


int   tests::swift2::testSML1D::globaldata::HydroPart::getSmlMaxIterations() {
  return _smlMaxIterations;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getAlphaAV() {
  return _alphaAV;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getBetaAV() {
  return _betaAV;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getBalsara() const {
  return _balsara;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setBalsara(double value) {
  _balsara = value;
}

// This needs modifications compared to the generated HydroPart to
// allow for different dimensions.
#if Dimensions < 3
double   tests::swift2::testSML1D::globaldata::HydroPart::getRot_v() const {
  return _rot_v;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setRot_v(double value) {
  _rot_v = value;
}
#else

tarch::la::Vector<Dimensions,double>   tests::swift2::testSML1D::globaldata::HydroPart::getRot_v() const {
  return   _rot_v;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setRot_v(const tarch::la::Vector<Dimensions,double>& value) {
  _rot_v = value;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getRot_v(int index) const {
  return   _rot_v(index);
}

#endif




double   tests::swift2::testSML1D::globaldata::HydroPart::getDiv_v() const {
  return _div_v;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setDiv_v(double value) {
  _div_v = value;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getV_sig_AV() const {
  return _v_sig_AV;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setV_sig_AV(double value) {
  _v_sig_AV = value;
}


double   tests::swift2::testSML1D::globaldata::HydroPart::getSoundSpeed() const {
  return _soundSpeed;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setSoundSpeed(double value) {
  _soundSpeed = value;
}


#if PeanoDebug > 0
tests::swift2::testSML1D::globaldata::HydroPart::DependencyChecksPeanoEventUsedBySwift   tests::swift2::testSML1D::globaldata::HydroPart::getDependencyChecksPeanoEventUsedBySwift() const {
  return _dependencyChecksPeanoEventUsedBySwift;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setDependencyChecksPeanoEventUsedBySwift(DependencyChecksPeanoEventUsedBySwift value) {
  _dependencyChecksPeanoEventUsedBySwift = value;
}


std::string   tests::swift2::testSML1D::globaldata::HydroPart::toString(DependencyChecksPeanoEventUsedBySwift value) {
  std::ostringstream out;
  out  << (value ==DependencyChecksPeanoEventUsedBySwift::touchVertexFirstTime? "touchVertexFirstTime" : "")  << (value ==DependencyChecksPeanoEventUsedBySwift::cellKernel? "cellKernel" : "")  << (value ==DependencyChecksPeanoEventUsedBySwift::touchVertexLastTime? "touchVertexLastTime" : "")  << (value ==DependencyChecksPeanoEventUsedBySwift::count? "count" : "") ;
  return out.str();
}


#endif


#if PeanoDebug > 0
tests::swift2::testSML1D::globaldata::HydroPart::DependencyChecksAlgorithmStepLastUpdated   tests::swift2::testSML1D::globaldata::HydroPart::getDependencyChecksAlgorithmStepLastUpdated() const {
  return _dependencyChecksAlgorithmStepLastUpdated;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setDependencyChecksAlgorithmStepLastUpdated(DependencyChecksAlgorithmStepLastUpdated value) {
  _dependencyChecksAlgorithmStepLastUpdated = value;
}


std::string   tests::swift2::testSML1D::globaldata::HydroPart::toString(DependencyChecksAlgorithmStepLastUpdated value) {
  std::ostringstream out;
  out  << (value ==DependencyChecksAlgorithmStepLastUpdated::SPH_Drift? "SPH_Drift" : "")  << (value ==DependencyChecksAlgorithmStepLastUpdated::PredictHydro? "PredictHydro" : "")  << (value ==DependencyChecksAlgorithmStepLastUpdated::SPH_DensityLoopWithConstantSearchRadius? "SPH_DensityLoopWithConstantSearchRadius" : "")  << (value ==DependencyChecksAlgorithmStepLastUpdated::SPH_ForceLoop? "SPH_ForceLoop" : "")  << (value ==DependencyChecksAlgorithmStepLastUpdated::SPH_Kick2? "SPH_Kick2" : "")  << (value ==DependencyChecksAlgorithmStepLastUpdated::SPH_Timestep? "SPH_Timestep" : "")  << (value ==DependencyChecksAlgorithmStepLastUpdated::SPH_ReduceGlobalQuantities? "SPH_ReduceGlobalQuantities" : "")  << (value ==DependencyChecksAlgorithmStepLastUpdated::SPH_Kick1? "SPH_Kick1" : "")  << (value ==DependencyChecksAlgorithmStepLastUpdated::count? "count" : "") ;
  return out.str();
}


#endif


#if PeanoDebug > 0
const int*   tests::swift2::testSML1D::globaldata::HydroPart::getDependencyChecksAlgorithmStepUpdates() const {
  return    _dependencyChecksAlgorithmStepUpdates;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setDependencyChecksAlgorithmStepUpdates(const int value[24]) {
  std::copy_n(value, 24,   _dependencyChecksAlgorithmStepUpdates );
}


int   tests::swift2::testSML1D::globaldata::HydroPart::getDependencyChecksAlgorithmStepUpdates(int index) const {
  return    _dependencyChecksAlgorithmStepUpdates[index];
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setDependencyChecksAlgorithmStepUpdates(int index, int value) {
  _dependencyChecksAlgorithmStepUpdates[index] = value;
}


#endif


#if PeanoDebug > 0
const int*   tests::swift2::testSML1D::globaldata::HydroPart::getDependencyChecksAlgorithmStepMaskOuts() const {
  return    _dependencyChecksAlgorithmStepMaskOuts;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setDependencyChecksAlgorithmStepMaskOuts(const int value[24]) {
  std::copy_n(value, 24,   _dependencyChecksAlgorithmStepMaskOuts );
}


int   tests::swift2::testSML1D::globaldata::HydroPart::getDependencyChecksAlgorithmStepMaskOuts(int index) const {
  return    _dependencyChecksAlgorithmStepMaskOuts[index];
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setDependencyChecksAlgorithmStepMaskOuts(int index, int value) {
  _dependencyChecksAlgorithmStepMaskOuts[index] = value;
}


#endif


#if PeanoDebug > 0
tests::swift2::testSML1D::globaldata::HydroPart::DependencyChecksInitStepLastUpdated   tests::swift2::testSML1D::globaldata::HydroPart::getDependencyChecksInitStepLastUpdated() const {
  return _dependencyChecksInitStepLastUpdated;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setDependencyChecksInitStepLastUpdated(DependencyChecksInitStepLastUpdated value) {
  _dependencyChecksInitStepLastUpdated = value;
}


std::string   tests::swift2::testSML1D::globaldata::HydroPart::toString(DependencyChecksInitStepLastUpdated value) {
  std::ostringstream out;
  out  << (value ==DependencyChecksInitStepLastUpdated::SPH_FirstInitParticle? "SPH_FirstInitParticle" : "")  << (value ==DependencyChecksInitStepLastUpdated::SPH_DensityLoopWithConstantSearchRadius? "SPH_DensityLoopWithConstantSearchRadius" : "")  << (value ==DependencyChecksInitStepLastUpdated::SPH_ForceLoop? "SPH_ForceLoop" : "")  << (value ==DependencyChecksInitStepLastUpdated::SPH_Timestep? "SPH_Timestep" : "")  << (value ==DependencyChecksInitStepLastUpdated::count? "count" : "") ;
  return out.str();
}


#endif


#if PeanoDebug > 0
const int*   tests::swift2::testSML1D::globaldata::HydroPart::getDependencyChecksInitStepUpdates() const {
  return    _dependencyChecksInitStepUpdates;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setDependencyChecksInitStepUpdates(const int value[12]) {
  std::copy_n(value, 12,   _dependencyChecksInitStepUpdates );
}


int   tests::swift2::testSML1D::globaldata::HydroPart::getDependencyChecksInitStepUpdates(int index) const {
  return    _dependencyChecksInitStepUpdates[index];
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setDependencyChecksInitStepUpdates(int index, int value) {
  _dependencyChecksInitStepUpdates[index] = value;
}


#endif


#if PeanoDebug > 0
const int*   tests::swift2::testSML1D::globaldata::HydroPart::getDependencyChecksInitStepMaskOuts() const {
  return    _dependencyChecksInitStepMaskOuts;
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setDependencyChecksInitStepMaskOuts(const int value[12]) {
  std::copy_n(value, 12,   _dependencyChecksInitStepMaskOuts );
}


int   tests::swift2::testSML1D::globaldata::HydroPart::getDependencyChecksInitStepMaskOuts(int index) const {
  return    _dependencyChecksInitStepMaskOuts[index];
}


void   tests::swift2::testSML1D::globaldata::HydroPart::setDependencyChecksInitStepMaskOuts(int index, int value) {
  _dependencyChecksInitStepMaskOuts[index] = value;
}


#endif






#ifdef Parallel

#if !defined(__MPI_ATTRIBUTES_LANGUAGE_EXTENSION__)
MPI_Datatype tests::swift2::testSML1D::globaldata::HydroPart::Datatype = MPI_DATATYPE_NULL;
#endif


[[clang::map_mpi_datatype]]
MPI_Datatype tests::swift2::testSML1D::globaldata::HydroPart::getForkDatatype() {
  return Datatype;
}


[[clang::map_mpi_datatype]]
MPI_Datatype tests::swift2::testSML1D::globaldata::HydroPart::getGlobalCommunciationDatatype() {
  return Datatype;
}


[[clang::map_mpi_datatype]]
MPI_Datatype tests::swift2::testSML1D::globaldata::HydroPart::getJoinDatatype() {
  return Datatype;
}


[[clang::map_mpi_datatype]]
MPI_Datatype tests::swift2::testSML1D::globaldata::HydroPart::getBoundaryExchangeDatatype() {
  return Datatype;
}


[[clang::map_mpi_datatype]]
MPI_Datatype tests::swift2::testSML1D::globaldata::HydroPart::getMultiscaleDataExchangeDatatype() {
  return Datatype;
}


[[clang::map_mpi_datatype]]
void tests::swift2::testSML1D::globaldata::HydroPart::freeForkDatatype() {
  if (Datatype != MPI_DATATYPE_NULL){
    MPI_Type_free(&Datatype);
    Datatype = MPI_DATATYPE_NULL;
  }
}


[[clang::map_mpi_datatype]]
void tests::swift2::testSML1D::globaldata::HydroPart::freeGlobalCommunciationDatatype() {
  if (Datatype != MPI_DATATYPE_NULL){
    MPI_Type_free(&Datatype);
    Datatype = MPI_DATATYPE_NULL;
  }
}


[[clang::map_mpi_datatype]]
void tests::swift2::testSML1D::globaldata::HydroPart::freeJoinDatatype() {
  if (Datatype != MPI_DATATYPE_NULL){
    MPI_Type_free(&Datatype);
    Datatype = MPI_DATATYPE_NULL;
  }
}


[[clang::map_mpi_datatype]]
void tests::swift2::testSML1D::globaldata::HydroPart::freeBoundaryExchangeDatatype() {
  if (Datatype != MPI_DATATYPE_NULL){
    MPI_Type_free(&Datatype);
    Datatype = MPI_DATATYPE_NULL;
  }
}


[[clang::map_mpi_datatype]]
void tests::swift2::testSML1D::globaldata::HydroPart::freeMultiscaleDataExchangeDatatype() {
  if (Datatype != MPI_DATATYPE_NULL){
    MPI_Type_free(&Datatype);
    Datatype = MPI_DATATYPE_NULL;
  }
}


int tests::swift2::testSML1D::globaldata::HydroPart::getSenderRank() const {
  return _senderDestinationRank;
}



void tests::swift2::testSML1D::globaldata::HydroPart::initDatatype() {
  #if !defined(__MPI_ATTRIBUTES_LANGUAGE_EXTENSION__)
  tests::swift2::testSML1D::globaldata::HydroPart  instances[2];

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
#if PeanoDebug > 0
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
#if PeanoDebug > 0
  NumberOfAttributes++;
#endif
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
#if PeanoDebug > 0
  subtypes[counter] = MPI_INT;
  blocklen[counter] = 1;
  counter++;
#endif
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
  subtypes[counter] = MPI_DOUBLE;
  blocklen[counter] = 1;
  counter++;
  subtypes[counter] = MPI_DOUBLE;
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
#if PeanoDebug > 0
  subtypes[counter] = MPI_INT;
  blocklen[counter] = 1;
  counter++;
#endif
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
  blocklen[counter] = 24;
  counter++;
#endif
#if PeanoDebug > 0
  subtypes[counter] = MPI_INT;
  blocklen[counter] = 24;
  counter++;
#endif
#if PeanoDebug > 0
  subtypes[counter] = MPI_INT;
  blocklen[counter] = 1;
  counter++;
#endif
#if PeanoDebug > 0
  subtypes[counter] = MPI_INT;
  blocklen[counter] = 12;
  counter++;
#endif
#if PeanoDebug > 0
  subtypes[counter] = MPI_INT;
  blocklen[counter] = 12;
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

#if PeanoDebug > 0
  MPI_Get_address( &(instances[0]._partid = -1), &disp[counter] );
  counter++;
#endif
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
  MPI_Get_address( &(instances[0]._smoothingLength = 0.0), &disp[counter] );
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
  MPI_Get_address( &(instances[0]._smlIterLeftBound), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._smlIterRightBound), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._hasNoNeighbours), &disp[counter] );
  counter++;
  MPI_Get_address( &(instances[0]._smoothingLengthConverged = false), &disp[counter] );
  counter++;

#if PeanoDebug > 0
  MPI_Get_address( &(instances[0]._densityNeighbourCount), &disp[counter] );
  counter++;
#endif

#if PeanoDebug > 0
  MPI_Get_address( &(instances[0]._forceNeighbourCount), &disp[counter] );
  counter++;
#endif
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


void tests::swift2::testSML1D::globaldata::HydroPart::shutdownDatatype() {
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


void tests::swift2::testSML1D::globaldata::HydroPart::send(const tests::swift2::testSML1D::globaldata::HydroPart& buffer, int destination, int tag, MPI_Comm communicator ) {
  MPI_Send( &buffer, 1, Datatype, destination, tag, communicator);
}


void tests::swift2::testSML1D::globaldata::HydroPart::receive(tests::swift2::testSML1D::globaldata::HydroPart& buffer, int source, int tag, MPI_Comm communicator ) {
  MPI_Status status;
  MPI_Recv( &buffer, 1, Datatype, source, tag, communicator, &status);
  buffer._senderDestinationRank = status.MPI_SOURCE;
}


void tests::swift2::testSML1D::globaldata::HydroPart::send(
  const tests::swift2::testSML1D::globaldata::HydroPart& buffer,
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


void tests::swift2::testSML1D::globaldata::HydroPart::receive(
  tests::swift2::testSML1D::globaldata::HydroPart& buffer,
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
void tests::swift2::testSML1D::globaldata::HydroPart::sendAndPollDanglingMessages(const tests::swift2::testSML1D::globaldata::HydroPart& message, int destination, int tag, MPI_Comm communicator ) {
  tests::swift2::testSML1D::globaldata::HydroPart::send(
    message, destination, tag,
    [&]() {
      tarch::mpi::Rank::getInstance().setDeadlockWarningTimeStamp();
      tarch::mpi::Rank::getInstance().setDeadlockTimeOutTimeStamp();
    },
    [&]() {
      tarch::mpi::Rank::getInstance().writeTimeOutWarning( "tests::swift2::testSML1D::globaldata::HydroPart", "sendAndPollDanglingMessages()",destination, tag );
      tarch::mpi::Rank::getInstance().triggerDeadlockTimeOut( "tests::swift2::testSML1D::globaldata::HydroPart", "sendAndPollDanglingMessages()", destination, tag );
      tarch::services::ServiceRepository::getInstance().receiveDanglingMessages();
    },
    communicator
  );
}


void tests::swift2::testSML1D::globaldata::HydroPart::receiveAndPollDanglingMessages(tests::swift2::testSML1D::globaldata::HydroPart& message, int source, int tag, MPI_Comm communicator ) {
  tests::swift2::testSML1D::globaldata::HydroPart::receive(
    message, source, tag,
    [&]() {
      tarch::mpi::Rank::getInstance().setDeadlockWarningTimeStamp();
      tarch::mpi::Rank::getInstance().setDeadlockTimeOutTimeStamp();
    },
    [&]() {
      tarch::mpi::Rank::getInstance().writeTimeOutWarning( "tests::swift2::testSML1D::globaldata::HydroPart", "receiveAndPollDanglingMessages()", source, tag );
      tarch::mpi::Rank::getInstance().triggerDeadlockTimeOut( "tests::swift2::testSML1D::globaldata::HydroPart", "receiveAndPollDanglingMessages()", source, tag );
      tarch::services::ServiceRepository::getInstance().receiveDanglingMessages();
    },
    communicator
  );
}
#endif

::swift2::ParticleSpecies& tests::swift2::testSML1D::globaldata::HydroPart::getSpecies() {
  static ::swift2::ParticleSpecies species;
  return species;
}
