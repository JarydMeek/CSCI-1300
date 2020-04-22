// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 3 - Problem #10

#include <iostream> 
using namespace std;

/*
Algorithm - First adds the correct number of column's worth of "+--" based on the number entered. 
                adds a "+" to cap the end of the first row
            adds the correct number of column's worth of "|  " based on the number entered.
                adds a "|" to cap the end of the next row
            repeats the above to add the correct number of rows corresponding to the number entered
            Caps the above off withe the correct number of "+--" and "+" to complete the final row
Input - 1 number in integer form
Output - Printed chart with number of rows and collumns corresponding to the number entered
Returns - no return
*/

//Problem
void printGrid(int input) {
    if (input > 0) { //makes sure the input is valid
        for (int j = 0; j < input; j++) { //repeats both of the following to create the correct number of rows
            for (int i = 0; i < input; i++) { //repeats to create the correct number of collumns of "+--"
            cout << "+--";
                }
                cout << "+" << endl; // caps the row off with a "+"
            for (int i = 0; i < input; i++) { //repeats to create the correct number of collumns of "|  "
                cout << "|  ";
            }
                cout << "|" << endl; // caps the row off with a "|"
        }
        for (int i = 0; i < input; i++) { //adds the final row of "+--+"
         cout << "+--";
        }
        cout << "+" << endl;
    } else {
        cout << "The grid can only have a positive number of rows and columns.";//error if value entered was not valid
    }
    
}

//Function to call printGrid as a test
int main(){
    //Test Case 1
    //Expected Result
    /*
    +--+--+--+--+--+
    |  |  |  |  |  |
    +--+--+--+--+--+
    |  |  |  |  |  |
    +--+--+--+--+--+
    |  |  |  |  |  |
    +--+--+--+--+--+
    |  |  |  |  |  |
    +--+--+--+--+--+
    |  |  |  |  |  |
    +--+--+--+--+--+
    */
    printGrid(5);
    
    cout << "\n \n \n";
    //Test Case 2
    //Expected Result
    /*
    +--+
    |  |
    +--+
    */
    printGrid(1);
 
}