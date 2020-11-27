// Week 8 Tutorial - Sample code with classes
// Rachel Menzies

// Updates:
// Add Player class
// Add Dice class
// Refactor code to include classes


#include <iostream>
#include <ctime> 
#include <stdlib.h>     /* srand, rand */
#include "classes.cpp"
using namespace std;

// get a random value between min and max values
// used to decide what player goes first
int getRand(int min, int max){
  return rand() % max + min; 
}

////////////////////////////
//      MAIN PROGRAM      //
////////////////////////////

int main() {
 
  // seed the time - see http://www.math.uaa.alaska.edu/~afkjm/csce211/fall2018/handouts/RandomFunctions.pdf for explanation
  srand(time(NULL));

  // used for user input
  string tempString;      // used to move user input to a class
  char input;             // used to confirm 'r' for roll

  // used for logic of turn taking
  int currentPlayer;      // store the current player number

  // create game parameters
  int target;
  cout << "Enter the target number: ";
  cin >> target;

  // create dice with min and max values
  int low,high;
  cout << "Enter the minimum dice value: ";
  cin >> low;
  cout << "Enter the maximum dice value: ";
  cin >> high;
  Dice dice(low, high);

  // create player 1
  Player p1;
  cout << "Enter name for player 1: ";
  cin >> tempString;
  p1.setName(tempString);
  
  // create player 2
  Player p2;
  cout << "Enter name for player 2: ";
  cin >> tempString;
  p2.setName(tempString);
  cout << endl;
  
  // set first player randomly
  currentPlayer = getRand(1, 2);

  // ******************************************
  // get the scoreboard from the file
  // put the values into a data structure for use later
  // ******************************************

  do {
    
    // Get input from user
    if(currentPlayer==1){cout<<p1.getName();}
    else{cout<<p2.getName();}
    cout<<", press 'r' to roll the dice"<< endl;
    cin>>input;

    // if the user inputs correct value
    if(input=='R' || input=='r'){

      // roll the dice, get random value, update rolls count
      dice.rollDice();
      cout << "Dice roll: " << dice.getCurrentRoll() << endl<< endl;

      // if acceptable value add points, increment rolls, check for winning roll
      if(currentPlayer == 1){
        p1.addPoints(dice.getCurrentRoll(),target);
        p1.updateRolls();
        p1.checkWinner(target);
      }
      else{
        p2.addPoints(dice.getCurrentRoll(),target);
        p2.updateRolls();
        p2.checkWinner(target);
        
      }

      // every time there is no winner, the dice is rolled, display stats
      if(p1.getWinner() == false && p2.getWinner() == false){
        p1.displayStats();
        p2.displayStats();
      }

    }
    else {
      cout << "Invalid input. Only 'r' is an acceptable input to roll the dice.";
    }

    // change player
    if (currentPlayer==1){
      currentPlayer=2;
    }
    else{
      currentPlayer=1;
    }

  } while (p1.getWinner() == false && p2.getWinner() == false);  
  // keep going while both players are under target points
  // when one reaches target the loop ends

  // ******************************************
  // Determine the winner
  // Check and update the leaderboard
  // Print the leaderboard
  // ******************************************
  
  cout << "The programe is finished";
  return 0;
  
}

////////////////////////////
//  END OF MAIN PROGRAM   //
////////////////////////////