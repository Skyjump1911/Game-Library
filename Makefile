#
# @file Makefile
# @author Sam Toney
# @date 2025-04-01
# @brief Makefile for game library program.
#
# Used to automate compiling and cleaning up excess files
#

CC = g++
CFLAGS = -g -Wall -Wextra

default: game-library

game-library: main.o library.o 
	$(CC) $(CFLAGS) -o game-library main.o library.o 

library.o: library.cpp library.h
	$(CC) $(CFLAGS) -c library.cpp


main.o: main.cpp library.h game.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) game-library *.o *~
