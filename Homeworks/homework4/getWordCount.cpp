// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 4 - Problem 5

#include <iostream>
#include <iomanip>
using namespace std;

/*
* Algorithm: Takes string input and first checks if the string is empty
             If it is, return 0
             If it isn't, count the number of spaces in the string
             Return the number of spaces plus 1 (for the total number of words)
* Input parameters: string
* Output (prints to screen): nothing
* Returns: the number of words in the string
*/
int getWordCount(string input) {
    int spaces = 0; // storage variable declaration
    if (input.length()==0) { //check if string is empty, if it is return 0
        return 0;
    } else if (input.length()!=0) { //make sure string has something in it
        for (int i = 0; i < input.length(); i++) { //check the string for hte number of spaces it has
            if (input[i] == ' ') {
                spaces++; //add one for every space found
            }
        }
    return spaces+1; //return 1 plus the number of spaces, for the number of words
    }
}

//main in order to run test cases.
int main() {
    //Test Case 1
    //Expected Result
    //0
    string test = "";
    cout << getWordCount(test); //run function
   
    
    //Test Case 2
    //Expected Result
    //9
    string test2 = "The quick brown fox jumps over the lazy dog";
    cout << getWordCount(test2); //run function
}