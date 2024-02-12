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

HEADERS=myconfig.h ICUniform1D.h ICDisplaced1D.h hydroPart.h smlUnitTest.h
OBJECTS=hydroPart.o

CXXFLAGS= $(OPTFLAGS) $(WFLAGS) $(FFLAGS) $(STDFLAGS)  $(INCLUDES) $(LDFLAGS) $(LIBS) 

# ---------------------------------------------------------
# ---------------------------------------------------------


default: test


hydroPart.o: hydroPart.cpp hydroPart.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: main.cpp $(HEADERS) $(OBJECTS)
	$(CXX) $(OBJECTS) $(CXXFLAGS) $< -o $@


clean:
	rm -f *.o test
