/**
 * @file library.cpp
 * @author Noah Melton
 * @date 2025-04-01
 * @brief This is the implementation of the library class
 * 
 * This is where we filled in the details for the library class's functions. 
 */


#include "library.h"

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>


//default constructor
library::library() {


  list<game> games;
  


}


//destructor
library::~library();


void library::read_from_file(const std::string& filename) {

  ifstream file;
  file.open(filename);

  string title, publisher, genre;
  float hours_played, price;
  int year; 

  getline(file, title);
  cin.ignore();
  getline(file, publisher);
  cin.ignore();

  file >> genre >> hours_played >> price >> year;

  while(file) {

    games.push_back(title, publisher, genre, hours_played, price, year); 

  }



}


void library::find_game(const std::string& title);

void library::find_genre(const std::string& genre);

void library::delete(std::string title, int year);

void library::print(); 
