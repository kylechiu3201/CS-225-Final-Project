EXENAME = airports
OBJS = main.o airport.o airports.o graph.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libstdc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libstdc++ -lc++abi -lm





# Custom Clang version enforcement Makefile rule:
	ccred=$(shell echo -e "\033[0;31m")
	ccyellow=$(shell echo -e "\033[0;33m")
	ccend=$(shell echo -e "\033[0m")

IS_EWS=$(shell hostname | grep "ews.illinois.edu")
IS_CORRECT_CLANG=$(shell clang -v 2>&1 | grep "version 6")
ifneq ($(strip $(IS_EWS)),)
	ifeq ($(strip $(IS_CORRECT_CLANG)),)
	CLANG_VERSION_MSG = $(error $(ccred) On EWS, please run 'module load llvm/6.0.1' first when running CS225 assignments. $(ccend))
endif
else
	CLANG_VERSION_MSG = $(warning $(ccyellow) Looks like you are not on EWS. Be sure to test on EWS before the deadline. $(ccend))
endif





all : $(EXENAME)

$(EXENAME) : output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp airports.h
	$(CXX) $(CXXFLAGS) main.cpp

airport.o : airport.cpp airport.h
	$(CXX) $(CXXFLAGS) airport.cpp

airports.o : airports.cpp airports.h airport.h graph.h edge.h
	$(CXX) $(CXXFLAGS) airports.cpp

graph.o : graph.cpp graph.h edge.h airport.h
	$(CXX) $(CXXFLAGS) graph.cpp
	
clean :
	-rm -f *.o $(EXENAME) airports



output_msg: ; $(CLANG_VERSION_MSG)

# Be sure to add output_msg as dependency target for your `intro` binary

# test: output_msg tests.o PNG.o HSLAPixel.o lodepng.o intro.o
# 	$(LD) tests.o PNG.o HSLAPixel.o lodepng.o intro.o $(LDFLAGS) -o test

# tests.o: tests/tests.cpp tests/catch.hpp cs225/PNG.h cs225/HSLAPixel.h
# 	$(CXX) $(CXXFLAGS) tests/tests.cpp

.PHONY: output_msg
