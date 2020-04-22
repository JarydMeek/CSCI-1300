#include "Team.h"
#include <fstream>
#include <vector>
using namespace std;

/*
* Algorithm: Takes a string and delimiter, and breaks the string into parts on the delimiter, storing the parts in the given array, checks to make sure the parts will fit in the array,
             doesn't count the part if the delimiter is repeated the string, or if the delimiter is at the beginning or end of the string.
* Input parameters: string, character that is the delimiter, an array to store the split parts in, and the size of the given storage array.
* Output (prints to screen): nothing
* Returns: either a -1 if the number of split parts is greater than the size, a zero if the given string is empty, and the number of split parts if neither of the previous are true.
*/
int Team::split(string split, char delimiter, string words[], int size) {
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
        return -1;
    } else if (split.length() == 0) { //if the string is empty, return 0
        return 0;
    } else{
        return numSplits+1; // otherwise, return the number of demimeters +1 (+1 since there is text after the final delimeter)
    }
} 
//Default constructor
Team::Team() {
    teamName = "";
}
//Parameterized constructor
Team::Team(string newTeamName) {
    teamName = newTeamName;
}
//Setter for team name
void Team::setTeamName(string newTeamName){
    teamName = newTeamName;
}
/*
* Algorithm: takes a filename, and adds the players to the team (with scores).
* Input parameters: filename
* Output (prints to screen): nothing
* Returns: nothing
*/
void Team::readRoster(string fileName){
    ifstream importFile; //create the file stream
    importFile.open(fileName); //open the file passed to the function
    int numPlayers = 0;
    string toSplit = ""; //create temporary storage variable for the line to be split
    string splitted[2]; //create array to store the data after it has been split
    if (importFile.is_open()) { //if there is room, make sure the file opened successfully
        while (getline(importFile, toSplit)) { //save each line to the storage variable
            Player tempPlayer;
            split(toSplit, ',', splitted, 2);
            tempPlayer.setName(splitted[0]);
            tempPlayer.setPoints(stod(splitted[1]));
            players.push_back(tempPlayer);
            numPlayers++;
        }
    }
}
//getter for player name
string Team::getPlayerName(int input){
    if (input >= 0 && input < players.size()) { //if the index passed to function is valid
        return players[input].getName(); //return the player name
    } else {
        return "ERROR"; //if the index is invalid, return "ERROR"
    }

}
//getter for player points
double Team::getPlayerPoints(int input){
    if (input >= 0 && input < players.size()) { //if the index passed to function is valid
        return players[input].getPoints();//return the player's points
    } else {
        return -1; //if the index is invalid, return -1
    }
    
}
//getter for number of players
int Team::getNumPlayers(){
    return players.size();
}
//getter for team name
string Team::getTeamName(){
    return teamName;
}


