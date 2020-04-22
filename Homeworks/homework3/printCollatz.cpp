// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 3 - Problem #7

#include <iostream>
using namespace std;
/*
Algorithm - Determine if the entered value is valid, if it is invalid, return "invalid number"
                as long as the number is above 1 repeat
                    if the number is even
                        divide it by 2 and store the output back into the currentValue variable
                    if it is odd
                        multiply the number by 3 and add 1, then store back into currentValue variable
Input - 1 number in integer form
Output - print each step of the Collatz process, or invalid number if the input is invalid
Returns - no return
*/
void printCollatz(int starting) {
    
    //Declare Variables
    int currentValue;
    
    //Verifies that the starting number is greater than 0
    if (starting > 0) { 
        currentValue = starting; //sets the input variable equal to our changing variable to keep it neater
        while (currentValue > 1) { //checks to make sure the value is 1 and repeats as long as it is.
            cout << currentValue << " "; // output the current value, and a space
            if (currentValue % 2 == 0 ) { //if the value is divisible by 2, divide it by 2 and store that
                currentValue = currentValue / 2;
            } else if (currentValue % 2 != 0) { //if the value is not divisible by 2 mulitply it by 3 add 1 and store that.
                currentValue = (currentValue*3)+1;
            }
        }
        cout<< currentValue; //output the final value (always a 1)
    } else {
        cout << "invalid number";//output if the entered value is invalid
    }
}

//Function to call printCollatz as a test
int main(){
    //Test Case 1
    //Expected Result
    //4 2 1
    printCollatz(4);
    
    cout << endl; //add a new line to make the output look prettier
    
    //Test Case 2
    //Expected Result
    //5 16 8 4 2 1
    printCollatz(5);
    
}