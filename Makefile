PEANO_ROOT=/home/mivkov/Durham/Peano/src

OPTFLAGS = -Og -g 			# debug
WFLAGS=   -Wall -Wextra -pedantic -Wno-gcc-compat -Wno-unused-command-line-argument -Wno-unused-parameter 
WFLAGS+=  -Wno-tautological-constant-compare  -Wno-ignored-attributes  -Wno-unknown-attributes  
WFLAGS+=  -Wno-zero-length-array -Wno-mismatched-tags -Wno-unused
STDFLAGS= -std=c++20


INCLUDES=-I/$(PEANO_ROOT)
INCLUDES+=-I/$(PEANO_ROOT)/


LDFLAGS=-L/$(PEANO_ROOT)
LDFLAGS += -L/home/mivkov/Durham/Peano/src  -L/home/mivkov/Durham/Peano/src/toolbox/loadbalancing  -L/home/mivkov/Durham/Peano/src/toolbox/blockstructured  -L/home/mivkov/Durham/Peano/src/toolbox/particles  -L/home/mivkov/Durham/Peano/src/swift2 -L//home/mivkov/local/spack/opt/spack/linux-ubuntu22.04-icelake/oneapi-2024.0.2/hdf5-1.12.2-nwvya6efp6jrgreywa6g2h4vcy7ygqct/lib -qopenmp

LIBS= -lm
LIBS += -L../../../../src -lSWIFT2Core2d_asserts  -lToolboxBlockstructured2d_asserts  -lToolboxLoadBalancing2d_asserts  -lPeano4Core2d_asserts -lTarch_asserts   -lToolboxParticles2d_asserts  -lToolboxBlockstructured2d_asserts  -lToolboxLoadBalancing2d_asserts  -lPeano4Core2d_asserts -lTarch_asserts -lhdf5_hl_cpp -lhdf5_cpp -lhdf5_hl -lhdf5 -lstdc++

HEADERS=myconfig.h ICUniform1D.h ICDisplaced1D.h ./ICMultilevelDisplaced1D.h ./ICUniform2D.h hydroPart.h smlUnitTest.h
OBJECTS=

DEF1D=-DHYDRO_DIMENSION=1 -DDimensions=2
DEF2D=-DHYDRO_DIMENSION=2 -DDimensions=2
DEF3D=-DHYDRO_DIMENSION=3 -DDimensions=3

CXXFLAGS= $(OPTFLAGS) $(WFLAGS) $(FFLAGS) $(STDFLAGS)  $(INCLUDES) $(LDFLAGS) $(LIBS) 

# ---------------------------------------------------------
# ---------------------------------------------------------


default: test1D test2D


hydroPart1D.o: hydroPart.cpp hydroPart.h
	$(CXX) $(CXXFLAGS) $(DEF1D) -c $< -o $@

hydroPart2D.o: hydroPart.cpp hydroPart.h
	$(CXX) $(CXXFLAGS) $(DEF2D) -c $< -o $@

test1D: test1D.cpp $(HEADERS) $(OBJECTS) hydroPart1D.o
	$(CXX) $(OBJECTS) $(DEF1D) hydroPart1D.o $(CXXFLAGS) $< -o $@

test2D: test2D.cpp $(HEADERS) $(OBJECTS) hydroPart2D.o
	$(CXX) $(OBJECTS) $(DEF2D) hydroPart2D.o $(CXXFLAGS) $< -o $@

clean:
	rm -f *.o test1D test2D
