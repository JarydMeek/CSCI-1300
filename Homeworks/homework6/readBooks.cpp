// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 6 - Problem 4

#include <iostream>
#include <string>
#include <fstream>
#include "Book.h"
using namespace std;

/*
* Algorithm: Takes a string and delimiter, and breaks the string into parts on the delimiter, storing the parts in the given array, checks to make sure the parts will fit in the array,
             doesn't count the part if the delimiter is repeated the string, or if the delimiter is at the beginning or end of the string.
* Input parameters: string, character that is the delimiter, an array to store the split parts in, and the size of the given storage array.
* Output (prints to screen): nothing
* Returns: either a -1 if the number of split parts is greater than the size, a zero if the given string is empty, and the number of split parts if neither of the previous are true.
*/
int split(string split, char delimiter, string words[], int size) {
    //variable declaration
    int numSplits = 0;
    int lastSplit = 0;
    
    for (int i = 0; i < split.length(); i++ ) { //loops through all characters in the string
        if (split[i] == delimiter) { //checks if the current character is equal to the given delimeter
            if (i != 0 || i != (split.length()-1)) {  //if it is, checks if the current character is the first or the last character
                if (split.substr(lastSplit, i - lastSplit).length() > 0) { // if it isn't, checks to make sure the string generated isn't empty
                    words[numSplits] = split.substr(lastSplit, i-lastSplit); //if the string will contain data, save that string to the words array in the current array save point
                    numSplits++; //add one to the current array save point
                    lastSplit = i+1; //set the position for the start point of the next substring to be after the previous string and delimeter
                } else {
                    lastSplit++; //if the string generated would have length 0 (two characters back to back), skip that character
                }
            } else if (i==0) {
                lastSplit++; //if the current character matches the delimeter at the first postion, skip it.
            }
        }
    }

    
    words[numSplits] = split.substr(lastSplit, split.length()); //save the string from the final delimeter to the end of the string.

    if (split[split.length()-1] == delimiter) { //checks to make sure that if the delimeter is found at the end of the string to not count it,
    numSplits--;
    }
    
    if (numSplits > size) { //if the number of delimiters found is greater than the size given, return -1
        return -1;
    } else if (split.length() == 0) { //if the string is empty, return 0
        return 0;
    } else{
        return numSplits+1; // otherwise, return the number of demimeters +1 (+1 since there is text after the final delimeter)
    }
} 

/*
* Algorithm: open file given in the parameters into the file stream
            first check to make sure the starting number of books in the array is less than the storage we are given, if it isn't return -2
            if we can store the number of books given, take the given file, split a line into an string, then split the string on the comma which divides the string into author and book title, 
            then store each part of the book information into the array of books.
            finally if we can't open the file, return -1
* Input parameters: file to open, an array to store titles in, an array to store authors in, an int for the number of books we need to store, and an int for the size of the storage that we have been passed
* Output (prints to screen): nothing
* Returns: a -2 if the book number we should start reading from is greater than the storage we have, or a -1 if unable to open the file give, otherwise the number of books stored
*/
int readBooks (string fileName, Book books[], int numBooksStored, int booksSize) {
    //open file
    ifstream importFile; //create the file stream
    importFile.open(fileName); //open the file passed to the function
    
    //process file 
    if (numBooksStored >= booksSize) { //checks to make sure that the array isn't already full as given from the problem
        return -2; //if there isn't space, return -2
    } else if (importFile.is_open()){ //check to make sure the file is open
        string toSplit = ""; //storage string to pass to the split() function
        string singleBook[2]; //array to pass to the split() function for storage
        int currentLine = numBooksStored; //start checking books after the number of books passed to the function
        // read each line from the file 
        while (getline(importFile, toSplit)) { //save each line to the storage variable
            if (currentLine < booksSize){ // make sure that we still have storage remaining 
                if (toSplit.length() != 0) { //make sure the line isn't empty
                split(toSplit, ',', singleBook, 2); //split the line on the comma
                books[currentLine].setAuthor(singleBook[0]); //store the current author to the correct place in the class
                books[currentLine].setTitle(singleBook[1]);//store the current book to the correct place in the class
                currentLine++; //add one to the current line tracker
                }
            }
        }
        return currentLine; //return the number of lines
    } else {
        return -1;
    }
    importFile.close(); //actually close the stream because I'm a good person
}


int main() {
    //Test Case 1
    //Expected Output -
    //Function returned value: 50
    Book books[50];
    int numbooks = readBooks("./Given Files/books.txt", books, 0, 50);
    cout << "Function returned value: " << numbooks << endl;
    
    //Test Case 2
    //Expected Output -
    //Function returned value: -2
    Book books2[10];
    int numbooks2 = readBooks("./Given Files/books.txt", books2, 10, 10);
    cout << "Function returned value: " << numbooks2 << endl;
    
    //Test Case 3
    //Expected Output -
    //Function returned value: -1
    Book books3[50];
    int numbooks3 = readBooks("./Given Files/ThisFileDoesn'tExist.txt", books3, 0, 50);
    cout << "Function returned value: " << numbooks3 << endl;
}