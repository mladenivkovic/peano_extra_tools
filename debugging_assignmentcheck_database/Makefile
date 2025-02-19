PEANO_ROOT=/home/mivkov/Durham/Peano/src

CXX = /home/mivkov/software/spack/opt/spack/linux-manjaro25-icelake/gcc-14.2.1/intel-oneapi-compilers-2025.0.0-t7hlf6ekexsd7uvpxsr33orr7wnbewzp/compiler/2025.0/bin/icpx

OPTFLAGS = -Og -g 			# debug
# OPTFLAGS += -fsanitize=address
WFLAGS=   -Wall -Wextra -pedantic -Wno-gcc-compat -Wno-unused-command-line-argument -Wno-unused-parameter 
WFLAGS+=  -Wno-tautological-constant-compare  -Wno-ignored-attributes  -Wno-unknown-attributes  
WFLAGS+=  -Wno-zero-length-array -Wno-mismatched-tags -Wno-unused
STDFLAGS= -std=c++20


INCLUDES=-I/$(PEANO_ROOT)
INCLUDES+=-I/$(PEANO_ROOT)/


# LDFLAGS=-L/$(PEANO_ROOT)
LDFLAGS += -L/home/mivkov/Durham/Peano/src  -L/home/mivkov/Durham/Peano/src/toolbox/loadbalancing  -L/home/mivkov/Durham/Peano/src/toolbox/blockstructured  -L/home/mivkov/Durham/Peano/src/toolbox/particles  -L/home/mivkov/Durham/Peano/src/swift2 -L/$(HDF5_ROOT)/lib -fopenmp
LDFLAGS += -L/home/mivkov/Durham/Peano/src/tarch
LDFLAGS += -L/home/mivkov/Durham/Peano/src/tarch/la

LIBS= -lm -lhdf5_hl_cpp -lhdf5_cpp -lhdf5_hl -lhdf5 -lstdc++
LIBS += -L/$(PEANO_ROOT) -lSWIFT2Core2d_debug  -lToolboxBlockstructured2d_debug  -lToolboxLoadBalancing2d_debug  -lPeano4Core2d_debug -lTarch_debug   -lToolboxParticles2d_debug  -lToolboxBlockstructured2d_debug  -lToolboxLoadBalancing2d_debug  -lPeano4Core2d_debug -lTarch_debug

HEADERS=myconfig.h InitialConditions.h InitialConditions1D.h InitialConditions2D.h InitialConditions3D.h HydroPart.h smlUnitTest.h
OBJECTS=

DEF1D=-DHYDRO_DIMENSION=1 -DDimensions=2
DEF2D=-DHYDRO_DIMENSION=2 -DDimensions=2
DEF3D=-DHYDRO_DIMENSION=3 -DDimensions=3

CXXFLAGS= $(OPTFLAGS) $(WFLAGS) $(FFLAGS) $(STDFLAGS)  $(INCLUDES) $(LDFLAGS) $(LIBS) 

# ---------------------------------------------------------
# ---------------------------------------------------------


default: run.o


run.o: main.cpp IO.h
	$(CXX) $(DEF2D) $< -o $@ $(CXXFLAGS) 

clean:
	rm -f *.o 
