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

  //constructor
  library();

  //destructor
  ~library();


  //methods
  void push_front(std::string title, std::string publisher, std::string genre, float hours_played, float price, int year);

  void push_back(std::string title, std::string publisher, std::string genre, 
float hours_played, float price, int year);      

  void write_to_file(const std::string& filename);

  void read_from_file(const std::string& filename); 

  void insert_sorted(const std::string& title);

  void find_genre(const std::string& genre);

  void find_game(const std::string& title);

  void delete(std::string title, int year);

  void print(); 
  
private:

  game *head;
  game *tail;
  game *n; 

  
}





#endif
