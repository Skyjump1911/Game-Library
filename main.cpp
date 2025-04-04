/**
 * @file main.cpp
 * @author Sam Toney
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
  library system;

  int userInput = 0;
  string fileName = "";

  do {

    system.displayMenu();

    cin >> userInput;

    switch(userInput) {

    case 1: // Read from file
      
      // cout << "enter a file name"; 
      // cin >> fileName;

      break;

    case 2: // Write to file

      // test.write_to_file(fileName);

      break;

    case 3: // Delete entry

      break;

    case 4: // Print file

      test.print();

      break;

    case 5: // Exit program

      cout << "Program has been exited...\n";

    }

  } while (userInput != 5);
  
  
    return 0;
}
