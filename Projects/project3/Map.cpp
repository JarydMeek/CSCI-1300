#include "Map.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

     // Default constructor
     Map::Map() {
     int numGyms = 0;
     } 

     int Map::split(string split, char delimiter, string words[], int size) {
          //variable declaration
          int numSplits = 0;
          int lastSplit = 0;
          for (int i = 0; i < split.length(); i++ ) { //loops through all characters in the string
               if (split[i] == delimiter) { //checks if the current character is equal to the given delimeter
                    if (i != 0 || i != (split.length()-1)) {  //if it is, checks if the current character is the first or the last character
                         if (split.substr(lastSplit, i - lastSplit).length() > 0) { // if it isn't, checks to make sure the string generated isn't empty
                              words[numSplits] = split.substr(lastSplit, i-lastSplit); //if the string will contain data, save that string to the words array in the current array save point
                              numSplits++; //add one to the current array save point
                              lastSplit = i+1; //set the position for the start point of the next substring to be after the previous string and delimeter
                         } else {
                              lastSplit++; //if the string generated would have length 0 (two characters back to back), skip that character
                         }
                    } else if (i==0) {
                         lastSplit++; //if the current character matches the delimeter at the first postion, skip it.
                    }
               }
          }
          words[numSplits] = split.substr(lastSplit, split.length()); //save the string from the final delimeter to the end of the string.
          if (split[split.length()-1] == delimiter) { //checks to make sure that if the delimeter is found at the end of the string to not count it,
          numSplits--;
          }
          
          if (numSplits > size) { //if the number of delimiters found is greater than the size given, return -1
               return numSplits +1;
          } else if (split.length() == 0) { //if the string is empty, return 0
               return 0;
          } else{
               return numSplits+1; // otherwise, return the number of demimeters +1 (+1 since there is text after the final delimeter)
          }
     } 

    /*
    * Algorithm: Moves the players current location in the direction passed to the function.
    * Input parameters: string of direction to move.
    * Output (prints to screen): nothing.
    * Returns: 1 if the move was successful, and a -1 if it wasn't;
    */
     int Map::readMap(string filename) {
          ifstream importFile; //create the file stream
          importFile.open(filename); //open the file passed to the function
          string toSplit = ""; //create temporary storage variable for the line to be split
          string splitMap[16]; //create array to store the data after it has been split
          int numRows = 25;
          string postSplit = "";
          int currentLine = 0; //create a variable that tracks the number of lines used by the given file
          if (importFile.is_open()) { //if there is room, make sure the file opened successfully
               while (getline(importFile, toSplit)) { //gets the current line, then moves to the next one,
                    if (toSplit.length() != 0){ //checks to make sure the line contains data
                         int splitted = split(toSplit, ',' , splitMap, numRows); //split the line into ints stored as strings
                         for (int i = 0; i < 16; i++) {
                              postSplit = splitMap[i];
                             map[currentLine][i] = postSplit[0];
                         }
                         currentLine++;
                    }
               }
                    importFile.close(); //actually close the stream because I'm a good person
                    return currentLine; //return the line the function got to.
               
          } else {
               return-1; //return -1 if file couldn't be opened
          }
     }


     /*
     * Algorithm: checks for wild pokemon in a 7x7 area around the player, if there is one there, there is a 50% chance the player catches it for free
     * Input parameters: none
     * Output (prints to screen): nothing
     * Returns: the name of the pokemon the player found or Error.
     */
     Pokemon Map::tryLuck(Trainer player) {
          Pokemon empty; //create empty pokemon
          tryLuckSuccess = false; //set the default case
          for (int k = 0; k < wildPokemon.size(); k++) { //go through all the wild pokemon
               //if there is one within the 7x7
               if (wildPokemon.at(k).getLocationX() >= player.getLocationX()-3 && wildPokemon.at(k).getLocationX() >= player.getLocationX()+3 && wildPokemon.at(k).getLocationY() >= player.getLocationY()-3 && wildPokemon.at(k).getLocationY() <= player.getLocationY()+3) {
                    //seed for true random value
                    srand(time(NULL));
                    //find if we got the pokemon
                    if (rand()%10 >= 5) {
                         tryLuckSuccess = true; //we got the pokemon
                         empty = wildPokemon.at(k); //save the pokemon we found
                         wildPokemon.erase(wildPokemon.begin()+k);//remove the pokemon we found from wildPokemon
                         break;
                    } else {
                         tryLuckSuccess = false; //we didn't get the bread, gamers
                    }
               }
               
          }

          return empty;
     }
     /*
     * Algorithm: checks for wild pokemon in a 2x2 area around the player.
     * Input parameters: none
     * Output (prints to screen): nothing
     * Returns: the index if there is a pokemon in a 2x2 area around the player, false if there isn't
     */
     int Map::nearPokemon(Trainer player) {
         int closePokemonIndex = -1; //create storage and default case
          for (int k = 0; k < wildPokemon.size(); k++) {//go through all pokemon
               //if one is within 2x2 of the player
               if (wildPokemon.at(k).getLocationX() >= player.getLocationX()-2 && wildPokemon.at(k).getLocationX() >= player.getLocationX()+3 && wildPokemon.at(k).getLocationY() >= player.getLocationY()-3 && wildPokemon.at(k).getLocationY() <= player.getLocationY()+2) {
               //set the index of the found pokemon
                closePokemonIndex = k;//store
                return closePokemonIndex; //return index
               }
          }
          return -1;//error
     }
     /*
     * Algorithm: Prints the entire map
     * Input parameters: none
     * Output (prints to screen): the entire map
     * Returns: nothing
     */
     void Map::printMap() {
          for (int i = 0; i < 25; i++) {
               for (int j = 0; j <16; j++) {
                    cout << map[i][j] << " ";
               }
               cout << endl;
          }
     }
     /*
     * Algorithm: outputs the 7x7 map around the player
     * Input parameters: none
     * Output (prints to screen): the 7x7 map around the player
     * Returns: nothing
     */
     void Map::printMiniMap(Trainer player) {
          char tempChar;
          cout << "+---------------+" << endl;//decorative
          for (int i = player.currentY-3; i < player.currentY+4; i++) { //goes through the 7x7
               cout << "| ";//decorative
               for (int j = player.currentX-3; j < player.currentX+4; j++) { //goes throught the 7x7
                    if (j == player.currentX && i == player.currentY) { //if we are on the same position as the player
                         cout << "@ "; //output the @
                    } else if (i < 0 || j < 0 || i > 24 || j > 15) { //if we are outside the map
                         cout << "X "; //output X's
                    } else {
                         tempChar = map[i][j];//get the character at the position
                         if (tempChar == 'w') { //if it's a water position, output ~
                              cout << "~ ";
                         } else if (tempChar == 'p') { //if it's a land position, output *
                              cout << "* ";
                         } else {
                              cout << tempChar << " "; //add a space between
                         }
                    }
               }
               cout << "|" << endl;//decorative
          }
          cout << "+---------------+" << endl;//decorative
     }     
     /*
     * Algorithm: Loads all Pokemon into a vector
     * Input parameters: filename to load pokemon from
     * Output (prints to screen): nothing
     * Returns: 1 if loaded sucessfully, -1 if It does not
     */
      int Map::loadAllPokemon(string filename) {
          ifstream importFile; //create the file stream
          importFile.open(filename); //open the file passed to the function
          string toSplit = ""; //create temporary storage variable for the line to be split
          string splitPokemon[10]; //create array to store the data after it has been split
          int numRows = 200;
          int currentLine = 0; //create a variable that tracks the number of lines used by the given file
          if (importFile.is_open()) { //if there is room, make sure the file opened successfully
               while (getline(importFile, toSplit)) { //gets the current line, then moves to the next one,
                    if (toSplit.length() != 0){ //checks to make sure the line contains data
                         int splitted = split(toSplit, ',' , splitPokemon, numRows); //split the line into ints stored as strings
                         if (currentLine > 0) {
                              Pokemon Temp(splitPokemon[1], stoi(splitPokemon[2]), stoi(splitPokemon[3]), stoi(splitPokemon[4]), stoi(splitPokemon[5]), stoi(splitPokemon[6]), splitPokemon[7], splitPokemon[8]);
                              allPokemon.push_back(Temp);
                         }
                         currentLine++;
                    }
               }
                    importFile.close(); //actually close the stream because I'm a good person
                    return currentLine; //return the line the function got to.
               
          } else {
               return-1; //return -1 if file couldn't be opened
          }
     }
     /*
     * Algorithm: returns the type of tile at a given postion
     * Input parameters: x coordinate, y coordinate
     * Output (prints to screen): nothing
     * Returns: the character at the position passed
     */
     char Map::getTypeAtPosition(int x, int y) {
          return map[x][y];
     }
     /*
     * Algorithm: Moves the players current location in the direction passed to the function.
     * Input parameters: string of direction to move.
     * Output (prints to screen): nothing.
     * Returns: 1 if the move was successful, and a -1 if it wasn't;
     */
     Trainer Map::travel(Trainer toMove, string direction) {
          if (direction == "north") {
               if (toMove.currentY-1 >= 0 && toMove.currentY-1 <= 24 && map[toMove.currentY-1][toMove.currentX] == 'p') { //make sure the land we want to move to is land and inside the map
                    toMove.currentY--;
                    travelResult =  1;
               } else if (map[toMove.currentY-1][toMove.currentX] == 'G'){//we are moving into a gym
                    toMove.currentY--;
                    travelResult =  2;
               } else if (map[toMove.currentY-1][toMove.currentX] == 'C'){//we are moving into a center
                    toMove.currentY--;
                    travelResult =  3;
               } else {
                    travelResult =  -1;
               }
          } else if (direction == "south") {
               if (toMove.currentY+1 >= 0 && toMove.currentY+1 <= 24 && map[toMove.currentY+1][toMove.currentX] == 'p') {//make sure the land we want to move to is land and inside the map
                    toMove.currentY++;
                    travelResult =  1;
               } else if (map[toMove.currentY+1][toMove.currentX] == 'G'){//we are moving into a gym
                    toMove.currentY++;
                    travelResult =  2;
               } else if (map[toMove.currentY+1][toMove.currentX] == 'C'){//we are moving into a center
                    travelResult =  3;
                    toMove.currentY++;
               } else {
                     travelResult =  -1;
               }
          }else if (direction == "west") {
               if (toMove.currentX-1 >= 0 && toMove.currentX-1 <= 15 && map[toMove.currentY][toMove.currentX-1] == 'p') {//make sure the land we want to move to is land and inside the map
                    toMove.currentX--;
                    travelResult =  1;
               } else if (map[toMove.currentY][toMove.currentX-1] == 'G'){//we are moving into a gym
                    toMove.currentX--;
                    travelResult =  2;
               } else if (map[toMove.currentY][toMove.currentX-1] == 'C'){//we are moving into a center
                    toMove.currentX--;
                    travelResult =  3;
               } else {
                    travelResult =  -1;
               }
          }else if (direction == "east") {
               if (toMove.currentX+1 >= 0 && toMove.currentX+1 <= 15 && map[toMove.currentY][toMove.currentX+1] == 'p') {//make sure the land we want to move to is land and inside the map
                    toMove.currentX++;
                    travelResult =  1;
               } else if (map[toMove.currentY][toMove.currentX+1] == 'G'){//we are moving into a gym
                    toMove.currentX++;
                    travelResult =  2;
               } else if (map[toMove.currentY][toMove.currentX+1] == 'C'){//we are moving into a center
                    toMove.currentX++;
                    travelResult =  3;
               } else {
                    travelResult =  -1; //invalid move
               }
          } else {
               travelResult =  -1;//invalid move
          }
          return toMove;//return the player post move
     }
     //getter for 
     int Map::getTravelResult() {
          return travelResult;
     }
          //getter for 
     bool Map::getTryLuckSuccess() {
          return tryLuckSuccess;
     }

     /*
     * Algorithm: randomly moves all wild pokemon
     * Input parameters: none
     * Output (prints to screen): nothing
     * Returns: nothing
     */
     void Map::moveWildPokemon() {
        for (int i = 0; i < wildPokemon.size(); i++) {
               int wildDirection = 0;//storage for random movement
               bool sucessfulMove = false;//storage for while loop
               while (sucessfulMove == false){//if the tile isn't valid run it again
                    wildDirection = rand()%4;//randomly generate direction
                    if (wildDirection == 0) {
                         //moves the wild north if the tile is valid
                         if (wildPokemon.at(i).getLocationY() >= 0 && wildPokemon.at(i).getLocationY()-1 <= 24 && map[wildPokemon.at(i).getLocationY()-1][wildPokemon.at(i).getLocationX()] == 'p') {
                              wildPokemon.at(i).setLocationY(wildPokemon.at(i).getLocationY()-1);
                              sucessfulMove = true;
                         }
                         //moves the wild south if the tile is valid
                    } else if (wildDirection == 1) {
                         if (wildPokemon.at(i).getLocationY()+1 >= 0 && wildPokemon.at(i).getLocationY()+1 <= 24 && map[wildPokemon.at(i).getLocationY()+1][wildPokemon.at(i).getLocationX()] == 'p') {
                              wildPokemon.at(i).setLocationY(wildPokemon.at(i).getLocationY()+1);
                              sucessfulMove = true;
                         }
                         //moves the wild east if the tile is valid
                    }else if (wildDirection == 2) {
                         if (wildPokemon.at(i).getLocationX()-1 >= 0 && wildPokemon.at(i).getLocationX()-1 <= 15 && map[wildPokemon.at(i).getLocationY()][wildPokemon.at(i).getLocationX()-1] == 'p') {
                              wildPokemon.at(i).setLocationX(wildPokemon.at(i).getLocationX()-1);
                              sucessfulMove = true;
                         }
                         //moves the wild west if the tile is valid
                    }else if (wildDirection == 3) {
                         if (wildPokemon.at(i).getLocationX()+1 >= 0 && wildPokemon.at(i).getLocationX()+1 <= 15 && map[wildPokemon.at(i).getLocationY()][wildPokemon.at(i).getLocationX()+1] == 'p') {
                              wildPokemon.at(i).setLocationX(wildPokemon.at(i).getLocationX()+1);
                              sucessfulMove = true;
                         }
                    }
               }
          }
     }
          //prints map with P where wild pokemon are
         void Map::printWildPokemon() {
              char tempChar;
          for (int i = 0; i < 25; i++) { //
               for (int j = 0; j <16; j++) {
                    if (map[i][j] == 'p') { //if we are on a land tile
                         bool output = false;
                         for (int k = 0; k < wildPokemon.size(); k++) {
                              if (wildPokemon.at(k).getLocationY() == i && wildPokemon.at(k).getLocationX() == j) {
                                   cout << "P "; //pokemon here
                                   output = true;
                                   break;
                              }
                                  
                         } if (output == false) {
                         cout << "* "; //no pokemon here
                         }
                    } else {
                         tempChar = map[i][j];//get the character at the position
                         if (tempChar == 'w') { //if it's a water position, output ~
                              cout << "~ ";
                         } else if (tempChar == 'p') { //if it's a land position, output *
                              cout << "* ";
                         } else {
                              cout << tempChar << " "; //add a space between
                         }
               }
                         
                    
                    
               }
               cout << endl;
          }
     }