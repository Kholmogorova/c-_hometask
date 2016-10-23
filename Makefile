CXX=g++

CXXFLAGS=-std=c++11 -O0 -g

all: main.out

main.out: main.cpp matrix_class.o Matrix.h
	$(CXX) $< -o $@ $(CXXFLAGS) 

matrix_class.o: matrix_class.cpp Matrix.h
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm *.o
	rm *.out
