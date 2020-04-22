// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 9 - Problem 2

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
/*
* Algorithm: Takes an integer and converts it to binary recursively
* Input parameters: int to convert to binary
* Output (prints to screen): nothing
* Returns: the binary equivalent of the integer.
*/
string decimalToBinaryRecursive(int startingInt) {
    string storage; //temporary storage (before flipping)
    string output; //string to output after flipping
    int processing = startingInt;
    if (startingInt == 0) { //if 0 is entered
        output = "0"; //output 0 
    } else {
        output = to_string(processing % 2); //if the number is divisible by 2 add a 0 to the output storage
        return decimalToBinaryRecursive(processing /2) + output; //recurse and add the current value to the output
    }
    return output;
}

//main in order to run test cases.
int main() {
    //Test case 1
    //Expected Output
    //01010
    cout << decimalToBinaryRecursive(10);

    cout << endl;

    //Test case 2
    //Expected Output
    //010111101
    cout << decimalToBinaryRecursive(189);
}