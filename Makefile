OBJS=main.o afnd.o estado.o alfabeto.o
BINARY=afnd

CXXFLAGS=-g
CXX=g++

all: programa

programa: $(OBJS)
	$(CXX) -o $(BINARY) $(OBJS)

main.o: main.cpp alfabeto.hpp alfabeto.cpp estado.hpp estado.cpp afnd.cpp afnd.hpp

alfabeto.o: alfabeto.cpp alfabeto.hpp

estado.o: estado.cpp estado.hpp

afnd.o: afnd.cpp afnd.hpp estado.cpp estado.hpp alfabeto.cpp alfabeto.hpp

clean:
	rm -r $(BINARY) $(OBJS)
