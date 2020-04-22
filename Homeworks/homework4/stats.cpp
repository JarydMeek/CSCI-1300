// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 4 - Problem 3

#include <iostream>
#include <iomanip>
using namespace std;

/*
* Algorithm: Take the given double array and find the minimum, maximum and average of all the doubles in the given array                                                                                                                                                                                                                                                                                                                                                                                                                                              ```                                         ``````  
* Input parameters: array of doubles, length of array
* Output (prints to screen): the minimum, maximum, and the average (TO TWO DECIMAL PLACES)
* Returns: nothing
*/
void stats (double input[], int length) {
    double min = input[0]; //create the variable to store the min
    double max = input[0]; //create the variable to store the max
    double total = 0; //create the variable to store the total of all the numbers
    for (int i = 0; i < length; i++) { //check every number in the string
        if (input[i] < min) { //if the current number is smaller than the minimum we have, store it
            min = input[i]; 
        } else if (input[i] > max) //if it isn't the minimum value, check if it is the maximum, if it is, store it as the max.
            max = input[i];
    }
    for (int i = 0; i < length; i++) { // add up all the numbers in the string
        total = total+input[i];
    }
    cout << fixed << showpoint; // prepare to output with 2 decimal places
    cout << setprecision(2) << "Min: " << min << endl; //output min
    cout << setprecision(2) << "Max: " << max << endl; //output max
    cout << setprecision(2) << "Avg: " << (total/length) << endl; //calculate and output the avg
}

//main in order to run test cases.
int main() {
    //Test Case 1
    //Expected Result
    //Min: 0.00
    //Max: 9.00
    //Avg: 4.50
    double arr[] = {0.00,1.00,2.00,3.00,4.00,5.00,6.00,7.00,8.00,9.00}; 
    double len = 10.00;
    stats(arr, len);
    
    //Test Case 2
    //Expected Result
    //Min: 4.00
    //Max: 23.00
    //Avg: 14.25
    double arr2[] = {10.00,20.00,23.00,4.00}; 
    double len2 = 4.00;
    stats(arr2, len2);
}