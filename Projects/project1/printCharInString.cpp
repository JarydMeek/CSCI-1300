// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Project 1 - Problem 1

#include <iostream>
#include <string>
using namespace std;

/*
* Algorithm: Determine first if the string entered is empty or not, 
                If empty, output message stating that the string is empty
                If full, output each letter on a diffrerent line
* Input parameters: String to be broken down by letter (or empty)
* Output (prints to screen): Either an error as the string is empty, or the word split out letter by letter.
* Returns: nothing
*/
void printCharInString(string input) {
    if (input.length()==0) {//make sure the length is greater than 0
        cout << "Given string is empty!";// if it isn't output an error
    } else {
        for (int i = 0; i < input.length(); i++) {//if it is, begin a loop that prints each letter for the entirety of the word.
            cout << input[i] << endl;//output current letter before advancing
        }
    }
}


//main in order to run test cases.
int main() {
    //Test Case 1
    //Expected Result
    //t
    //e
    //s
    //t
    printCharInString("test");
    
    //Test Case 2
    //Expected Result
    //Given string is empty!
    printCharInString("");
    
}