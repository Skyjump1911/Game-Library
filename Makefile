#Date: 4/19/2025
#Author: Noah Melton and Sam Toney
#Description: This is the makefile for the Game Library assignment
CXX = g++

CXXFLAGS = -Wall -Wextra -g

all:program

program: main.o library.o 
	$(CXX) $(CXXFLAGS) -o program main.o library.o 
main.o: main.cpp library.h game.h
	$(CXX) $(CXXFLAGS) -c main.cpp
library.o: library.cpp library.h game.h
	$(CXX) $(CXXFLAGS) -c library.cpp
clean:
	rm -f *.o~ program
