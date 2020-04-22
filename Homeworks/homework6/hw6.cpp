// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 6 - Problem 7

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



/*
* Algorithm: chjeck to make sure that there are books stored, if there are, print the title and author for the number of books given.
* Input parameters: titles array, authors array, and number of books to print
* Output (prints to screen): "here is a list of books" then the list of books, or "no books are stored"
* Returns: none
*/
void printAllBooks(Book books[], int numberBooks) {
    if (numberBooks > 0) { //make sure that there are more than one book to be printed
        cout << "Here is a list of books" << endl; //Insert top
        for (int i = 0; i < numberBooks; i++) { 
            cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl; //output each book on each line
        }
    } else { //if there are no books stored, output error.
        cout << "No books are stored" << endl;
    }
}

/*
* Algorithm: take the given input, make sure books are stored in the arrays passed to the function, and if there are, search for and output the books from the author given
* Input parameters: a string containing book names, a string containing authors, an in for the number of books stored, and a string containing the author's name to search for
* Output (prints to screen): the books written by the author given including a special message if there are none by the author, or an error stating that there are no books stored
* Returns: nothing
*/
void printBooksByAuthor(Book books[], int number, string name)  { 
    string outputStorage[number]; //storage array for strings to be output at the end
    int numberStored = 0; //variable to store the number books in
    if (number > 0) { //make sure there are books stored in the given array
        for (int i = 0; i < number; i++) {
            if (name == books[i].getAuthor()) { //check if the current book being checked matches the author passed to the function
                outputStorage[numberStored] = books[i].getTitle(); //if it is, save it to the output
                numberStored++; //add one to the number of books stored
            }
        }
        if (numberStored == 0) { 
            cout << "There are no books by " << name << endl;//if there are no books matching the given author output message
        } else {
            cout << "Here is a list of books by " << name << endl; //output list header
            for (int i = 0; i < numberStored; i++) {
                cout << outputStorage[i] << endl; //output the list of books that match the author
            }
        }
    } else {
        cout << "No books are stored" << endl; //error message if needed
    }
}


//Menu from Moodle
void printMenu(){
    cout << "======Main Menu=====" << endl;
    cout << "1. Read books" << endl;
    cout << "2. Print all books" << endl;
    cout << "3. Print books by author" << endl;
    cout << "4. Quit" << endl;
}

 //main to run menu and all other functions
int main() {
    Book books[50];
    bool restart = true;
    int storedBooks = 0;
    
    while (restart == true) {

        
        int selection = 0;
        printMenu();
        cin >> selection;
        
        if (selection == 1) {
            string fileName;
            cout << "Enter a book file name:" <<endl;
            cin >> fileName;
            int readBooksReturn = readBooks(fileName, books, storedBooks, 50);
            if (readBooksReturn == -2) {
                cout << "Database is already full. No books were added." << endl;
            } else if (readBooksReturn == -1) {
                cout << "No books saved to the database." << endl;
            } else  if (readBooksReturn == 50) {
                cout << "Database is full. Some books may have not been added." << endl;  
                storedBooks = readBooksReturn;
            }else {
                cout << "Total books in the database: " << readBooksReturn << endl;
                storedBooks = readBooksReturn;
            }
        }else if (selection == 2) {
            printAllBooks(books, storedBooks);
        }else if (selection == 3) {
            string searchName;
            cout << "Enter name of author:" << endl;
            cin.ignore();
            getline(cin, searchName);
            printBooksByAuthor(books, storedBooks, searchName);
        }else if (selection == 4) {
            cout << "Good bye!" << endl;
            restart = false;
        } else { 
            cout << "Invalid input." <<endl;
        }
    }
    
}