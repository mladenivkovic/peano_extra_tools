PEANO_ROOT=/home/mivkov/Durham/Peano/src

CXX = /home/mivkov/local/spack/opt/spack/linux-ubuntu24.04-icelake/gcc-14.0.1/intel-oneapi-compilers-2024.2.1-ysaj6erxyjcz2c3mvqd6pv2eyt3b3suu/compiler/2024.2/bin/icpx

OPTFLAGS = -Og -g 			# debug
# OPTFLAGS += -fsanitize=address
WFLAGS=   -Wall -Wextra -pedantic -Wno-gcc-compat -Wno-unused-command-line-argument -Wno-unused-parameter 
WFLAGS+=  -Wno-tautological-constant-compare  -Wno-ignored-attributes  -Wno-unknown-attributes  
WFLAGS+=  -Wno-zero-length-array -Wno-mismatched-tags -Wno-unused
STDFLAGS= -std=c++20


INCLUDES=-I/$(PEANO_ROOT)
INCLUDES+=-I/$(PEANO_ROOT)/


# LDFLAGS=-L/$(PEANO_ROOT)
LDFLAGS += -L/home/mivkov/Durham/Peano/src  -L/home/mivkov/Durham/Peano/src/toolbox/loadbalancing  -L/home/mivkov/Durham/Peano/src/toolbox/blockstructured  -L/home/mivkov/Durham/Peano/src/toolbox/particles  -L/home/mivkov/Durham/Peano/src/swift2 -L//home/mivkov/local/spack/opt/spack/linux-ubuntu24.04-icelake/oneapi-2024.2.1/hdf5-1.14.3-pu54c7mxajmoxbye2gqeiah2vg4huaqq/lib -qopenmp
LDFLAGS += -L/home/mivkov/Durham/Peano/src/tarch
LDFLAGS += -L/home/mivkov/Durham/Peano/src/tarch/la

LIBS= -lm -lhdf5_hl_cpp -lhdf5_cpp -lhdf5_hl -lhdf5 -lstdc++
LIBS += -L/$(PEANO_ROOT) -lSWIFT2Core2d_asserts  -lToolboxBlockstructured2d_asserts  -lToolboxLoadBalancing2d_asserts  -lPeano4Core2d_asserts -lTarch_asserts   -lToolboxParticles2d_asserts  -lToolboxBlockstructured2d_asserts  -lToolboxLoadBalancing2d_asserts  -lPeano4Core2d_asserts -lTarch_asserts

HEADERS=myconfig.h InitialConditions.h InitialConditions1D.h InitialConditions2D.h InitialConditions3D.h HydroPart.h smlUnitTest.h
OBJECTS=

DEF1D=-DHYDRO_DIMENSION=1 -DDimensions=2
DEF2D=-DHYDRO_DIMENSION=2 -DDimensions=2
DEF3D=-DHYDRO_DIMENSION=3 -DDimensions=3

CXXFLAGS= $(OPTFLAGS) $(WFLAGS) $(FFLAGS) $(STDFLAGS)  $(INCLUDES) $(LDFLAGS) $(LIBS) 

# ---------------------------------------------------------
# ---------------------------------------------------------


default: test1D 
# default: test1D test2D test3D


HydroPart1D.o: HydroPart.cpp HydroPart.h
	$(CXX) $(DEF1D) -c $< -o $@  $(CXXFLAGS) 

HydroPart2D.o: HydroPart.cpp HydroPart.h
	$(CXX) $(DEF2D) -c $< -o $@ $(CXXFLAGS) 

HydroPart3D.o: HydroPart.cpp HydroPart.h
	$(CXX) $(DEF3D) -c $< -o $@ $(CXXFLAGS) 



InitialConditions1D.o: InitialConditions1D.cpp InitialConditions1D.h InitialConditions.h
	$(CXX) $(DEF1D) -c $< -o $@ $(CXXFLAGS) 

InitialConditions2D.o: InitialConditions2D.cpp InitialConditions2D.h InitialConditions.h
	$(CXX) $(DEF2D) -c $< -o $@ $(CXXFLAGS) 

InitialConditions3D.o: InitialConditions3D.cpp InitialConditions3D.h InitialConditions.h
	$(CXX) $(DEF3D) -c $< -o $@ $(CXXFLAGS) 


smlUnitTest1D.o: smlUnitTest.cpp smlUnitTest.h
	$(CXX) $(DEF1D) -c $< -o $@ $(CXXFLAGS) 

smlUnitTest2D.o: smlUnitTest.cpp smlUnitTest.h
	$(CXX) $(DEF2D) -c $< -o $@ $(CXXFLAGS) 

smlUnitTest3D.o: smlUnitTest.cpp smlUnitTest.h
	$(CXX) $(DEF3D) -c $< -o $@ $(CXXFLAGS) 


test1D: test1D.cpp $(HEADERS) $(OBJECTS) HydroPart1D.o InitialConditions1D.o smlUnitTest1D.o
	$(CXX) $(OBJECTS) $(DEF1D) HydroPart1D.o InitialConditions1D.o smlUnitTest1D.o $< -o $@ $(CXXFLAGS)

test2D: test2D.cpp $(HEADERS) $(OBJECTS) HydroPart2D.o InitialConditions2D.o smlUnitTest2D.o
	$(CXX) $(OBJECTS) $(DEF2D) HydroPart2D.o InitialConditions2D.o smlUnitTest2D.o $< -o $@ $(CXXFLAGS) 

test3D: test3D.cpp $(HEADERS) $(OBJECTS) HydroPart3D.o InitialConditions3D.o smlUnitTest3D.o
	$(CXX) $(OBJECTS) $(DEF3D) HydroPart3D.o InitialConditions3D.o smlUnitTest3D.o $< -o $@ $(CXXFLAGS) 



clean:
	rm -f *.o test1D test2D test3D
