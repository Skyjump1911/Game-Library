/**
 * @file library.h
 * @author Noah Melton
 * @date 2025-03-31
 * @brief This is the .h file for the library class, where we define but don't provide implementation for the library class's functions. 
 * 
 * I worked on this alongside Sam Toney
 */


#include "game.h"

#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>


class library {

 public:

  std::list<game> games; 
  //constructor
  library();

  //destructor
  //  ~library();


  //methods      

  void write_to_file(const std::string& filename);

  void read_from_file(const std::string& filename); 

  void insert_sorted(const std::string& title);

  void find_genre(const std::string& genre);

  void find_game(const std::string& title);

  bool Delete(std::string title, int year);

  void print();

  void displayMenu();
 

  
};





#endif
