// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 4 - Problem 1

#include <iostream>
using namespace std;

/*
* Algorithm: Creates the 4 strings necessary, fills them with the requred data, and outputs them to the console
* Input parameters: None
* Output (prints to screen): The values stored in the 4 arrays
* Returns: None
*/

//main in order to run test cases.
int main() {

    //TEMPS ARRAY
    //Creation and assigning values
    double temps[10]; //Create Array of size 10
    for (int i = 0; i<10; i++) { //fill all 10 positions in the array with the temperature given.
        temps[i] = -459.67;
    }
    //Output
    for (int i = 0; i < 10; i++) {
        cout << temps[i] << endl; //outputs all 10 letters.
    }
    
    cout << endl; //Create blank line
    
    //COLORS ARRAY
    //Creation and assigning values
    string colors [] = {"Red", "Blue", "Green", "Cyan", "Magenta"}; //Create Array and fill it with the 5 colors given
    //Output
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << colors[i] << endl; //output all 5 colors
    }
    
    cout << endl; //Create blank line
    
    //SEQUENCE ARRAY
    //Creation and assigning values
    int sequence[100]; //create array of size 100
    for (int i = 0; i<100; i++) { 
        sequence[i] = i+1; //fill each position of the array with a separate integer from 1-100
    }
    //Output
    for (int i = 0; i < 100; i++) {
        cout << sequence[i] << endl; //output numbers 1-100 on a new line per integer
    }
    
    cout << endl; //Create blank line
    
    //LETTERS ARRAY
    //Creation and assigning values
    char letters[52]; //create array "letters" of size 52.
    int j = 0; //create extra variable that will count from 0 - 26
    for (int i = 0; i <52; i++) { //count from 0 to 52
        if (i % 2 == 0) { //if the position is even
            letters[i] = j + 65; // put in the next capital letter
        } else {
            letters[i] = j + 97; // put in the next lowercase letter
            j++; //add 1 to the extra variable
        }
    }
    //Output
    for (int i = 0; i < 52; i = i+2) {
        cout << letters[i] << " " << letters[i+1] << endl; //outputs capital letters, a space, then the lowercase letter 
    }
    
    
}