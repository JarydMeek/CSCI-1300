// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 4 - Problem 4

#include <iostream>
#include <iomanip>
using namespace std;

/*
* Algorithm: Take the given integer array and swap the first and last values.                                                                                                                                                                                                                                                                                                                                                                                                                                             ```                                         ``````  
* Input parameters: array of integers, length of array
* Output (prints to screen): nothing
* Returns: nothing
*/
void swapFirstLast(int input[], int length) {
    int storage = 0; //create storage variable
    storage = input[0]; //save the first number in the array to the storage variable
    input[0] = input[length-1]; // set the first number in the array to the last number in the array
    input[length-1] = storage; //set the last number in the array to the storage variable (which is the original first number in the array.)
}

//main in order to run test cases.
int main() {
    //Test Case 1
    //Expected Result
    //9
    //1
    //2
    //3
    //4
    //5
    //6
    //7
    //8
    //0
    int arr[] = {0,1,2,3,4,5,6,7,8,9}; 
    int len = 10;
    swapFirstLast(arr, len); //run function
    for (int i = 0; i < len; i++) { //output the array after the function runs
    cout << arr[i] << endl;
    }
    cout << endl; // add an extra space
    
    //Test Case 2
    //Expected Result
    //10
    //23
    //20
    //5
    int arr2[] = {10,20,23,5}; 
    int len2 = 4;
    swapFirstLast(arr2, len2); //run function
        for (int j = 0; j < len2; j++) { //output the array after the function runs.
    cout << arr2[j] << endl;
    }
}