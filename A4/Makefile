# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++20 -g -O3
PROGRAMS = travelers
CPP = main.cpp ascii_art.cpp

# Targets and Dependencies
all: $(PROGRAMS) 

remake: clean travelers run

travelers:
	$(CXX) $(CXXFLAGS) $(CPP) -o $(PROGRAMS)

run:
	./$(PROGRAMS)

clean:
	rm -f $(PROGRAMS) *.o
	rm -rf travelers.dSYM
