// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 3 - Problem #1

#include <iostream>
using namespace std;

/*
Algorithm - Takes input value and determines if it is odd or even
                if it is even, divides it by two, 
                if it is odd, it multiplies it by 3 and adds 1
Input - a value in the form of an integer
Output - None 
Returns - an integer with the value after the calculation
*/

int collatzStep (int input) {
    if (input%2 == 0 && input > 0) {//Determines if input is even and greater than 0
         return input/2; //returns the number divided by 2
    }
    else if (input%2 == 1 && input > 0) {//Determines if input is odd and greater than 0
        return 3*input+1;//returns the number multiplied by 3 and with 1 added
    } else {
        return 0;//Returns 0 if any other value is entered (for example, a negative number)
    }
}

//Function to call collatzStep as a test
int main(){
    //Test Case 1
    //Expected Result
    //2
    cout << collatzStep(4) << endl;
    
    //Test Case 2
    //Expected Result
    //16
    cout << collatzStep(5) << endl;
}