#
# Makefile
#
#  Created on: 24 Jan 2015
#      Author: Christian Herold
CXX     = clang++
AR      = ar
ARFLAGS = rcs
INCLUDE = -I./include
LIBNAME = GmlWriter 
LIBSRC  = ./src/gml_writer.cpp
LIBS    = -L./lib/ -l$(LIBNAME) 
SOURCES = ./test/test.cpp
CXXFLAGS = -Wall -g3 -O0 -std=c++11 -static
TESTBIN = ./test/bin/test-gw

all: libGmlWriter.a $(TESTBIN)
.PHONY : all

libGmlWriter.a: $(LIBSRC:%.cpp=%.o)
	mkdir -p ./lib
	$(AR) $(ARFLAGS) ./lib/$@ $<
	
$(TESTBIN): $(SOURCES:%.cpp=%.o)
	mkdir -p ./test/bin
	$(CXX) $(INCLUDE) -o $@ $< $(LIBS)

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $(INCLUDE) -o $@ $<

.PHONY: clean
	
clean:
	rm ./test/*.o
	rm ./test/*.gml
	rm ./src/*.o
	rm -rf ./test/bin
	rm -rf ./lib
	