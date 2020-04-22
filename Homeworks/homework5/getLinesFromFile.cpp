// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 5 - Problem 1

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
* Algorithm: take the given file, and take each int and store it in an array.
* Input parameters: file to open, integer array to store the integers from the file in, and length of that array
* Output (prints to screen): nothing
* Returns: number of integerss saved to array
*/

int getLinesFromFile (string file, int storage[], int length) {
    ifstream importFile; //create the file stream
    importFile.open(file); //open the file passed to the function
    int currentLine = 0; //counter to return when done storing ints
    int toStore = 0; //temporary variable to save later
    
    if (importFile.is_open()) { //makes sure the file opened successfully
        while (importFile >> toStore) { //store the current number to the intermediate variable
            if (currentLine < length) { //make sure we aren't going farther in the function than we have room to store in the array.
                storage[currentLine] = toStore; //store the int to the array
                currentLine++; //move to the next storage spot, adds to the total number of lines saved
            }else {
                break; //end if we don't have any more storage space in the array
            }
        }
        return currentLine; //return the number of ints we saved to the array.
    } else {
        return-1; //return -1 if file couldn't be opened
    }
    importFile.close(); //actually close the stream because I'm a good person
}

//main in order to run test cases.
int main() {
    //Test Case 1 - 
    //Expected Result
    //10
    int arr[10];
    cout << getLinesFromFile("./Input Files/numbers.txt", arr, 10 ) << endl;
    
    //Test Case 2 - 
    //Expected Result
    //-1
    int arr2[10];
    cout << getLinesFromFile("./ThisFolderDoesn'tExistLOL/numbers.txt", arr2, 10 );
    
}