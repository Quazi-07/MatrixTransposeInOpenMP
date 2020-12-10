CXX = g++

CXXFLAGS = -std=c++14 -O2 -fopenmp 
###CXXFLAGS = -std=c++11 -O0 -fopenmp 

all: hw3.o
	@echo hw3 has been compiled

hw3.o: hw3.cpp
	$(CXX) $(CXXFLAGS) -o hw3.o hw3.cpp

clean:
	rm -f hw3 hw3.o *.o
