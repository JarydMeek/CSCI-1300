// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 4 - Problem 2

#include <iostream>
using namespace std;

/*
* Algorithm: Take the given integer array and output it to console in the reverse order of the array                                                                                                                                                                                                                                                                                                                                                                                                                                              ```                                         ``````  
* Input parameters: array of integers, length of array
* Output (prints to screen): the array entered in the reverse order
* Returns: nothing
*/
void printArrReverse (int input[], int length) {
    for (int i = length-1; i >= 0; i--) {//counts from the end of the array to the start
        cout << input[i] << endl; // outputs int in current positiom
    }
}

//main in order to run test cases.
int main() {
    //Test Case 1
    //Expected Result
    //9
    //8
    //7
    //6
    //5
    //4
    //3
    //2
    //1
    //0
    int arr[] = {0,1,2,3,4,5,6,7,8,9}; 
    int len = 10;
    printArrReverse(arr, len);
    
    //Test Case 2
    //Expected Result
    //4
    //23
    //20
    //10
    int arr2[] = {10,20,23,4}; 
    int len2 = 4;
    printArrReverse(arr2, len2);
}