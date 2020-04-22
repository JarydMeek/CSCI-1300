// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 3 - Problem #8

#include <iostream>
using namespace std;

/*
Algorithm - Count by odd numbers from 1 to entered number with a while loop
Input - 1 number in integer form
Output - print each odd number starting from one counting until the entered number
Returns - no return
*/
int printOddNumsWhile(int starting) {
    int currentValue = 1; //sets the first number to 1
    while (currentValue < starting) { //checks that the current number never gets above the maximum given to us
        cout << currentValue << endl; //outputs the current value
        currentValue = currentValue +2; //adds 2 to the current value to get to the next odd number
    }
}

//Function to call printOddNumsWhile as a test
int main(){
    
    //Test Case 1
    //Expected Result
    //1 3 5 7 9 11
    cout << printOddNumsWhile(11) << endl;
 
    //Test Case 2
    //Expected Result
    //1 3 5
     cout << printOddNumsWhile(5) << endl;
}