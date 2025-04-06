/**
 * @file library.cpp
 * @author Noah Melton and Sam Toney
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
//library::~

void library::read_from_file(string filename) {

  game tempEntry;

  string line1, line2, line3;
  
  ifstream file;
  file.open(filename);

  // Check if file was opened
  if (!file) {
    cout << "ERROR: Could not open file...\n";
    return;
  }

  // Get data from file
  while(getline(file, line1) && getline(file, line2) && getline(file, line3)) {
    
    tempEntry.title = line1;
    tempEntry.publisher = line2;

    stringstream ss(line3);
    ss >> tempEntry.genre >> tempEntry.hours_played >> tempEntry.price >> tempEntry.year;

    // Add entry
    games.push_back(tempEntry);
  }

  file.close();

  cout << "Loaded " << games.size() << " games from file.\n";
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

void library::insert_sorted(const std::string &title) {

  game gameObject;
  
  gameObject.title = title;
  
  // initialize iterator for loop
  auto it = games.begin();

  while (it != games.end() && it->title < gameObject.title) {
    it++;
  }

  games.insert(it, gameObject);
}



void library::find_game(const std::string& title) {

  // Check if library is empty
  if (games.empty()) {
    cout << "ERROR: Library is empty...\n\n";
  }

  // Go through list and print matching information
  for (list<game>::iterator i = games.begin(); i != games.end(); i++) {

    if (i->title == title) {
      cout << "Game found...\n\n";
      cout << "Game Title: " << i->title << endl;
      cout << "Game Publisher: " << i->publisher << endl;
      cout << "Hours Played: " << i->hours_played << endl;
      cout << "Price: $" << i->price << endl;
      cout << "Release Year: " << i->year << endl;
    }
  }  
}

void library::find_genre(const std::string& genre) {

 for(list<game>::iterator it = games.begin(); it != games.end(); it++) {         

   if(it->genre == genre) {

     cout << "Game Title: " << it->title << endl;
     cout << "Game Publisher: " << it->publisher << endl;
     cout << "Hours Played: " << it->hours_played << endl;
     cout << "Price: $" << it->price << endl;
     cout << "Release Year: " << it->year << endl;
   }
 }
}


bool library::Delete(std::string title, int year) {

  // Check if library is empty
  if (games.empty()) {
    std::cout << "ERROR: Library is empty...\n\n";
    return false;
  }

  // Check current size of library
  unsigned int initialSize = games.size();

  // Go through list and remove entries that match desired game
  games.remove_if([&title, year](const game& game) {
    return game.title == title && game.year == year;
  });

  // If an entry has been removed return true
  if (games.size() < initialSize) {
    cout << title << " removed successfully...\n";
    return true;
  }

  return false;
}


void library::print() {

  string filename;

  cout << "enter a file name";
  cin >> filename;
  
  read_from_file(filename);

  for(list<game>::iterator it = games.begin(); it != games.end(); it++) {

    cout << it->title << endl;
    cout << it->publisher << endl;
    cout << it->genre << " " << it->hours_played << " " <<  it->price << " " << it->year << endl;
    cout << endl; 
  }
}

  
void library::displayMenu() {

  cout << endl;
  cout << "Please select one of the following options:\n";
  cout << "===========================================\n";
  cout << "1 - Read from file\n";
  cout << "2 - Write to file\n";
  cout << "3 - Add game\n";
  cout << "4 - Add game (test)\n";
  cout << "5 - Delete entry\n";
  cout << "6 - Print library\n";
  cout << "7 - Find game\n";
  cout << "8 - Add Game (Sorted)\n";
  cout << "9 - Exit Program\n\n";
  cout << "Please enter desired option: ";
  
}

void library::add() {


  game temp;
  

  string T;
  string P;
  string G;
  float h;
  float p;
  int y;

 
    cout << "Enter the game's title: ";
    cin >> T;
    cout << "Enter the game's publisher: ";
    cin >> P;
    cout << "Enter the game's genre: ";
    cin >> G;
    cout << "Enter how many hours you have spent playing the game: ";
    cin >> h;
    cout << "Enter the game's price: ";
    cin >> p;
    cout << "Enter the game's release year: ";
    cin >> y;

    temp.title = T;
    temp.publisher = P;
    temp.genre = G;
    temp.hours_played = h;
    temp.price = p;
    temp.year = y;

    games.push_back(temp); 




}



/**
 * This funciton allows us to delete game entries
 *
 * @pre Game entries must already exist if we want to be able to delete them. 
 * @return void No return type, just prints out what is left after deletion. 
 * @post The list is now one specified game shorter
 * 
 */
void library::subtract() {

  string remTitle;
  cout << "Enter the title of the game you want to remove from the library: " <<endl;
  cin >> remTitle;

  /**
  I was able to use most of this logic from other parts of the code that I had
  done already, but since I was not used to how iterators worked, I didn't know why I couldn't use the "games.erase(it)" just like that. So, I found a useful
YouTube video by "Bo Quian" which talked about how to remove elements from an STL list. That is where I learned that I could delete using games.erase(it++). 

   **/
  
  for(list<game>::iterator it = games.begin(); it != games.end();) {


    if(it->title == remTitle) {

      games.erase (it++);
      cout << "possibly worked" << endl; 

    } else{
      it++;
    }

  }



}

void library::extra() {


  for(list<game>::iterator it = games.begin(); it != games.end(); it++) {

    cout << "the game titles: " << endl;
    cout << it->title << endl;




  }

}
