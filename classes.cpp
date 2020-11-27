#include <iostream>
#include <ctime> 
#include <stdlib.h>     /* srand, rand */
using namespace std;

//
// CLASS Player
//
class Player{
  private:
    int points;
    int rolls;
    bool winner;
    string name;
    //int currentRoll;

  public:
    Player(){
      points = 0; rolls = 0; winner = false; name = "";
    }

    void setName(string n){name=n;}
    string displayName(){return name;}

    // t = temp value (the dice roll)
    // tar = target points set at start of the game
    void addPoints(int t, int tar){
      if(points + t <= tar){
        points = points + t;     
      }
    }

    void updateRolls(){
      rolls = rolls + 1;
    }

    void checkWinner(int tar){
      if(points==tar){
        winner = true;
        cout << "******************" << endl;
        cout << "GAME OVER" << endl;
        cout << "******************" << endl;
        cout << "The winner is player: " << name << endl;
        cout << "******************" << endl;
        displayStats();
      }
    }


    void displayStats(){
      cout << "- Points for " << name << ": " << points << endl;
      cout << "- Rolls for " << name << ": " << rolls << endl;
      cout << endl;
    }

    bool getWinner(){
      return winner;
    }

    string getName(){
      return name;
    }
    
};

//
// CLASS DICE
//
class Dice{
  private:
    int min;
    int max;
    int currentRoll;

  public:
    Dice(){}

    Dice(int low, int high){
      min=low;
      max=high;
    }

    int getMin(){
      return min;
    }

    int getMax(){
      return max;
    }

    int getCurrentRoll(){
      return currentRoll;
    }

    void rollDice(){
      currentRoll = rand() % max + min;  // generate random dice roll
    }
};

