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
void printSeriesSkipFour(int maxValue){
    int sum = 0;
    int i = 1;
    while (i <= maxValue){
        if (i%4 != 0){
            // If the number is not divisible by 4, add it to sum and print
            cout << i;
            sum += i;
        }
        else {
            // Print 0 when number is divisible by 4
            cout << "0";
        }
        if (i != maxValue){
            // This check is added to not print the last '+'
            cout << " + ";
        }
        i++;
    }
    cout << endl;
    cout << "Result of the series is " << sum << endl;
}


//main in order to run test cases.
int main() {
    
    printSeriesSkipFour(20);
    
}