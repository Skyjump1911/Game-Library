/**
 * @file library.h
 * @author Noah Melton and Sam Toney
 * @date 2025-03-31
 * @brief This is the .h file for the library class, where we define but don't provide implementation for the library class's functions. 
 * 
 * Contains library class for use in the Game Library Program.
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include "game.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>


/**
 * A library class for processing game data.
 *
 * @class library library.h "Game-Library/library.h"
 * @brief Holds the games list and methods for use in the Game Library Program.
 *
 */
class library {

 public:

  // List of game objects used to represent a game library
  std::list<game> games;
  
  // constructor
  library();

  // destructor
  // ~library();


/**
 * Writes game data to a file.
 *
 * @param const std::string& filename File to be opened and written to.
 * @pre 
 * @return void 
 * @post Game data has been properly written to the specified file.
 * 
 */
  void write_to_file(const std::string& filename);


/**
 * Reads game data from a file.
 *
 * @param std::string filename File containing data to be read.
 * @pre filename contains a valid file name.
 * @return void 
 * @post Game data has been properly read from the specified file.
 * 
 */
  void read_from_file(std::string filename); 


/**
 * Inserts a game into the library, sorted alphabetically by game title.
 *
 * @param const std::string& title Name of game title to be added to the library.
 * @pre 
 * @return void 
 * @post Specified game has been properly added to the library in the correct order.
 * 
 */
  void insert_sorted(const std::string& title);


/**
 * Searches library for a game by genre.
 *
 * @param const std::string& genre The type of genre to be searched for.
 * @pre 
 * @return void 
 * @post The specified game(s) has been found.
 * 
 */
  void find_genre(const std::string& genre);


/**
 * Searches for a game by title.
 *
 * @param const std::string& title The game title to be searched for.
 * @pre 
 * @return void 
 * @post The specified game has been found.
 * 
 */
  void find_game(const std::string& title);


/**
 * Deletes a specified game from the library.
 *
 * @param std::string title The title of the game to be removed.
 * @param int year The release year of the game to be removed.
 * @pre 
 * @return bool Returns true if the game was deleted, and false if not.
 * @post The specified game was found and deleted.
 * 
 */
  bool Delete(std::string title, int year);


/**
 * Prints game data from a file.
 *
 * @pre 
 * @return void 
 * @post The game data was properly read and printed.
 * 
 */
  void print(); 


/**
 * Displays menu options for the program.
 *
 * @pre 
 * @return void 
 * @post Menu was properly printed to console.
 * 
 */
  void displayMenu();
 
  void extra();

  void add();
  
  void subtract(); 
  
};
#endif
