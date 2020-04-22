// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 5 - Problem 5

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


/*
* Algorithm: check the given 2d array to see if each value in the array is larger than the value passed to the function, if it is, output a "_" if it isn't, output a "*"
* Input parameters: a 2d array of doubles, signifing height in a given area, an int of the number of rows in the array passed to the function, and a value to compare to.
* Output (prints to screen): either a "_" or a "*" based on the height given
* Returns: nothing
*/
void floodMap (double input[][4], int numRows, double waterLevel) {
    for (int i = 0; i < numRows; i++) { //loop through moving down a row each loop
        for (int j = 0; j < 4; j++) {   //loop through moving down a column each loop
            if (input[i][j] > waterLevel) { //check if the current cell of the array is greater than the given water level
                cout << "_"; //if it is, output _
            } else {
                cout << "*"; //if it isn't output *
            }
        }
        cout << endl; //once it finishes the 4 columns, move the output to the next row
    }
}

//main in order to run test cases.
int main() {
    //Test Case 1
    //Expected Output 
    //*_*_
    //_*_*
    //*_*_
    //***_
    double map[4][4] = {{5.9064, 15.7541, 6.11483, 11.3928}, 
    {16.8498, 5.736, 9.33342, 6.36095}, 
    {3.18645, 16.935, 4.7506, 9.63635}, 
    {2.22407, 0.815145, 0.298158, 13.466}};
    floodMap(map, 4, 9.3);
    //make a spacer
    cout << endl;
    //Test Case 2
    //Expected Output 
    //_***
    //*_*_
    double map2[2][4] = {{12.6326, 1.4787, 8.57927, 6.81492},
    {4.53957, 15.245, 1.18922, 11.9867}};
    floodMap(map2, 2, 9.3);

}