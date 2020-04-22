// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 3 - Problem #2

#include <iostream>
using namespace std;

/*
Algorithm - Takes input value and determines if they are all the same, all different, or neither.
                Test if the three values are equal
                    If they are, output "All same"
                Test if all three values are different
                    If they are, output "All different"
                If neither of the above are true, output "Neither"
Input - 3 values in the form of integers
Output - Different strings based on the values of the three numbers and how similar and different they are.
Returns - no returns
*/

//Problem
void checkEqual(int inputOne,int inputTwo, int inputThree) {
    //calculations
    if (inputOne == inputTwo && inputTwo == inputThree) {//Check if the three values are equal
        cout << "All same";//If they are, output "All Same"
    } else if (inputOne != inputTwo && inputTwo != inputThree && inputOne != inputThree) {//Check if the three values are different
        cout << "All different";//If they are, output "All Different"
    }else {
       cout<< "Neither";//Output "Neither" if neither of the above are true
    }
}

//Function to call checkEqual as a test
int main(){
    
    //Test Case 1
    //Expected Result
    //All Different
    checkEqual(5, 8, 19);
 
    //Test Case 2
    //Expected Result
    //All Same
    checkEqual(8, 8, 8);
}