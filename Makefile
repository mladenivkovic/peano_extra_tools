

OPTFLAGS = 	-Og -g 			# debug
WFLAGS= 	-Wall -Wextra -pedantic  -Wno-gcc-compat  -Wno-tautological-constant-compare  -Wno-ignored-attributes  -Wno-unknown-attributes  
STDFLAGS= 	-std=c++20
CXXFLAGS=      	$(OPTFLAGS) $(WFLAGS) $(FFLAGS) $(STDFLAGS)

LDFLAGS= -lm


OBJECTS=


test: main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@


clean:
	rm -f *.o test
