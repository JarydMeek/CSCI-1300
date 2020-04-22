// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 4 - Problem 7 (EC)

#include <iostream>
#include <iomanip>
using namespace std;

/*
* Algorithm: take the given array and shift it down by the number of shifts given.                                                                                                                                                                                                                                                                                                                                                                                                                                             ```                                         ``````  
* Input parameters: array of integers, size of array, number of shifts
* Output (prints to screen): nothing, except for an error if shifts is zero or negative
* Returns: nothing
*/
void shiftElements(int input[], int size, int shifts) {
    int storage = 0; //create storage variable
    if (shifts > 0){ //make sure shifts is positive, and non-zero
        for (int i = 0; i < shifts; i++) { //for loop to repeat the single shift for the number of shifts given
            storage = input[size-1]; // store the last integer in the array to our storage variable
            for (int i = size-1; i > 0; i--) { //for loop to go through the entire arrar
                input[i] = input[i-1]; //set the current position in the array equal to the previous one, starting from the end and going to the beginning
            }
            input[0] = storage; //set the first position equal to what was the last int in the array, before the shift
        } 
    } else {
        cout << "No Shift" << endl; //output error if negative or zero
    }
}

//main in order to run test cases.
int main() {
    //Test Case 1
    //Expected Result
    //3
    //4
    //5
    //1
    //2
    int arr[] = {1,2,3,4,5}; 
    shiftElements(arr, 5, 3); //run function
    for (int i = 0; i < 5; i++) { //output the array after the function runs
    cout << arr[i] << endl;
    }
    cout << endl; // add an extra space
    
    //Test Case 2
    //Expected Result
    //No Shift
    //1
    //2
    //3
    //4
    //5
    int arr2[] = {1,2,3,4,5}; 
    shiftElements(arr2, 5, -2); //run function
    for (int i = 0; i < 5; i++) { //output the array after the function runs
    cout << arr2[i] << endl;
    }
    cout << endl; // add an extra space
}