CC= g++  	

# include debugging symbols in object files,
# and enable all warnings
CXXFLAGS= -g -Wall -std=c++11

#include debugging symbols in executable
LDFLAGS= -g	

default: main

main: main.o
	g++ -o main main.o

main.o: myHashMap.hpp myType.hpp

clean:
	$(RM) main *.o
