// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 3 - Problem #9

#include <iostream> 
using namespace std;
/*
Algorithm - Count by odd numbers from 1 to entered number with a for loop
Input - 1 number in integer form
Output - print each odd number starting from one counting until the entered number
Returns - no return
*/
int printOddNumsFor(int starting) {
    for(int i = 1; i < starting; i=i+2) {// count from 1 to the entered value adding 2 to the current value each loop 
        cout << i << endl; //output the current number
    }
}

//Function to call printOddNumsFor as a test
int main(){
    //Test Case 1
    //Expected Result
    //1 3 5 7 9 11 13 15
    cout << printOddNumsFor(15) << endl;
 
    //Test Case 2
    //Expected Result
    //1 3 5
     cout << printOddNumsFor(5) << endl;
}