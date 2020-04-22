// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 3 - Problem #6

#include <iostream>
using namespace std;

/*
Algorithm - Determine if the year is before or after 1582 (the year that there was a calendar correction)
                If the year is above 1582
                    if it is divisible by 4, set the output to true
                    if it is divisible by 100 and not 400, set the output to false
                If the year is not above 1582
                    if it is divisible by 4, set the output to true
Input - 1 number in integer form, corresponding to a year
Output - no printed output
Returns - return true if the year is a leap year, and false if it is not.
*/
bool checkLeapYear(int year) {
    
    //Declare Variables
    bool output = false; //output variable storage
    //Process
    if (year >= 1582) { //checks if year is above 1582
         if (year % 4 == 0) { //if it is, is the year divisible by 4?
            output = true;  //if it is, it is a leap year.
        }
        if (year % 100 == 0 && year % 400 != 0) { //is the year on the 100 year mark, but not at the 400 year mark?
            output = false; //if it is, it is not a leap year
        }
    }
    if (year < 1582) { //if the year is above 1582
        if (year % 4 == 0) { //if the year is divisible by 4
            output = true; // it is a leap year.
        }
    }
return output; //return output storage variable
}

//Function to call checkLeapYear as a test
int main(){
        
    //Test Case 1
    //Expected Result
    //false
    cout << checkLeapYear(1959);
        
    //Test Case 2
    //Expected Result
    //true
    cout << checkLeapYear(2004);
}