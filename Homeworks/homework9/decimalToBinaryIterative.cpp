// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 9 - Problem 1

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
* Algorithm: Takes an integer and converts it to binary with loops
* Input parameters: int to convert to binary
* Output (prints to screen): nothing
* Returns: the binary equivalent of the integer.
*/
string decimalToBinaryIterative(int startingInt) {
    string storage; //temporary storage (before flipping)
    string output; //string to output after flipping
    if (startingInt == 0) { //if 0 is entered
        storage = "0"; //output 0
    }
    int processing = startingInt; //create temporary variable and store the input variable to it.
    while (processing > 0) { //repeat while the temp varaible is greater than 0
       storage = storage + to_string(processing % 2); //if 0 is divisible by 2 add a 0 to the string storage, and if it isn't add 1 to the output
       processing = processing/2; //divide the temp variable by 2, to move to the next position
    }
    for (int i = storage.length()-1; i >= 0; i--) { //flip the storage string and store to the output string
        output = output + storage[i];
    }
    return output; //return the output string
}

//main in order to run test cases.
int main() {
    //Test case 1
    //Expected Output
    //1010
    cout << decimalToBinaryIterative(10) << endl;

    //Test case 2
    //Expected Output
    //10111101
    cout << decimalToBinaryIterative(189) << endl;
}