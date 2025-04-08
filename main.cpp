 /**
 * @file main.cpp
 * @author Sam Toney and Noah Melton
 * @date 2025-04-01
 * @brief Game Library Program
 * 
 * Uses a linked list to organize game data.
 */

#include <iostream>
#include <iomanip>
#include "library.h"
#include "game.h"
#include <string>

using namespace std;

int main () {
  
  library test; 

  int userInput = 0, releaseYear = 0;
  string gameTitle = "", fileName = "";
  

  cout << "Game Library Program Loaded\n\n";
  
  do {

    test.displayMenu();

    cin >> userInput;

    switch(userInput) {

    case 1: // Read from file
      
      cout << "Please enter your file name: ";
      cin.ignore();
      cin >> fileName;
      cout << endl;
      test.read_from_file(fileName); 

      break;

    case 2: // Write to file

      cout << "Please enter your file name: ";
      cin >> fileName;
      test.write_to_file(fileName);

      break;

    case 3: // Add a game

      test.add();
      
      break;

    case 4: // Remove a game 
      
      test.subtract();
      
      break;
    

    case 5: // find the genre and print the games info
      
      test.find_genre(); 
      break;
      
    case 6: // Print library

      test.print();
      
      break;

    case 7: // Find game

      cout << "Enter game title: ";
      cin.ignore();
      getline(cin, gameTitle);
      cout << endl;
      test.find_game(gameTitle);

      break;

    case 8: // Insert sorted

      cout << "Enter game title: ";
      cin.ignore();
      getline(cin, gameTitle);
      cout << endl;
      test.insert_sorted(gameTitle);
      
      break;

    case 9: // Exit program


      test.extra(); 

      break;
      
    }

  } while (userInput != 9); 

   
    return 0;
}
