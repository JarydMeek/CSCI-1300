#include <iostream>
#include "Pokemon.h"
#include "Trainer.h"
#include "Map.h"

using namespace std;

#ifndef FIGHT_H
#define FIGHT_H


class Fight 
{ 
    private:
    Pokemon playerPokemon;
    Pokemon opponentPokemon;
    bool gymFight;

    
    public:
     Fight(); // Default constructor
     Fight(Pokemon, Pokemon, bool);
     bool wildAutoJoin();
     int attack(Pokemon &, Pokemon &);
     bool run(Pokemon, Pokemon);
     bool wildFight(Trainer &, Pokemon, Map);
     bool trainerFight(Trainer &, Trainer &, Map);
     

}; 

#endif 