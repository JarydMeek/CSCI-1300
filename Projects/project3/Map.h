#include <iostream>
#include <vector>
#include "Trainer.h"
#include "Pokemon.h"

#ifndef MAP_H
#define MAP_H

using namespace std;

class Map 
{ 
    private:
    char map[25][16];
    int travelResult;
    bool tryLuckSuccess;
    int numPokemonMap;

    public:
     Map(); // Default constructor
     vector<Pokemon> allPokemon;
     vector<Pokemon> wildPokemon;
     int numGyms;
     Trainer opponent[15];
     int split(string, char, string[], int);
     int readMap(string);
     Pokemon tryLuck(Trainer);
     int nearPokemon(Trainer);
     void printMap();
     void printMiniMap(Trainer);
     int loadAllPokemon(string);
     char getTypeAtPosition(int, int);
     Trainer travel(Trainer, string);
     int getTravelResult();
     bool getTryLuckSuccess();
     void moveWildPokemon();
     void printWildPokemon();

     

}; 

#endif 