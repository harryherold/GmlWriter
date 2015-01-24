#
# Makefile
#
#  Created on: 24 Jan 2015
#      Author: Christian Herold
CXX = clang++

INCLUDE = -I./src/

SOURCES = ./test/test.cpp

CXXFLAGS = -Wall -g3 -O0 -std=c++11

TESTBIN = ./test/bin/test-gw

$(TESTBIN): $(SOURCES:%.cpp=%.o)
	mkdir -p ./test/bin
	$(CXX) $(INCLUDE) -o $@ $< 

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $(INCLUDE) -o $@ $<
	
clean:
	rm ./test/*.o
	rm -rf ./test/bin

test: $(TESTBIN)
	$(TESTBIN)
	