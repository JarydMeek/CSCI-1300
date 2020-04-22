#include "Fight.h"
using namespace std;

Fight::Fight() {

} 
/*
* Algorithm: Sets the current players pokemon, the oppenent pokemon and whether they are fighting at a gym or not
* Input parameters: the player's pokemon, the opponents pokemon, and a boolean telling the function if the fight is occuring at a gym or not.
* Output (prints to screen): the fight, including the results, and all the information
* Returns: nothing
*/
Fight::Fight(Pokemon player, Pokemon opponent, bool gym) {

} 
/*
* Algorithm: finds if the wild pokemon that the player finds will auto join the player.
* Input parameters: none
* Output (prints to screen): nothing
* Returns: true if the wild pokemon will join the player automatically
*/
bool Fight::wildAutoJoin() {
    srand(time(NULL));
    if ((rand() % 10) >=8) {
        return true;
    } else {
        return false;
    }
}
/*
* Algorithm: preforms the attack for each pokemon
* Input parameters: none
* Output (prints to screen): nothing
* Returns: the amound of damage that the pokemon will inflict on the opponent
*/
int Fight::attack(Pokemon &player, Pokemon &opponent) {
    if (player.getSpeed() > opponent.getSpeed()) { //player attacks first
        cout << player.getName() << " attacks first" << endl;
        int A = rand() % player.getAttack(); //calc A
        int D = rand() % opponent.getDefense(); //calc D
        int damageDealt = A - D; //find the difference
        if (damageDealt < 0) { //if the damage is negative, force it to 0
            damageDealt = 0;
        }
        opponent.setHP(opponent.getHP()- damageDealt);
        cout << player.getName() << " deals " << damageDealt << " damage" << endl;
        cout << "\n" << opponent.getName() << " attacks" << endl;
        int A2 = rand() % opponent.getAttack();//calc A
        int D2 = rand() % player.getDefense();//calc D
        int damageDealt2 = A2 - D2;//find the difference
        if (damageDealt2 < 0) {
            damageDealt2 = 0;//if the damage is negative, force it to 0
        }
        player.setHP(player.getHP()- damageDealt2);
        cout << opponent.getName() << " deals " << damageDealt2 << " damage" << endl;
    } else {
        cout << opponent.getName() << " attacks first" << endl;//opponent attacks first
        int A2 = rand() % opponent.getAttack();//calc A
        int D2 = rand() % player.getDefense();//calc D
        int damageDealt2 = A2 - D2;//find the difference
        if (damageDealt2 < 0) {
            damageDealt2 = 0;//if the damage is negative, force it to 0
        }
        player.setHP(player.getHP()- damageDealt2);
        cout << opponent.getName() << " deals " << damageDealt2 << " damage" << endl;
        cout << "\n" << player.getName() << " attacks" << endl;
        int A = rand() % player.getAttack();//calc A
        int D = rand() % opponent.getDefense();//calc D
        int damageDealt = A - D;//find the difference
        if (damageDealt < 0) {
            damageDealt = 0;//if the damage is negative, force it to 0
        }
        opponent.setHP(opponent.getHP()- damageDealt);
        cout << player.getName() << " deals " << damageDealt << " damage" << endl;
    }

    if (opponent.getHP() == 0) { //opponent faints
        return 1;
    } else if (player.getHP() == 0) { //player faints
        return 0;
    }
    return -1;   
}
/*
* Algorithm: calcualtes whether the attempt to run by the player is sucessful.
* Input parameters: none
* Output (prints to screen): nothing
* Returns: true if the player ran successfully, false if the player didn't
*/
bool Fight::run(Pokemon flee, Pokemon opponent) {
    srand(time(NULL));//seed random number generator
    double A = (flee.getSpeed()*32); //calc A
    double B = ((opponent.getSpeed()/4)%256); //calc B
    double fleeChance = (((A/B)+30)*(flee.numberTimesFleed+1)); //calc F (c is also in here)
    if (fleeChance > 255) { //if the flee is successful 100%
        return true;
    } else { //random chance to flee
        srand(time(NULL)); //seed again cause more random
        if ((rand() % 256) < fleeChance){ //see if flee works
            return true; //we can sissy out
        } else {
            return false;//we have to fight like men
        }
    }
}
/*
* Algorithm: preforms the Wild fight system
* Input parameters: none
* Output (prints to screen): nothing
* Returns: true if the player ran successfully, false if the player didn't
*/
bool Fight::wildFight(Trainer &player, Pokemon opponent, Map pokemonMap) {
    Pokemon playerActive = player.getActive();
    playerActive.numberTimesFleed = 0;
    opponent.numberTimesFleed = 0;
    cout << "\n\n\nYou ran into a wild pokemon!" << endl;
    srand(time(NULL));
    bool repeat = true;
    while (repeat == true) {
        int totalHP = 0;
        for (int i = 0; i < 6; i++) {
            if (player.getParty()[i] != -1){
                totalHP = totalHP + player.pokemon.at(i).getHP();
            }
        }
        if (totalHP == 0) {
            cout << "\n\n\nAll your Pokemon have fainted.\nYou lost the Fight.\n\n\n" << endl;
           bool foundCenter = false;
           int distanceFromPlayer = 1;
           opponent.levelUp();
            while (foundCenter == false){
                for (int i = player.getLocationY()-distanceFromPlayer; i < player.getLocationY()+distanceFromPlayer; i++) {
                    for (int j = player.getLocationX()-distanceFromPlayer; j <= player.getLocationX()+distanceFromPlayer; j++) {
                        if (pokemonMap.getTypeAtPosition(i,j) == 'C') {
                            player.currentX = j;
                            player.currentY = i;
                            foundCenter = true;
                            return false;
                        }
                    }
                }
                distanceFromPlayer++;
            }
            return false;
        }
        cout << "\nName - " << opponent.getName() << ", HP - " << opponent.getHP() << ", Attack - " << opponent.getAttack() << ", Defense - " << opponent.getDefense() << ", Speed - " << opponent.getSpeed() << ", Max - " << opponent.getMax() << endl;
        cout << "\n\nYour active Pokémon is - " << endl;
        cout << "\nName - " << player.getActive().getName() << ", HP - " << player.getActive().getHP() << ", Attack - " << player.getActive().getAttack() << ", Defense - " << player.getActive().getDefense() << ", Speed - " << player.getActive().getSpeed() << ", Max - " << player.getActive().getMax() << endl;
        playerActive = player.getActive();
        cout << "\nWhat do you want to do?\n1 - Fight\n2 - Switch Active Pokemon\n3 - Run" << endl;
        int selection = 0;
        if (cin >> selection) {
            switch (selection)
            {
            case 1:
                if (player.getActive().getHP() == 0) {
                    cout << "\n\n\nYour active Pokémon has fainted\nYou cannot go into battle with this Pokémon" << endl;
                } else {
                    if (player.numberWildCollected < 2) {
                        cout << opponent.getName() << "has joined your party!" << endl;
                        player.numberWildCollected++;
                        return true;
                    } else if (rand() % 10 <= 5) {
                    int attackResult = attack(player.pokemon.at(player.getActiveIndex()), opponent);
                        if (attackResult == 1) {
                            cout << "You won the fight! " << opponent.getName() << " has joined your party!" << endl;
                            return true;
                            player.getActive().levelUp();
                        }
                    } else {
                        opponent.numberTimesFleed++;
                        if (run(opponent, player.getActive()) == true) {
                            repeat = false;
                            char tempPosition;
                            bool wildHasPosition = false;
                            while (wildHasPosition == false) { //if the pokemon doesn't have a position
                                int randY = rand() % 25; //pick a random Y
                                int randX =  rand() % 16; //pick a random X
                                for (int j = 0; j < pokemonMap.wildPokemon.size(); j++) { //loop through for all the wild pokemon
                                    if (randY != pokemonMap.wildPokemon.at(j).getLocationY() && randX != pokemonMap.wildPokemon.at(j).getLocationX()){ //if the random position doesn't match one taken by another pokemon
                                        tempPosition = pokemonMap.getTypeAtPosition(randY,randX);  //make sure the tile is land
                                        if (tempPosition == 'p') { //see above
                                            opponent.setLocation(randY,randX); //set the wild pokemon to the tile
                                            wildHasPosition = true; //move on to the next pokemon, as the current one is on a valid position
                                            }
                                        }
                                    }
                                }
                            cout << "\n\n\nThe wild Pokémon has fled!\n\n\n" << endl;
                            return false;
                        }
                    }
                }
                break;
            case 2:
            {
                cout << "Pick another Pokémon to become active" << endl;
                int numSelected;
                for (int i = 0; i < 6; i++) {
                    if (player.party[i] != -1) {
                        numSelected++;
                    }
                }
                int tempPrint = 0;//temp storage
                while (tempPrint < numSelected) { //loop to print all in the new party
                    if (player.party[tempPrint] >= 0) {
                    cout << tempPrint+1 << " - " << player.pokemon.at(player.party[tempPrint-1]).getName() << endl; //actually print
                    tempPrint++; //move to the next pokemon to print
                    }
                }
                int activeSelection; //storage for input
                cin >> activeSelection;//collect input
                player.switchActive(activeSelection-1); //set the active pokemon

            }
            case 3:
                    playerActive.numberTimesFleed++;
                    if (run(player.getActive(), opponent) == true) {
                        cout << "\n\nYou were able to flee\n\n" << endl;
                        bool foundCenter = false;
                        int distanceFromPlayer = 1;
                        while (foundCenter == false){
                            for (int i = player.getLocationY()-distanceFromPlayer; i < player.getLocationY()+distanceFromPlayer; i++) {
                                for (int j = player.getLocationX()-distanceFromPlayer; j <= player.getLocationX()+distanceFromPlayer; j++) {
                                    if (pokemonMap.getTypeAtPosition(i,j) == 'C') {
                                        player.currentX = j;
                                        player.currentY = i;
                                        foundCenter = true;
                                        return false;
                                    }
                                }
                            }
                            distanceFromPlayer++;
                        }
                        repeat = false;
                        return false;
                    } else {
                        cout << "\n\nYou were unable to flee\n\n" << endl;
                    }
                break;
            default:
                cout << "Please make a valid selection" << endl;
                break;
            }
        }else {
            cout << "\n\n\n**Please make a valid selection**\n\n\n" << endl;
            cin.clear();
            cin.ignore(10000, '\n'); 
        }
   }
   return false;
}
/*
* Algorithm: preforms the trainer fight system
* Input parameters: none
* Output (prints to screen): nothing
* Returns: true if the player ran successfully, false if the player didn't
*/
bool Fight::trainerFight(Trainer &player, Trainer &opponent, Map pokemonMap) {
    cout << "\n\n\nYou arrived at the Gym and the trainer is there. They want to fight.\n" << endl;
    bool continueFight = true;
    while (continueFight == true) {
        if (player.getTotalHealth() == 0) {
        cout << "\n\n\nAll your Pokemon have fainted.\nYou lost the Fight.\n\n\n" << endl;
           bool foundCenter = false;
           int distanceFromPlayer = 1;
            while (foundCenter == false){
                for (int i = player.getLocationY()-distanceFromPlayer; i < player.getLocationY()+distanceFromPlayer; i++) {
                    for (int j = player.getLocationX()-distanceFromPlayer; j <= player.getLocationX()+distanceFromPlayer; j++) {
                        if (pokemonMap.getTypeAtPosition(i,j) == 'C') {
                            player.currentX = j;
                            player.currentY = i;
                            foundCenter = true;
                            return false;
                        }
                    }
                }
                distanceFromPlayer++;
            }
            return false;
        } else if (opponent.getTotalHealth() == 0) {
            return true;
        } else {
            cout << "\n\n\nYour opponent's active Pokémon is - \n" << endl;
            opponent.printSingleActive();
            cout << "\n\n\nYour active Pokémon is - \n" << endl;
            player.printSingleActive();
            cout << "\nWhat do you want to do?\n1 - Fight\n2 - Switch Active Pokemon" << endl;
            int fightSelection;
            cin >> fightSelection;
            if (fightSelection == 1) {
                if (player.getActive().getHP() == 0) {
                    cout << "\n\n\nYour active Pokémon has fainted!\nSelect a different Pokémon to continue.\n\n\n" << endl;
                    opponent.getActive().levelUp();
                } else {
                    int trainerFightResult = attack(player.pokemon.at(player.getActiveIndex()), opponent.pokemon.at(opponent.getActiveIndex()));
                    if (trainerFightResult == 1) {
                        cout << "\n\n\nYour opponent's active Pokémon has fainted!\n\n\n" << endl;
                        player.getActive().levelUp();
                        if (opponent.getActiveIndex() < opponent.getNumPokemon()) {
                            opponent.switchActive(opponent.getActiveIndex()+1);
                        }
                    }
                }
            } else if (fightSelection == 2) {
                {
                cout << "Pick another Pokémon to become active" << endl;
                int current = 0;
                while (player.getParty()[current] != -1) {
                    cout << current+1 << " - " << player.pokemon.at(current).getName() << endl;
                    current++;
                }
                cout << endl;
                int activeSelection;
                cin >> activeSelection;
                player.switchActive(activeSelection-1);
            }
            } else {
                cout << "Please enter a valid selection" << endl;
            }
        }
    }
    return false;
}

