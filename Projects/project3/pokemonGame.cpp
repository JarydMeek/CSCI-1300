#include "Map.cpp"
#include "Trainer.cpp"
#include "Pokemon.cpp"
#include "Fight.cpp"
#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;


int main() {
    //storage for if the player won or lost for the scoreboard
    char winLoss;
    //Create Player
    Trainer player;
    //Create Map
    Map pokemonMap;
    //Create Repeat variable
    bool continueGame = true;


    //Initialize map and Pokemon
    int mapLoad = pokemonMap.readMap("GivenFiles/mapPoke.txt"); //load map file
    int pokemonLoad = pokemonMap.loadAllPokemon("GivenFiles/pokemon.txt"); //load all pokemon into vector
    if (mapLoad == -1 || pokemonLoad == -1) { //if there was an error, output that there was.
        cout << "An error has occurred initializing the game" << endl;
    }

    //Welcome
    //The following line is ASCII art... It's a long line
    cout << "                                  ,'\\ \n    _.----.        ____         ,'  _\\   ___    ___     ____ \n_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`. \n\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  | \n \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  | \n   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  | \n    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     | \n     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    | \n      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   | \n       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   | \n        \\_.-'       |__|    `-._ |              '-.|     '-.| |   | \n                                `'                            '-._| \n" << endl;
    cout << "Welcome to Pokémon!\n" << endl; //welcome message

    //Initialize Player and Starting Pokemon
    cout << "Please state your name: "; 
    string name = "";//temp storage for username
    getline(cin, name); //save player name to temp string
    player.setName(name); //update the player name
    cout << endl;//blank line
    //welcome message (using playername)
    cout << "Welcome, " << player.getName() << "! Before you can begin your Pokémon adventure, you must choose a starting Pokémon, courtesy of the Professor. ​Please choose from the following ​Pokémon​ - " << endl;
    bool sucessfulStartingSelection = false; //create boolean to track if a valid input has been input
    while (sucessfulStartingSelection == false){ //while a successful selection hasn't been made, continue showing the menu
        cout << "1 - Bulbasaur\n2 - Charmander\n3 - Squirtle\n4 - Pikachu" << endl; //show menu
        int startingPokemon = 0; //variable to store selection in
        cin >> startingPokemon;  //store the selection
        switch (startingPokemon) {  //switch for each of the menu options
            case 1: //player wants bulbusaur
                player.setLocation(7,13); //set starting location to the correct location
                for (int i = 0; i < pokemonMap.allPokemon.size(); i++) { //find bulbasaur in the list of all pokemon
                    if ("Bulbasaur" == pokemonMap.allPokemon.at(i).getName()) { //find him
                        player.addPokemon(pokemonMap.allPokemon.at(i)); //add him to the player's pokedex
                    }
                }
                sucessfulStartingSelection = true; //there was a successful selection
                break;
            case 2: 
                player.setLocation(8,13);//set starting location to the correct location
                for (int i = 0; i < pokemonMap.allPokemon.size(); i++) {//find in the list of all pokemon
                    if ("Charmander" == pokemonMap.allPokemon.at(i).getName()) {//find him
                        player.addPokemon(pokemonMap.allPokemon.at(i));//add him to the player's pokedex
                    }
                }
                sucessfulStartingSelection = true;//there was a successful selection
                break;
            case 3: 
                player.setLocation(9,13);//set starting location to the correct location
                for (int i = 0; i < pokemonMap.allPokemon.size(); i++) {//find in the list of all pokemon
                    if ("Squirtle" == pokemonMap.allPokemon.at(i).getName()) {//find him
                        player.addPokemon(pokemonMap.allPokemon.at(i));//add him to the player's pokedex
                    }
                }
                sucessfulStartingSelection = true;//there was a successful selection
                break;
            case 4: 
                player.setLocation(10,13);//set starting location to the correct location
                for (int i = 0; i < pokemonMap.allPokemon.size(); i++) {//find in the list of all pokemon
                    if ("Pikachu" == pokemonMap.allPokemon.at(i).getName()) {//find him
                        player.addPokemon(pokemonMap.allPokemon.at(i));//add him to the player's pokedex
                    }
                }
                sucessfulStartingSelection = true;//there was a successful selection
                break;
            default:
                cout << "Please pick 1 - 4" << endl; //the user entered something unexpected
                break;
        }
    }
    pokemonMap.numGyms = 0;
    //Initialize Gym Trainers
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 16; j++) {
            if (pokemonMap.getTypeAtPosition(i, j) == 'G') { //find any tiles that are a gym
                pokemonMap.numGyms++; //count them
            }
        }
    }
    srand(time(NULL));
    int test = 0;
    for (int j = 0; j < pokemonMap.numGyms; j++) { //create a trainer for every gym
        for (int i = 1; i <= (rand() % 6)+1; i++) { //pick a random number of pokemon to add to the trainer (from 1 to 6)
            pokemonMap.opponent[j].addPokemon(pokemonMap.allPokemon.at(rand() % pokemonMap.allPokemon.size())); //add the correct number of random pokemon to each of the gym trainers
        }
    }
    int trainersTemp = 0; //variable to track the number of trainers already assigned
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 16; j++) {
            if (pokemonMap.getTypeAtPosition(i, j) == 'G') { //find and tile that is a gym
                pokemonMap.opponent[trainersTemp].setLocation(j+1, i+1); //assign a trainer there
                trainersTemp++; //move on to the next trainer
                
            }
        }
    }

    //Initialize Wild Pokemon
    char tempPosition; //temporary storage for position
    bool wildHasPosition = false; //create bool for while loop
    for (int i = 0; i < 20; i++) { //go through the following 20 times for the 20 wild pokemon
        wildHasPosition = false; //reset valid position to false each loop
        pokemonMap.wildPokemon.push_back(pokemonMap.allPokemon.at(rand() % pokemonMap.allPokemon.size())); //pick a random pokemon and add it to the wildPokemon vector
        while(wildHasPosition == false) { //if the pokemon doesn't have a position
            int randY = rand() % 25; //pick a random Y
            int randX =  rand() % 16; //pick a random X
            for (int j = 0; j < pokemonMap.wildPokemon.size(); j++) { //loop through for all the wild pokemon
                if (randY != pokemonMap.wildPokemon.at(j).getLocationY() && randX != pokemonMap.wildPokemon.at(j).getLocationX()){ //if the random position doesn't match one taken by another pokemon
                    tempPosition = pokemonMap.getTypeAtPosition(randY,randX);  //make sure the tile is land
                    if (tempPosition == 'p') { //see above
                        pokemonMap.wildPokemon.at(i).setLocation(randY,randX); //set the wild pokemon to the tile
                        wildHasPosition = true; //move on to the next pokemon, as the current one is on a valid position
                    }
                }
            }
        }
    }


    cout << "Awesome! Lets get started!\n\n\n" << endl; //initialization completed successfullys
    
    //Turns
    while (continueGame == true) { //if the game is still going on
        //**HANDLES BASIC TURNS**
        bool enterGym = false; //resets the variable for being in a gym
        Pokemon tempPokemon; //temporary pokemon variable
        string tryLuckResponse; //storage for tryLuck
        bool enterCenter = false; //resets the variable for being in a center
        pokemonMap.printMiniMap(player); //print the 7x7 mini map
        cout << "The sun is shining, " << player.getName() << "! It's a beautiful day, we have " << player.getPokeballs() << " Pokéball left and your Pokémon are "; //update on pokeballs, uses playername, and lists overall health of pokemon
        cout << player.getOverallHealth() << "\n" << endl; // see above
        player.printActive(); //print all the pokemon in the players party (6 max)
        bool sucessfulTurnSelection = false; //create a variable for while loop
        while (sucessfulTurnSelection == false){ //loop until valid option has been picked.
            cout << "\nPlease choose from the following options - " << endl; //display menu
            cout << "1 - Travel" << endl; //opt 1
            cout << "2 - Rest" << endl; //opt 2
            cout << "3 - Try your luck" << endl; //opt 3
            cout << "4 - Quit the game" << endl; //opt 4
            int turnSelection = 0; //storage for turn selection
            bool travelSelection = false; //variable for while loop
                if (cin >> turnSelection) { //store input
                    switch (turnSelection) { 
                        case 1: //travel
                        {
                            sucessfulTurnSelection = true; //don't prompt for another entry
                            while (travelSelection == false){ //while loop to get valid direction entrys
                                cout << "Which direction would you like to move?" << endl; //question
                                cout << "1 - North\n2 - South\n3 - East\n4 - West" << endl; //menu
                                int travelDirection; //storage for direction
                                if (cin >> travelDirection) { //store input
                                    switch (travelDirection) { 
                                        case 1: 
                                            player = pokemonMap.travel(player, "north"); //move player north
                                            break;
                                        case 2: 
                                            player = pokemonMap.travel(player, "south"); //move player south
                                            break;
                                        case 3: 
                                            player = pokemonMap.travel(player, "east"); //move player east
                                            break;
                                        case 4: 
                                            player = pokemonMap.travel(player, "west"); //move player west
                                            break;
                                        default: 
                                            cout << "Please make a valid selection" << endl; //player didn't enter a valid NUMBER
                                            break;
                                    }
                                }else {
                                    cout << "Please make a valid selection" << endl; //player didn't enter valid CHARACTER
                                    cin.clear(); //clear the cin error state
                                    cin.ignore(10000, '\n'); //clear the cin buffer
                                }
                                if (pokemonMap.getTravelResult() == 1) {//move was successful to another land tile
                                    travelSelection = true;
                                } else if (pokemonMap.getTravelResult() == 2) { //move was successful to a gym tile
                                    enterGym = true;
                                    travelSelection = true;
                                } else if (pokemonMap.getTravelResult() == 3) { //move was successful to a center tile
                                    enterCenter = true;
                                    travelSelection = true;
                                } else {
                                    cout << "\n\n\n\nYou can't move that direction\n\n\n\n" << endl; //move was unsuccessful
                                    pokemonMap.printMiniMap(player); //print map again
                                    cout << endl; //loop to the top for entry attempt
                                }
                            }
                            //**HANDLES WILD FIGHTS**
                            int nearPokemonResult = pokemonMap.nearPokemon(player); //if the player is near a wild pokemon
                            if (nearPokemonResult >= 0 && player.getTotalHealth() != 0 && enterGym == false && enterCenter == false) { //make sure the player isn't entering a gym, center, or has 0 health
                                Fight wild; //create fight instance
                                if (wild.wildFight(player, pokemonMap.wildPokemon.at(nearPokemonResult), pokemonMap) == true) { //actully preform the fight
                                    player.addPokemon(pokemonMap.wildPokemon.at(nearPokemonResult)); //since we won, add the wildpokemon to our pokedex
                                    pokemonMap.wildPokemon.erase(pokemonMap.wildPokemon.begin()+nearPokemonResult); //erase the wildpokemon from the vector since we have it now
                                    player.score = player.score + 10; //add 10 to the score
                                    player.pokeballs--; //remove a pokeball
                                }
                                if (pokemonMap.getTypeAtPosition(player.getLocationY(), player.getLocationX()) == 'C') { //if the player is at a center square (they will be since they lost if this runs)
                                    enterCenter = true; //go to the center
                                }
                            }
                        }
                            break;
                        case 2: 
                            sucessfulTurnSelection = true;
                            player.rest(); //run rest function
                            break;
                        case 3: 
                            sucessfulTurnSelection = true;
                            tempPokemon = pokemonMap.tryLuck(player); //try luck, store the pokemon returned
                            if (pokemonMap.getTryLuckSuccess() == true) { //if the pokemon returned isn't empty
                                cout << "Congrats! You got Lucky! " << tempPokemon.getName() << " just joined your party!" << endl; //nice message
                                player.addPokemon(tempPokemon); //add the new pokemon to the party
                                player.score = player.score + 10;
                            } else {
                                cout << "Unlucky! No pokémon this turn." << endl; //you didn't find a pokemon :(
                            }
                            break;
                        case 4: 
                            cout << "Are you sure? (Y/N)" << endl; //Quit game
                            char check;
                            cin >> check;
                            if (check == 'Y' || check == 'y') { //verify quit (you can never be too sure)
                                cout << "Are you POSITIVE? (Y/N)" << endl;
                                char check2;
                                cin >> check2;
                                if (check2 == 'Y' || check2 == 'y') {
                                    continueGame = false;//end the game
                                    sucessfulTurnSelection = true;//don't prompt menu again
                                    winLoss = 'L';
                                    cout << "You lost. You finished with "<< player.score << " points and " << player.badges << " badges. There were " << player.pokemon.size() << " Pokémon in your Pokédex."<< endl; //final message
                                }
                            }
                            break;
                        default:
                            cout << "Please pick 1 - 4" << endl; //invalid entry NUMBER
                            break;
                    }
                } else {
                    cin.clear(); //clear error
                    cin.ignore(10000, '\n');  //clear buffer
                    cout << "Please pick 1 - 4" << endl; //invalid entry CHARACTER
                }
        }

        //**HANDLES GYMS**
        if (enterGym == true) { //if we are on a gym tile
            int trainerIndex; //storage for the trainer index of the gym tile we are on
            for (int i = 0; i < 15; i++) {
                if (player.getLocationX() == pokemonMap.opponent[i].getLocationX() && player.getLocationY() == pokemonMap.opponent[i].getLocationY()) { //find the index for the trainer assigned to this gym
                    trainerIndex = i; //store it
                }
            }
            if (pokemonMap.opponent[trainerIndex].hasLost == false) { //if we haven't beat this trainer before
                Fight gymFight; //fight instance
                bool result = gymFight.trainerFight(player, pokemonMap.opponent[trainerIndex], pokemonMap); //run the fight and store the result
                if (result == true) { //if we won
                    pokemonMap.opponent[trainerIndex].hasLost = true; //we have now beat this gym
                    for (int i = 0; i < pokemonMap.opponent[trainerIndex].pokemon.size(); i++) { //loop through all the trainer's pokemon
                        player.addPokemon(pokemonMap.opponent[trainerIndex].pokemon.at(i)); //add them to the player
                    }
                    player.badges++; //add a badge
                    player.score = player.score+60; //add to score
                    player.pokeballs = player.pokeballs+5; //give player pokeballs
                    cout << "You Won!\nYou have added " << pokemonMap.opponent[trainerIndex].pokemon.size() << " Pokémon to your party!" << endl; //congrats message
                } else {
                    enterCenter = true;//you lost and need to go to a center
                }
            } else {
                cout << "\n\n\nYou already control this gym!\n\n\n" << endl; //you've already won at that gym
            }
        }
        
        //**HANDLES POKEMON CENTERS**
        if (enterCenter == true) { //you are on a center tile
            player.pokemonCenter(); //heal pokemon
            cout << "Welcome to the Pokémon Center. All Pokémon in your party have been healed. Do you want to change the members of your party?\n(Y/N)" << endl; //happy message
            char centerSelection; //storage for selection (Y/N)
            bool centerValidSelection = false; //variable for while loop
            while (centerValidSelection == false) { //make sure we have a valid entry
                cin >> centerSelection; //store entry
                if (centerSelection == 'Y' || centerSelection == 'y') { //the player wants to reorganize
                    player.pickActive();
                    centerValidSelection = true; //we had a valid selection
                } else if (centerSelection == 'N' || centerSelection == 'n') { //the player doesn't want to organize
                    centerValidSelection = true; //valid input
                } else {
                    cout << "Please make a Valid Selection (Y/N)" << endl; //invalid input
                }
            }
        }

        //**HANDLES WILD POKEMON MOVEMENT**
        pokemonMap.moveWildPokemon(); //end of a turn, move pokemon in a random direction

        //**HANDLES POST TURN RANDOMNESS AND WIN CONDITIONS**
        if (continueGame == true) {//make sure that we aren't ending
            srand(time(NULL)); //Seed random number generator again so we get a more random number (yay psudoranomness)
            int randomness = rand() % 100;
                //**HANDLES RANDOM POKEMON CATCH AND RELEASE**
                if (randomness > 0 && randomness < 30) {
                    int newPokemonSelection = rand() % pokemonMap.allPokemon.size();
                    cout << "Suddenly, " << pokemonMap.allPokemon.at(newPokemonSelection).getName() << " appears in your path. Do you want to -\n1 - Catch it\n2 - Release it" << endl;
                    char randomPokemonSelection;
                    cin >> randomPokemonSelection;
                    bool validRandomSelection = false;
                    while (validRandomSelection == false)
                        if (randomPokemonSelection == '1' || randomPokemonSelection == '1') {
                            player.addPokemon(pokemonMap.allPokemon.at(newPokemonSelection));
                            cout << "Awesome! " << pokemonMap.allPokemon.at(newPokemonSelection).getName() << " has joined your pokedex!" << endl;
                            validRandomSelection = true;
                            player.numberWildCollected++;
                        } else if (randomPokemonSelection == '2' || randomPokemonSelection == '2') {
                            cout << "*Poof* \n" << pokemonMap.allPokemon.at(newPokemonSelection).getName() << " has vanished!" << endl;
                            validRandomSelection = true;
                        } else {
                            cout << "Please enter a valid input (1 or 2)" << endl;
                        }
                }
                
                //**HANDLES HIDDEN TREASURE**
                if (randomness >= 30 && randomness < 55) {
                    int randFruitVSBalls = rand() % 2;
                    if (randFruitVSBalls == 0) {
                        player.pokeballs = player.pokeballs + 2;
                        cout << "Great news! You have stumbled upon a hidden stash of Pokéballs. Your reserves increased to " << player.getPokeballs() << " Pokéballs." << endl;
                    } else {
                        /*cout << "Great news! You have stumbled upon a hidden stash of Poffins. Your Pokémon are delighted. Choose one of them to feast on the Poffins and Level Up - " << endl;
                        int current = 0; //temp storage
                        while (current < player.pokemon.size()) {
                            cout << current+1 << " - " << player.pokemon.at(current).getName() << endl;//print out all the pokemon in the pokedex
                            current++;
                        }
                        int levelUpPick;
                        cin >> levelUpPick;
                        player.pokemon.at(levelUpPick).levelUp();
                        cout << player.pokemon.at(levelUpPick).getName() << " has leveled up!" << endl;
                        */

                    }
                }

                //**HANDLES DEATHS**
                if (randomness >= 55 && randomness < 75) {
                    if (player.getNumPokemon() > 1) { //if the pokemon dies (and the player has more than 1 pokemon)
                        int toDie = rand()%player.getNumPokemon(); //picks a pokemon at random
                        cout << "\n\nOh No!\n\nIt is with great sadness that we report that " << player.pokemon.at(toDie).getName() << " has perished.\n\n Please reorganize your party." << endl; //tell the player their pokemon died
                        player.pokemon.erase(player.pokemon.begin()+toDie); //remove the pokemon from the player's inventory
                        player.pickActive(); //have the player update their party
                    }
                }

            //**HANDLES WIN CONDITIONS**
                //**HANDLES BADGE NUMBER WIN CONDITION**
                if (player.badges >= 6) { //player wins
                    continueGame = false; //don't continue game
                    cout << "\n\n\n ~~CONGRATULATIONS~~ \n\n\n "<< endl;
                    winLoss = 'W';
                    cout << "You won! You finished with "<< player.score << " points and " << player.badges << " badges" << endl; //final message
                }
                
                //**HANDLES TYPE WIN CONDITION**
                vector<string> typeStorage; //stores all the different types
                int typeMatches; //stores the number of matches
                for (int i = 0; i < player.pokemon.size(); i++) { //go through all the player's pokemon
                    typeMatches = 0; //reset storage to 0
                    for (int j = 0; j < typeStorage.size(); j++) {
                        if (player.pokemon.at(i).getType1() == typeStorage.at(j)) {
                            typeMatches++; //if the type doesn't match what is already saved, add 1
                        }
                    }
                    for (int j = 0; j < typeStorage.size(); j++) {
                        if (player.pokemon.at(i).getType2() == typeStorage.at(j)) {
                            typeMatches++; //does the same as above just for type 2 (For pokemon with 2 types.)
                        }
                    }
                    if (typeMatches == 0) {
                        typeStorage.push_back(player.pokemon.at(i).getType1()); //add the pokemon's type if there wasn't any matches found
                    }
                }
                if (typeStorage.size() >= 8) {
                    continueGame = false; //end game 
                    cout << "\n\n\n ~~CONGRATULATIONS~~ \n\n\n "<< endl; //player won
                    cout << "You won! You finished with "<< player.score << " points and " << player.pokemon.size() << " Pokémon" << endl; //final message
                    winLoss = 'W';
                }

        }
    }
    
    //**HANDLES SAVING INFO TO FILE**
        ofstream scoreboard;
        scoreboard.open ("scoreboard.txt", ios::app);
        scoreboard << endl;
        scoreboard << left << setw(30) << setfill(' ') << player.getName();
        scoreboard << left << setw(15) << setfill(' ') << winLoss;
        scoreboard << left << setw(10) << setfill(' ') << player.getScore();
        scoreboard.close();


}