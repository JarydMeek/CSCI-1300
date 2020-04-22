#include <iostream>
#include "Pokemon.h"
#include <vector>

using namespace std;

#ifndef TRAINER_H
#define TRAINER_H


class Trainer 
{ 
    private:
    string trainerName;
    int activePokemon;
    int numActive;
    int scoreWild;
    int scoreGym;
    

    public:
     int party[6];
     vector<Pokemon> pokemon;
     int currentX;
     int badges;
     int score;
     int pokeballs;
     int numberWildCollected;
     int currentY;
     bool hasLost;
     Trainer(); // Default constructor
     void setName(string);
     string getName();
     void setPokeballs(int);
     int getPokeballs();
     int getNumPokemon();
     void pokemonCenter();
     void addPokemon(Pokemon);
     int getActiveIndex();
     void switchActive(int);
     void pickActive();
     Pokemon getActive();
     int currentActive();
     void reorganize(int, int, int, int, int, int);
     void addToScore(int);
     int getScore();
     int setLocation(int, int);
     int getLocationX();
     int getLocationY();
     string getOverallHealth();
     void printActive();
     void printSingleActive();
     void rest();
     int* getParty();
     int getTotalHealth();
}; 

#endif 