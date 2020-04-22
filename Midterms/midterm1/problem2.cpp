// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Project 1 - Problem 2

#include <iostream>
#include <string>
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
double smallestNumber (double inOne, double inTwo, double inThree) {
    if (inOne < inTwo && inOne < inThree) {
        return inOne;
    } else if (inTwo < inOne && inTwo < inThree) {
        return inTwo;
    } else if (inThree < inTwo && inThree < inOne) {
        return inThree;
    } 
    
}


//main in order to run test cases.
int main() {
    
    
    
}