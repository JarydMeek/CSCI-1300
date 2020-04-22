// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Project 1 - Problem 4

#include <iostream>
#include <string>
using namespace std;

/*
* Algorithm: First check that the strings are the same length and that they are not 0, if they aren't the same length or one of them is 0, output 0
            Then go letter by letter for the length of the strings comparing the strings to make sure they are the same letter
            if they aren't, add one to a storage variable
            Calculate the simularity score
* Input parameters: Two strings to compare
* Output (prints to screen): nothing
* Returns: similarity score between 0 and 1 in the form of a double
*/

double calcSimScore(string first, string second) {
    int differences = 0; //storage variable for the number of positions that don't match
    
    if (first.length() == second.length() && first.length() != 0) { //make sure the lengths are the same and neither is 0
        for (int i = 0; i < first.length(); i++) { //count from zero to the length of the strings
            if (first[i] != second[i]) { //check that the letters at the current position don't match
                differences++; //if they don't add one to the output
            }
        }
        return (double) (first.length()-differences)/first.length(); //calculate then return the similarity score
    } else {
        return 0; //return zero if the lengths are different or one is zero
    }
}

//main in order to run test cases.
int main() {
    //Test Case 1
    //Expected Result
    //1
    cout << calcSimScore("ACCG", "ACCG") << endl;
    
    //Test Case 2
    //Expected Result
    //0.5
    cout << calcSimScore("ACCG", "ACGT") << endl;
    
}