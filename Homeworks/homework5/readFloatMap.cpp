// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 5 - Problem 6

#include <iostream>
#include <string>
#include <fstream>
using namespace std;



/*
* Algorithm: Takes a string and delimiter, and breaks the string into parts on the delimiter, storing the parts in the given array, checks to make sure the parts will fit in the array,
             doesn't count the part if the delimiter is repeated the string, or if the delimiter is at the beginning or end of the string.
* Input parameters: string, character that is the delimiter, an array to store the split parts in, and the size of the given storage array.
* Output (prints to screen): nothing
* Returns: either a -1 if the number of split parts is greater than the size, a zero if the given string is empty, and the number of split parts if neither of the previous are true.
*/
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
        return -1;
    } else if (split.length() == 0) { //if the string is empty, return 0
        return 0;
    } else{
        return numSplits+1; // otherwise, return the number of demimeters +1 (+1 since there is text after the final delimeter)
    }
} 




/*
* Algorithm: take input file, and break it down by doubles into a 2d array.  if the file can't be opened, will return -1
* Input parameters: the file to break down, an array to store the doubles after breaking down, and the number of rows to break down
* Output (prints to screen): nothing
* Returns: the number of lines added to the array after filling the number passed to the function
*/
int readFloatMap (string fileName, double storageArray[][4], int rows) {
    ifstream importFile; //create the file stream
    importFile.open(fileName); //open the file passed to the function
    string toSplit = ""; //create temporary storage variable for the line to be split
    string doubleInLine[4]; //create array to store the data after it has been split
    int currentLine = 0; //create a variable that tracks the number of lines used by the given file
    if (importFile.is_open()) { //makes sure the file opened successfully
        while (getline(importFile, toSplit)) { //gets the current line, then moves to the next one,
        if (toSplit.length() == 0) { //makes sure the line isn't empty, if it is return 0
            return 0; 
        } else if (currentLine < rows) { //if the line isn't empty
                split(toSplit, ',' , doubleInLine, 4); //split the line into doubles stored as strings
                for (int i = 0; i < 4; i++) {
                    storageArray[currentLine][i] = stod(doubleInLine[i]); //store each string containing a double as a double in the storage array
                }
                currentLine++; //count the line that was just completed
            }

        }
        importFile.close(); //actually close the stream because I'm a good person
        return currentLine; //return the line the function got to.
    } else {
        return-1; //return -1 if file couldn't be opened
    }

}
    

//main in order to run test cases.
int main() {
    //Test Case 1
    //Expected Output 
    //Function returned: 2
    //3.11, 3.2, 0.85, 1.18, 
    //4.07, 0.84, 1.98, 1.24, 
    double floatMap[2][4];
    int x = readFloatMap("./Input Files/floodMap.txt", floatMap, 2);
    cout << "Function returned: " << x << "\n";
    for(int i = 0; i < 2; i++){
        for (int j = 0; j < 4; j++) {
            cout << floatMap[i][j] << ", ";
        }
        cout << "\n";
    }
    //make a spacer
    cout << endl;
    //Test Case 1
    //Expected Output 
    //Function returned: -1
    double floatMap2[2][4];
    int x2 = readFloatMap("./Input Files/ThisFileDoesn'tExist.txt", floatMap2, 2);
    cout << "Function returned: " << x2 << "\n";
  
}