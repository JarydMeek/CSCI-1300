// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Project 1 - Problem 2

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*
* Algorithm: convert money from U.S. Dollars (USD) to Euros.
* 1. Take the value of number of dollars involved
* in the transaction.
* 2. Current value of 1 USD is equal to 0.86 euros
* 3. Multiply the number of dollars got with the
* currency exchange rate to get Euros value
* 4. Return the computed Euro value
* Input parameters: Amount in USD (double)
* Output (prints to screen): nothing
* Returns: Amount in Euros (double)
*/
void ordinalText (int num) {
    //declare variables 
    switch(num) {
    case 0 : cout << num << "";//january
    break;
    case 1 : cout << num  << "st";//february
    break;
    case 2 : cout << num  << "nd";//march
    break;
    case 3 : cout << num  << "rd";//april
    break;
    case 4 : cout << num  << "th";//may
    break;
    case 5 : cout << num  << "th";//may
    break;
    case 6 : cout << num  << "th";//may
    break;
    case 7 : cout << num  << "th";//may
    break;
    case 8 : cout << num  << "th";//may
    break;
    case 9 : cout << num  << "th";//may
    break;
    }
}


//main in order to run test cases.
int main() {
    
    
    
}