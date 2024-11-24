
//
// Generated by DaStGen2 (C) 2020 Tobias Weinzierl
//
// For DaStGen's copyright, visit www.peano-framework.org. These generated files
// however are not subject of copyright, i.e. feel free to add your copyright in
// here
//
#pragma once

#include "myconfig.h"
#include <string>



#ifdef Parallel
  #include <mpi.h>
  #include <functional>
#endif

#include "tarch/la/Vector.h"
#include "tarch/mpi/Rank.h"
#include "tarch/services/ServiceRepository.h"
#include "peano4/grid/LoadStoreComputeFlag.h"
#include "peano4/utils/Globals.h"
#include "peano4/grid/TraversalObserver.h"

#include "peano4/datamanagement/CellMarker.h"
#include "peano4/datamanagement/FaceMarker.h"
#include "peano4/datamanagement/VertexMarker.h"



#include "swift2/ParticleSpecies.h"




namespace tests{
namespace swift2{
namespace testSML1D{
namespace globaldata{

  struct HydroPart;
}
}
}
}



struct tests::swift2::testSML1D::globaldata::HydroPart {
  public:

    enum class ParallelState: int {
      Local=0, Virtual=1
    };
    enum class MoveState: int {
      New=0, NotMovedYet=1, Moved=2
    };
    enum class DependencyChecksPeanoEventUsedBySwift: int {
      touchVertexFirstTime=0, cellKernel=1, touchVertexLastTime=2, count=3
    };
    enum class DependencyChecksAlgorithmStepLastUpdated: int {
      SPH_Drift=0, PredictHydro=1, SPH_DensityLoopWithConstantSearchRadius=2, SPH_ForceLoop=3, SPH_Kick2=4, SPH_Timestep=5, SPH_ReduceGlobalQuantities=6, SPH_Kick1=7, count=8
    };
    enum class DependencyChecksInitStepLastUpdated: int {
      SPH_FirstInitParticle=0, SPH_DensityLoopWithConstantSearchRadius=1, SPH_ForceLoop=2, SPH_Timestep=3, count=4
    };

    HydroPart() {}
    HydroPart(tarch::la::Vector<Dimensions,double>  __debugX, tarch::la::Vector<Dimensions,double>  __debugH, tarch::la::Vector<Dimensions,double>  __x, tarch::la::Vector<Dimensions,double>  __cellH, double  __searchRadius, int  __partid, ParallelState  __ParallelState, MoveState  __MoveState, bool  __CellHasUpdatedParticle, double  __mass, tarch::la::Vector<Dimensions,double>  __v, tarch::la::Vector<Dimensions,double>  __a, double  __density, double  __pressure, double  __smoothingLength, double  __u, double  __uDot, tarch::la::Vector<Dimensions,double>  __v_full, double  __u_full, double  __wcount, double  __wcount_dh, double  __f, double  __hDot, double  __rho_dh, int  __smoothingLengthIterCount, double  __smlIterLeftBound, double  __smlIterRightBound, bool  __hasNoNeighbours, bool  __smoothingLengthConverged, int  __densityNeighbourCount, int  __forceNeighbourCount, double  __balsara, double  __rot_v, double  __div_v, double  __v_sig_AV, double  __soundSpeed, DependencyChecksPeanoEventUsedBySwift  __dependencyChecksPeanoEventUsedBySwift, DependencyChecksAlgorithmStepLastUpdated  __dependencyChecksAlgorithmStepLastUpdated, int  __dependencyChecksAlgorithmStepUpdates[24], int  __dependencyChecksAlgorithmStepMaskOuts[24], DependencyChecksInitStepLastUpdated  __dependencyChecksInitStepLastUpdated, int  __dependencyChecksInitStepUpdates[12], int  __dependencyChecksInitStepMaskOuts[12]);


#if PeanoDebug>0
    tarch::la::Vector<Dimensions,double>   getDebugX() const;
    void   setDebugX(const tarch::la::Vector<Dimensions,double>& value);
    double   getDebugX(int index) const;
    void   setDebugX(int index, double value);
#endif
#if PeanoDebug>0
    tarch::la::Vector<Dimensions,double>   getDebugH() const;
    void   setDebugH(const tarch::la::Vector<Dimensions,double>& value);
    double   getDebugH(int index) const;
    void   setDebugH(int index, double value);
#endif
    tarch::la::Vector<Dimensions,double>   getX() const;
    void   setX(const tarch::la::Vector<Dimensions,double>& value);
    double   getX(int index) const;
    void   setX(int index, double value);
    tarch::la::Vector<Dimensions,double>   getCellH() const;
    void   setCellH(const tarch::la::Vector<Dimensions,double>& value);
    double   getCellH(int index) const;
    void   setCellH(int index, double value);
    double   getSearchRadius() const;
    void   setSearchRadius(double value);
#if PeanoDebug > 0
    int   getPartid() const;
    void   setPartid(int value);
#endif
    tests::swift2::testSML1D::globaldata::HydroPart::ParallelState   getParallelState() const;
    void   setParallelState(ParallelState value);
    static std::string   toString(ParallelState value);
    tests::swift2::testSML1D::globaldata::HydroPart::MoveState   getMoveState() const;
    void   setMoveState(MoveState value);
    static std::string   toString(MoveState value);
    bool   getCellHasUpdatedParticle() const;
    void   setCellHasUpdatedParticle(bool value);
    double   getMass() const;
    void   setMass(double value);
    tarch::la::Vector<Dimensions,double>   getV() const;
    void   setV(const tarch::la::Vector<Dimensions,double>& value);
    double   getV(int index) const;
    void   setV(int index, double value);
    tarch::la::Vector<Dimensions,double>   getA() const;
    void   setA(const tarch::la::Vector<Dimensions,double>& value);
    double   getA(int index) const;
    void   setA(int index, double value);
    double   getDensity() const;
    void   setDensity(double value);
    double   getPressure() const;
    void   setPressure(double value);
    double   getSmoothingLength() const;
    void   setSmoothingLength(double value);
    double   getU() const;
    void   setU(double value);
    double   getUDot() const;
    void   setUDot(double value);
    tarch::la::Vector<Dimensions,double>   getV_full() const;
    void   setV_full(const tarch::la::Vector<Dimensions,double>& value);
    double   getV_full(int index) const;
    void   setV_full(int index, double value);
    double   getU_full() const;
    void   setU_full(double value);
    double   getWcount() const;
    void   setWcount(double value);
    double   getWcount_dh() const;
    void   setWcount_dh(double value);
    double   getF() const;
    void   setF(double value);
    double   getHDot() const;
    void   setHDot(double value);
    double   getRho_dh() const;
    void   setRho_dh(double value);
    int   getSmoothingLengthIterCount() const;
    void   setSmoothingLengthIterCount(int value);
    double   getSmlIterLeftBound() const;
    void   setSmlIterLeftBound(double value);
    double   getSmlIterRightBound() const;
    void   setSmlIterRightBound(double value);
    bool   getHasNoNeighbours() const;
    void   setHasNoNeighbours(bool value);
    bool   getSmoothingLengthConverged() const;
    void   setSmoothingLengthConverged(bool value);
#if PeanoDebug > 0
    int   getDensityNeighbourCount() const;
    void   setDensityNeighbourCount(int value);
#endif
#if PeanoDebug > 0
    int   getForceNeighbourCount() const;
    void   setForceNeighbourCount(int value);
#endif
    static double   getCfl();
    static double   getInitialTimeStepSize();
    static bool   getAdjustTimeStepSize();
    static double   getHydroDimensions();
    static double   getEtaFactor();
    static double   getSmlMin();
    static double   getSmlMax();
    static double   getSmlTolerance();
    static int   getSmlMaxIterations();
    static double   getAlphaAV();
    static double   getBetaAV();
    double   getBalsara() const;
    void   setBalsara(double value);
// Manual changes to allow for different dimensions in this unit test
#if Dimensions < 3
    double   getRot_v() const;
    void   setRot_v(double value);
#else
    tarch::la::Vector<Dimensions,double>   getRot_v() const;
    void   setRot_v(const tarch::la::Vector<Dimensions,double>& value);
    double   getRot_v(int index) const;
    void   setRot_v(int index, double value);
#endif
    double   getDiv_v() const;
    void   setDiv_v(double value);
    double   getV_sig_AV() const;
    void   setV_sig_AV(double value);
    double   getSoundSpeed() const;
    void   setSoundSpeed(double value);
#if PeanoDebug > 0
    tests::swift2::testSML1D::globaldata::HydroPart::DependencyChecksPeanoEventUsedBySwift   getDependencyChecksPeanoEventUsedBySwift() const;
    void   setDependencyChecksPeanoEventUsedBySwift(DependencyChecksPeanoEventUsedBySwift value);
    static std::string   toString(DependencyChecksPeanoEventUsedBySwift value);
#endif
#if PeanoDebug > 0
    tests::swift2::testSML1D::globaldata::HydroPart::DependencyChecksAlgorithmStepLastUpdated   getDependencyChecksAlgorithmStepLastUpdated() const;
    void   setDependencyChecksAlgorithmStepLastUpdated(DependencyChecksAlgorithmStepLastUpdated value);
    static std::string   toString(DependencyChecksAlgorithmStepLastUpdated value);
#endif
#if PeanoDebug > 0
    const int*   getDependencyChecksAlgorithmStepUpdates() const;
    void   setDependencyChecksAlgorithmStepUpdates(const int value[24]);
    int   getDependencyChecksAlgorithmStepUpdates(int index) const;
    void   setDependencyChecksAlgorithmStepUpdates(int index, int value);
#endif
#if PeanoDebug > 0
    const int*   getDependencyChecksAlgorithmStepMaskOuts() const;
    void   setDependencyChecksAlgorithmStepMaskOuts(const int value[24]);
    int   getDependencyChecksAlgorithmStepMaskOuts(int index) const;
    void   setDependencyChecksAlgorithmStepMaskOuts(int index, int value);
#endif
#if PeanoDebug > 0
    tests::swift2::testSML1D::globaldata::HydroPart::DependencyChecksInitStepLastUpdated   getDependencyChecksInitStepLastUpdated() const;
    void   setDependencyChecksInitStepLastUpdated(DependencyChecksInitStepLastUpdated value);
    static std::string   toString(DependencyChecksInitStepLastUpdated value);
#endif
#if PeanoDebug > 0
    const int*   getDependencyChecksInitStepUpdates() const;
    void   setDependencyChecksInitStepUpdates(const int value[12]);
    int   getDependencyChecksInitStepUpdates(int index) const;
    void   setDependencyChecksInitStepUpdates(int index, int value);
#endif
#if PeanoDebug > 0
    const int*   getDependencyChecksInitStepMaskOuts() const;
    void   setDependencyChecksInitStepMaskOuts(const int value[12]);
    int   getDependencyChecksInitStepMaskOuts(int index) const;
    void   setDependencyChecksInitStepMaskOuts(int index, int value);
#endif
    HydroPart(const HydroPart& copy);


    #ifdef Parallel
    /**
     * Hands out MPI datatype if we work without the LLVM MPI extension.
     * If we work with this additional feature, this is the routine where
     * the lazy initialisation is done and the datatype is also cached.
     */
    [[clang::map_mpi_datatype]]
    static MPI_Datatype  getForkDatatype();

    [[clang::map_mpi_datatype]]
    static MPI_Datatype  getJoinDatatype();

    [[clang::map_mpi_datatype]]
    static MPI_Datatype  getBoundaryExchangeDatatype();

    [[clang::map_mpi_datatype]]
    static MPI_Datatype  getMultiscaleDataExchangeDatatype();

    [[clang::map_mpi_datatype]]
    static MPI_Datatype  getGlobalCommunciationDatatype();

    [[clang::map_mpi_datatype]]
    static void  freeForkDatatype();

    [[clang::map_mpi_datatype]]
    static void  freeJoinDatatype();

    [[clang::map_mpi_datatype]]
    static void  freeBoundaryExchangeDatatype();

    [[clang::map_mpi_datatype]]
    static void  freeMultiscaleDataExchangeDatatype();

    [[clang::map_mpi_datatype]]
    static void  freeGlobalCommunciationDatatype();

    /**
     * @return The rank of the sender of an object. It only make ssense to call
     *         this routine after you've invoked receive with MPI_ANY_SOURCE.
     */
    int getSenderRank() const;

    /**
     * Wrapper around getDatatype() to trigger lazy evaluation if we
     * use the lazy initialisation.
     */
    static void initDatatype();

    /**
     * Free the underlying MPI datatype.
     */
    static void shutdownDatatype();

    /**
     * In DaStGen (the first version), I had a non-static version of the send
     * as well as the receive. However, this did not work with newer C++11
     * versions, as a member function using this as pointer usually doesn't
     * see the vtable while the init sees the object from outside, i.e.
     * including a vtable. So this routine now is basically an alias for a
     * blocking MPI_Send.
     */
    static void send(const tests::swift2::testSML1D::globaldata::HydroPart& buffer, int destination, int tag, MPI_Comm communicator );
    static void receive(tests::swift2::testSML1D::globaldata::HydroPart& buffer, int source, int tag, MPI_Comm communicator );

    /**
     * Alternative to the other send() where I trigger a non-blocking send an
     * then invoke the functor until the corresponding MPI_Test tells me that
     * the message went through. In systems with heavy MPI usage, this can
     * help to avoid deadlocks.
     */
    static void send(const tests::swift2::testSML1D::globaldata::HydroPart& buffer, int destination, int tag, std::function<void()> startCommunicationFunctor, std::function<void()> waitFunctor, MPI_Comm communicator );
    static void receive(   tests::swift2::testSML1D::globaldata::HydroPart& buffer, int source,      int tag, std::function<void()> startCommunicationFunctor, std::function<void()> waitFunctor, MPI_Comm communicator );
    #endif


    enum ObjectConstruction {
      NoData
    };

    HydroPart( ObjectConstruction ):
        HydroPart() {}

#ifdef Parallel
    static void sendAndPollDanglingMessages(const tests::swift2::testSML1D::globaldata::HydroPart& message, int destination, int tag, MPI_Comm communicator=tarch::mpi::Rank::getInstance().getCommunicator());
    static void receiveAndPollDanglingMessages(tests::swift2::testSML1D::globaldata::HydroPart& message, int source, int tag, MPI_Comm communicator=tarch::mpi::Rank::getInstance().getCommunicator() );
#endif


  static ::swift2::ParticleSpecies& getSpecies();


    std::string toString() const;

    // Changed these variables to non-const so I can modify it on-the-fly.
    static double   _hydroDimensions;
    static double   _etaFactor;
    static double   _smlMin;
    static double   _smlMax;
    static double   _smlTolerance;
    static int   _smlMaxIterations;

  private:
#if PeanoDebug>0
    tarch::la::Vector<Dimensions,double>   _debugX;
#endif
#if PeanoDebug>0
    tarch::la::Vector<Dimensions,double>   _debugH;
#endif
    tarch::la::Vector<Dimensions,double>   _x;
    tarch::la::Vector<Dimensions,double>   _cellH;
      double   _searchRadius;
#if PeanoDebug > 0
      int   _partid = -1;
#endif
    [[clang::pack]]  ParallelState   _ParallelState;
    [[clang::pack]]  MoveState   _MoveState;
    [[clang::pack]]  bool   _CellHasUpdatedParticle;
      double   _mass;
    tarch::la::Vector<Dimensions,double>   _v;
    tarch::la::Vector<Dimensions,double>   _a;
      double   _density;
      double   _pressure;
      double   _smoothingLength = 0.0;
      double   _u;
      double   _uDot;
    tarch::la::Vector<Dimensions,double>   _v_full;
      double   _u_full;
      double   _wcount;
      double   _wcount_dh;
      double   _f;
      double   _hDot;
      double   _rho_dh;
      int   _smoothingLengthIterCount;
      double   _smlIterLeftBound;
      double   _smlIterRightBound;
    [[clang::pack]]  bool   _hasNoNeighbours;
    [[clang::pack]]  bool   _smoothingLengthConverged = false;
#if PeanoDebug > 0
      int   _densityNeighbourCount;
#endif
#if PeanoDebug > 0
      int   _forceNeighbourCount;
#endif
      inline const static double   _cfl = 1e-06;
      inline const static double   _initialTimeStepSize = 1e-06;
      inline const static bool   _adjustTimeStepSize = false;
      inline const static double   _alphaAV = 0.8;
      inline const static double   _betaAV = 3.0;

      double   _balsara;
#if Dimensions < 3
      double   _rot_v;
#else
    tarch::la::Vector<Dimensions,double>   _rot_v;
#endif
      double   _div_v;
      double   _v_sig_AV;
      double   _soundSpeed;
#if PeanoDebug > 0
    [[clang::pack]]  DependencyChecksPeanoEventUsedBySwift   _dependencyChecksPeanoEventUsedBySwift;
#endif
#if PeanoDebug > 0
    [[clang::pack]]  DependencyChecksAlgorithmStepLastUpdated   _dependencyChecksAlgorithmStepLastUpdated;
#endif
#if PeanoDebug > 0
      int   _dependencyChecksAlgorithmStepUpdates[24];
#endif
#if PeanoDebug > 0
      int   _dependencyChecksAlgorithmStepMaskOuts[24];
#endif
#if PeanoDebug > 0
    [[clang::pack]]  DependencyChecksInitStepLastUpdated   _dependencyChecksInitStepLastUpdated;
#endif
#if PeanoDebug > 0
      int   _dependencyChecksInitStepUpdates[12];
#endif
#if PeanoDebug > 0
      int   _dependencyChecksInitStepMaskOuts[12];
#endif



    #ifdef Parallel
    private:
      int                  _senderDestinationRank;

      #if !defined(__MPI_ATTRIBUTES_LANGUAGE_EXTENSION__)
      /**
       * Whenever we use LLVM's MPI extension (DaStGe), we rely on lazy
       * initialisation of the datatype. However, Peano calls init explicitly
       * in most cases. Without the LLVM extension which caches the MPI
       * datatype once constructed, this field stores the type.
       */
      static MPI_Datatype  Datatype;
      #endif
    #endif




};



