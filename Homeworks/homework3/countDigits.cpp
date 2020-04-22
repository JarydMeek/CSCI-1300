// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 3 - Problem #4

#include <iostream>
using namespace std;

/*
Algorithm - Takes input and if 0 is entered, return the value 1
                otherwise while the value can be divided by 10, add 1 to the output
                return the final value
Input - 1 number in integer form
Output - no printed output
Returns - return the number of digits in the value entered
*/
int countDigits(int input) {
    //Declare output variable
    int output = 0;

    //Process
    if (input == 0) { //check if the input is 0, if it is, return 1
        return 1;
    } else {
        while (input != 0) { //otherwise check that the value is not zero, if it is dividie it by ten, and add 1 to the output value
        input /= 10;
        output ++;
        }
    }

    return output; //return the result of the calculation
}

//Function to call countDigits as a test
int main(){
    //Test Case 1
    //Expected Result
    //1
    cout << countDigits(2) << endl;
 
    //Test Case 2
    //Expected Result
    //4
    cout << countDigits(2234) << endl;
}