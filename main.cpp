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


  string filename; 
  
  library test;    


  int userInput;

  do {

    test.displayMenu();

    cin >> userInput;

    switch(userInput) {

    case 1: // Read from file
      
      cout << "Please enter your file name: ";
      cin >> filename;
      test.read_from_file(filename); 

      break;

    case 2: // Write to file

      // test.write_to_file(fileName);

      break;

    case 3: // Add a game

      test.add();
      
      break;

    case 4: // testing our ability to add games
      
      test.extra();
      
      break;

    case 5: // Exit program

      cout << "Program has been exited...\n";

    }

  } while (userInput != 5);
  
 

   
    return 0;
}
