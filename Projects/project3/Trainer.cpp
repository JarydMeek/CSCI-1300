#include "Trainer.h"
using namespace std;

    // Default constructor
    Trainer::Trainer() {
         pokemon.clear();
         pokeballs = 10;
         trainerName = "";
         activePokemon = 0;
         badges = 0;
         for (int i = 0; i < 6; i++) {
             party[i] = -1;
         }
         score = 0;
         hasLost = false;
         numberWildCollected = 0;
     }
    //setter for trainerName
     void Trainer::setName(string newName) {
         trainerName = newName;
     }
    //getter for trainerName
     string Trainer::getName() {
         return trainerName;
     }
    //setter for numPokeballs
     void Trainer::setPokeballs(int numPokeballs) {
         pokeballs = numPokeballs;
     }
    //getter for trainerName
     int Trainer::getPokeballs() {
         return pokeballs;
     }
     //getter for numPokemon
     int Trainer::getNumPokemon() {
         return pokemon.size();
     }
     //resets all pokemon's health
     void Trainer::pokemonCenter() {
         for (int i = 0; i < pokemon.size(); i++ ) {
             pokemon.at(i).resetHealth();
         }
     }
     //adds pokemon to the vector storage of all the trainer's pokedex
     void Trainer::addPokemon(Pokemon newPokemon) {
         pokemon.push_back(newPokemon);
         if (getNumPokemon()-1 < 6) {
             party[getNumPokemon()-1] = getNumPokemon()-1;
             numActive++;
         }
     }
     //sets the new index of the active pokemon
     void Trainer::switchActive(int newActive) {
         activePokemon = newActive;
     }     
     //getter for the active pokemon
     Pokemon Trainer::getActive() {
         return pokemon.at(activePokemon);
     }
     //getter for the active pokemon
     int Trainer::currentActive() {
         return activePokemon;
     }
     //reorganize the list of active pokemon
     void Trainer::reorganize(int pos1, int pos2, int pos3, int pos4, int pos5, int pos6) {
         party[0] = pos1-1;
         party[1] = pos2-1;
         party[2] = pos3-1;
         party[3] = pos4-1;
         party[4] = pos5-1;
         party[5] = pos6-1;
     }
     void Trainer::pickActive() {
         bool repeat = true;
        string newPartySelection; //storage for the new entry
        string newPartyTemp; //temp string
        vector<int> newParty; //temp party storage
        int numSelected = 0; //number of pokemon picked
         while (repeat == true) {
             newPartySelection = "";
            //nice message explaining what to do
            cout << "\nHere are all the Pokémon in your Pokédex. Choose at most 6 Numbers to become members of your party.\nEnter a number corresponding to each Pokémon then enter q, for example \"1 2 3 4 5 6 Q\"" << endl;
            int current = 0; //temp storage
            while (current < pokemon.size()) {
                cout << current+1 << " - " << pokemon.at(current).getName() << endl;//print out all the pokemon in the pokedex
                current++;
            }
                while (cin >> newPartySelection) {
                    if (newPartySelection != "Q" && newPartySelection != "q") {
                        newParty.push_back(stoi(newPartySelection));
                        numSelected++;
                    } else {
                        if (numSelected == 0) {
                            cout << "Please select a Pokémon" << endl;
                        } else {
                        break;
                        }
                    }
                }
                repeat = false;
                break;
         }
        while (newParty.size() < 6) { //if at least 6 entries haven't been filled, fill the rest with -1
            newParty.push_back(0);
        }
        reorganize(newParty.at(0),newParty.at(1),newParty.at(2),newParty.at(3),newParty.at(4),newParty.at(5)); //actually reorganize the party
        cout << "You have chosen the " << numSelected << " Pokémon below. Please choose which one should be the active Pokémon - " << endl; //question
        numActive = numSelected;
        int tempPrint = 0;//temp storage
        while (tempPrint < numSelected) { //loop to print all in the new party
            if (newParty.at(tempPrint) >= 0) {
            cout << tempPrint+1 << " - " << pokemon.at(newParty.at(tempPrint)-1).getName() << endl; //actually print
            tempPrint++; //move to the next pokemon to print
            }
        }
        int activeSelection; //storage for input
        cin >> activeSelection;//collect input
        switchActive(activeSelection-1); //set the active pokemon

     }

     //adds to the score
     void Trainer::addToScore (int value) {
         score = score + value;
     }
     //getter for score
     int Trainer::getScore() {
         return score;
     }
     /*
     * Algorithm: sets the location of the player
     * Input parameters: none
     * Output (prints to screen): nothing
     * Returns: 1 if the location is valid and completed sucessfully, -1 if the location is invalid
     */
     int Trainer::setLocation(int newX, int newY) {
          if (newX >= 0 && newX <=16 && newY >= 0 && newY <= 25) {
               currentX = newX-1;
               currentY = newY-1;
               return 1;
          } else {
               return -1;
          }
     }
     
    //getter for locationX
     int Trainer::getLocationX() {
         return currentX;
     }
    //getter for locationY
     int Trainer::getLocationY() {
         return currentY;
     }
    //getter for overall health term
     string Trainer::getOverallHealth() {
         double overallHealth = 0;
         double overallMaxHP = 0;

         for (int i = 0; i < numActive; i++) { //total up the current hp and maxhealth for all the pokemon that are in our party
             overallHealth = overallHealth + pokemon.at(party[i]).getHP();
             overallMaxHP = overallMaxHP + pokemon.at(party[i]).getMaxHealth();
         }
         double percentageHealth = overallHealth/overallMaxHP; //calculate the percentage of the max health we are att
         if (percentageHealth == 0) { //eryone ded
            return "all fainted";
         } else if (percentageHealth > 0 && percentageHealth <= 0.25) { //lower than 25%
            return "very hurt";
         } else if (percentageHealth > 0.25 && percentageHealth <= 0.5) {//25 to 50%
            return "hurt";
         } else if (percentageHealth > 0.5 && percentageHealth <= 0.75) {//50 to 75%
            return "injured";
         } else if (percentageHealth > 0.75 && percentageHealth <= 1) {//75 to full
            return "strong";
         } else { //something broke
             return "Error";
         }
     }
    //printer for party Pokemon
     void Trainer::printActive() {
         for (int i = 0; i < 6; i++) {//go through all in party
             if (party[i] != -1) {//make sure there is a pokemon there
                cout << "Name - " << pokemon.at(party[i]).getName();//print
                if (i == activePokemon) {//print if active
                    cout << " (Active)";//printe
                }
                //print
                cout << ", HP - " << pokemon.at(party[i]).getHP() << ", Attack - " << pokemon.at(party[i]).getAttack() << ", Defense - " << pokemon.at(party[i]).getDefense() << ", Speed - " << pokemon.at(party[i]).getSpeed() << ", Max - " << pokemon.at(party[i]).getMax() << endl;
             }
         }
     }
    //printer for a single active pokemon    
     void Trainer::printSingleActive() {
         //prints ONLY the active pokemon
        cout << "Name - " << pokemon.at(party[activePokemon]).getName() << " (Active)" << ", HP - " << pokemon.at(party[activePokemon]).getHP() << ", Attack - " << pokemon.at(party[activePokemon]).getAttack() << ", Defense - " << pokemon.at(party[activePokemon]).getDefense() << ", Speed - " << pokemon.at(party[activePokemon]).getSpeed() << ", Max - " << pokemon.at(party[activePokemon]).getMax() << endl;
     }
    /*
     * Algorithm: Adds 1 to all pokemon HP and removes 1 pokeball.
     * Input parameters: none
     * Output (prints to screen): nothing
     * Returns: none
     */
     void Trainer::rest() {
         if (pokeballs > 0){
            pokeballs--;
            for (int i = 0; i < pokemon.size(); i++) {
                int healthTemp = pokemon.at(i).getHP()+1;
                if (healthTemp < pokemon.at(i).getMaxHealth()) {
                pokemon.at(i).setHP(pokemon.at(i).getHP()+1);
                }
            }
         } else {
             cout << "\n\n\nYou are out of Pokéballs, Please pick a different option.\n\n\n" << endl;//player dumb
         }
     }

    //getter for party[]
    int* Trainer::getParty() {
        return party;
    }
    //getter for index of active pokemon
    int Trainer::getActiveIndex() {
        return activePokemon;
    }
    //getter for totalHealth
    int Trainer::getTotalHealth() {
        int totalHealth = 0;
        for (int i = 0; i < pokemon.size(); i++) {//sums all the party pokemon's health
            totalHealth = totalHealth + pokemon.at(i).getHP();
        }
        return totalHealth;
    }