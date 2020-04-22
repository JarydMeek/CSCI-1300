// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Practicum 2 - Problem 1

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

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
        return -1;
    } else if (split.length() == 0) { //if the string is empty, return 0
        return 0;
    } else{
        return numSplits+1; // otherwise, return the number of demimeters +1 (+1 since there is text after the final delimeter)
    }
} 

int calcPastries(string fileName) {
    int currentLine = 0;
    string words[3];
    string toSplit;
    float total = 0;
    ifstream importFile; //create the file stream
    importFile.open(fileName); //open the file passed to the function
    if (importFile.is_open()) { //makes sure the file opened successfully
        while (getline(importFile, toSplit)) { //gets the current line, then moves to the next one,
            if (toSplit.length() != 0){ //checks to make sure the line contains data
                currentLine++;
                split(toSplit, ',', words, 4);
                float quantity = stof(words[1]);
                float price = stof(words[2]);
                total = total + (quantity*price);
                cout << words[0] << ": " << (quantity*price) << endl;
            }
        
        }
        cout << "Total: " << total << endl;
        return currentLine; //return the number of ints we saved to the array.
    }else {
        return-1; //return -1 if file couldn't be opened
    }
    importFile.close(); //a
}


//main in order to run test cases.
int main() {

}