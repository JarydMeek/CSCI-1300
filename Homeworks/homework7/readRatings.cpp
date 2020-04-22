// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 7 - Problem 4

#include <iostream>
#include <string>
#include <fstream>
#include "User.h"
using namespace std;

/*
* Algorithm: Takes a string and delimiter, and breaks the string into parts on the delimiter, storing the parts in the given array, checks to make sure the parts will fit in the array,
             doesn't count the part if the delimiter is repeated the string, or if the delimiter is at the beginning or end of the string.
* Input parameters: string, character that is the delimiter, an array to store the split parts in, and the size of the given storage array.
* Output (prints to screen): nothing
* Returns: either a -1 if the number of split parts is greater than the size, a zero if the given string is empty, and the number of split parts if neither of the previous are true.
*/
int split(string split, char delimiter, string words[], int size) {
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
* Algorithm: take input file, break it down into lines, and then into strings, then store the first part of the line as the username and the following parts as the ratings
* Input parameters: the string of the file to pull data from, an array of Users, an int for how many users are already stored, and the max rows and columns that the storage array has available
* Output (prints to screen): nothing
* Returns: either a -2 if there is no more space in the array, -1 if the file can't open, or the number of lines added to the array.
*/
int readRatings (string file, User users[], int usersStored, int maxRows, int maxColumns) {
    ifstream importFile; //create the file stream
    importFile.open(file); //open the file passed to the function
    string toSplit = ""; //create temporary storage variable for the line to be split
    string splitRatings[100]; //create array to store the data after it has been split
    int currentLine = usersStored; //create a variable that tracks the number of lines used by the given file
    if (usersStored == maxRows) { //make sure there is room to add any ratings
        return -2; //if there isn't return -2
    }else if (importFile.is_open()) { //if there is room, make sure the file opened successfully
        while (getline(importFile, toSplit)) { //gets the current line, then moves to the next one,
            if (toSplit.length() != 0){ //checks to make sure the line contains data
                if (currentLine < maxRows) { //make sure we aren't going to try to overfill the array we were given
                    int splitted = split(toSplit, ',' , splitRatings, maxRows); //split the line into ints stored as strings
                    users[currentLine].setUsername(splitRatings[0]); //save the first part of the line (the user) as the username
                    for (int i = 1; i < splitted; i++) {
                        users[currentLine].setRatingAt(i-1, (stoi(splitRatings[i]))); //store each string containing an int as a rating.
                    }
                    currentLine++; //count the line that was just completed
                } else {
                    return maxRows; //if array gets filled up output the number of rows filled.
                }
            }
        }
            importFile.close(); //actually close the stream because I'm a good person
            return currentLine; //return the line the function got to.
        
    } else {
        return-1; //return -1 if file couldn't be opened
    }
}
    

//main is in runProblem4.cpp