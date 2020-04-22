// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 3 - Problem #5

#include <iostream>
using namespace std;

/*
Algorithm - Determine what month was entered, and add the corresponding number of days,
            multiply the number of days by 24, to convert days to hours
Input - 1 number in integer form, corresponding to a month
Output - no printed output
Returns - return the total number of hours in the given month
*/
int countHours(int month) {
    
    //declare variables 
    int days = 0;    //intermediate variable for the number of days in the month selected

    switch(month) {
    case 1 : days = 31;//january
    break;
    case 2 : days = 28;//february
    break;
    case 3 : days = 31;//march
    break;
    case 4 : days = 30;//april
    break;
    case 5 : days = 31;//may
    break;
    case 6 : days = 30;//june
    break;
    case 7 : days = 31;//july
    break;
    case 8 : days = 31;//august
    break;
    case 9 : days = 30;//september
    break;
    case 10 : days = 31;//october
    break;
    case 11 : days = 30;//november
    break;
    case 12 : days = 31;//december
    break;
    }
    
    int hours = days*24; //convert days to hours
    
    return hours; //return result
}

//Function to call countHours as a test
int main(){
    //Test Case 1
    //Expected Result
    //672
    cout << countHours(2) << endl;
    
    //Test Case 2
    //Expected Result
    //744
    cout << countHours(5) << endl;
 
}