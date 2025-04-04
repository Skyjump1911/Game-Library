/**
 * @file library.cpp
 * @author Noah Melton
 * @date 2025-04-01
 * @brief This is the implementation of the library class
 * 
 * This is where we filled in the details for the library class's functions. 
 */


#include "library.h"
#include "game.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>

using namespace std; 

//default constructor
library::library() {


  games = list<game>(); 
  


}


//destructor
//library::~library();


void library::read_from_file(const std::string& filename) {

  ifstream file;
  file.open(filename);

  string title, publisher, genre;
  float hours_played = 0;
  float price = 0;
  int year = 0; 
  game tempEntry; 
   string trash1, trash2;
  getline(file, tempEntry.title);
  // getline(file, trash1); 
  getline(file, tempEntry.publisher);
  // getline(file, trash2); 

  file >> genre >> hours_played >> price >> year;

  tempEntry.genre = genre; 
  tempEntry.hours_played = hours_played;
  tempEntry.price = price;
  tempEntry.year = year;
  

  games.push_back(tempEntry);
  
  while(file) {
  
  getline(file, tempEntry.title);
  // getline(file, trash1);
  getline(file, tempEntry.publisher);
  getline(file, trash2); 

  file >> genre >> hours_played >> price >> year;

  tempEntry.genre = genre; 
  tempEntry.hours_played = hours_played; 
  tempEntry.price = price;
  tempEntry.year = year; 

  games.push_back(tempEntry); 

  }

}


void library::write_to_file(const std::string& filename) {

  list<game> test = {{"Title", "Publisher","genre", 33.3, 22.2, 2019}, {"title", "publisher", "Genre",  32.2, 1.2, 2008}};


    ofstream file;
  file.open(filename);

  for(list<game>::iterator it = test.begin(); it != test.end(); it++) {

    file << it->title << endl;
    file << it->publisher << endl;
    file << it->genre << " " << it->hours_played << " " <<  it->price << " " << it->year << endl;  



  }


}



/**
void library::find_game(const std::string& title);

void library::find_genre(const std::string& genre);
 
**/

bool library::Delete(std::string title, int year) {

  // Check if the list contains any elements
  if (head == NULL) {
    std::cout << "Your game library is empty\n";
    return false;
  }

  return true;
}


void library::print() {


  
  string filename;

  cout << "enter a file name";
  cin >> filename;
  
  read_from_file(filename);


  cout << "it got done with reading the file";

  
  for(list<game>::iterator it = games.begin(); it != games.end(); it++) {

    cout << it->title << endl;
    cout << it->publisher << endl;
    cout << it->genre << " " << it->hours_played << " " <<  it->price << " " << it->year << endl;  



  }
}

void library::displayMenu() {

  cout << "Game Library Program loaded...\n\n";
  cout << "Please select one of the following options:\n";
  cout << "============================================\n";
  cout << "1 - Read from file\n";
  cout << "2 - Write to file\n";
  cout << "3 - Delete entry\n";
  cout << "4 - Print file\n";
  cout << "5 - Exit Program\n"; 
  
}
