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



void library::write_to_file(string filename) {

  game temp;
  
  string Title;
  string Publisher;
  string Genre;
  float Hours;
  float Price;
  int Year;
  
  cout << "Enter the name of the game you wish to add! " << endl;
  cin >> Title;
  cout << "Enter the game's publisher: " << endl;
  cin >> Publisher;
  cout << "Enter the game's genre: " << endl;
  cin >> Genre;
  cout << "Enter how many hours you have played this game: " << endl;
  cin >> Hours;
  cout << "Enter the games price: " << endl;
  cin >> Price;
  cout << "Enter the game's release year: " << endl;
  cin >> Year;

  temp.title = Title;
  temp.publisher = Publisher;
  temp.genre = Genre;
  temp.hours_played = Hours;
  temp.price = Price;
  temp.year = Year;

 
  games.push_back(temp); 
  
  
  ofstream file;
  file.open(filename);

  for(list<game>::iterator it = games.begin(); it != games.end(); it++) {

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

void library::find_genre() {


  string genre;
  cout << "Enter a genre: " << endl;
  cin >> genre;
  
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



void library::print() {

  for(list<game>::iterator it = games.begin(); it != games.end(); it++) {

    cout << it->title << endl;
    cout << it->publisher << endl;
    cout << it->genre << " " << it->hours_played << " " <<  it->price << " " << it->year << endl;
    cout << endl; 
  }
}

  
void library::displayMenu() {


  cout << "      ****     ****  ******  ****      ***  ***   *** " << endl;
  cout << "       ***********    **      ** **    **    **   **  " << endl;
  cout << "       *** *** ***    ****    **   **  **    **   **  " << endl;
  cout << "       ***  *  ***    ****    **    ** **    **   **  " << endl;
  cout << "       ***     ***    **      **     ****    **   **  " << endl;
  cout << "      ****     ****  ******  ***      ***     *****   " << endl;    

  cout << endl;
  cout << "Please select one of the following options:\n";
  cout << "===========================================\n";
  cout << "1 - Read from file\n";
  cout << "2 - Write to file\n";
  cout << "3 - Add game\n";
  cout << "4 - Remove Game (Delete)\n";
  cout << "5 - Display Info by Genre\n";
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





/**
 * I just made this function so I would have a quick way to see if the games were getting added to the linked list right.  
 *
 * @pre N/A
 * @return void N/A
 * @post N/A
 * 
 */
void library::extra() {


  for(list<game>::iterator it = games.begin(); it != games.end(); it++) {

    cout << "the game titles: " << endl;
    cout << it->title << endl;




  }

}
