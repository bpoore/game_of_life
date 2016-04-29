CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors

PROGS := gameOfLife

all: $(PROGS)

gameOfLife: Point.o Grid.o main.cpp
	${CXX} ${CXXFLAGS} Point.o Grid.o main.cpp -o gameOfLife

Point.o: Point.cpp Point.hpp
	${CXX} -c Point.cpp 

Grid.o: Grid.cpp Grid.hpp
	${CXX} -c Grid.cpp

clean:
	rm -f $(PROGS) *.o *~