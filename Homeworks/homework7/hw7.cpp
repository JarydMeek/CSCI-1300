// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 7 - Problem 8

#include <iostream>
#include <string>
#include <fstream>
#include "User.h"
#include "Book.h"
using namespace std;

/*
* Algorithm: Takes a string and converts all uppercase letters to lowercase letters
* Input parameters: string
* Output (prints to screen): nothing
* Returns: a string of all lowercase letters
*/
string makeLowercase(string input) {
    for (int i=0; i < input.length(); i++) { //go through the string 1 by one
        if (input[i] >= 'A' && input[i] <= 'Z') //sees if the current letter is capital
		input[i] = ((input[i]) + 32); //if the current letter is capital, replace it with the lowercase letter
    }
    return input; //return the all lowercase string
}


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
* Algorithm: take input file, break it down into lines, and then into strings, then store the first part of the line as the username and the following parts as the ratings
* Input parameters: the string of the file to pull data from, an array of Users, an int for how many users are already stored, and the max rows and columns that the storage array has available
* Output (prints to screen): nothing
* Returns: either a -2 if there is no more space in the array, -1 if the file can't open, or the number of lines added to the array.
*/
int readRatings (string file, User users[], int usersStored, int maxRows, int maxColumns) {
    ifstream importFile; //create the file stream
    importFile.open(file); //open the file passed to the function
    string toSplit = ""; //create temporary storage variable for the line to be split
    string splitRatings[100]; //create array to store the data after it has been split
    int currentLine = usersStored; //create a variable that tracks the number of lines used by the given file
    if (usersStored == maxRows) { //make sure there is room to add any ratings
        importFile.close();
        return -2; //if there isn't return -2
    }else if (importFile.is_open()) { //if there is room, make sure the file opened successfully
        while (getline(importFile, toSplit)) { //gets the current line, then moves to the next one,
            if (toSplit.length() != 0){ //checks to make sure the line contains data
                if (currentLine < maxRows) { //make sure we aren't going to try to overfill the array we were given
                    int splitted = split(toSplit, ',' , splitRatings, maxRows); //split the line into ints stored as strings
                    users[currentLine].setUsername(splitRatings[0]); //save the first part of the line (the user) as the username
                    for (int i = 1; i < splitted; i++) {
                        users[currentLine].setRatingAt(i-1, (stoi(splitRatings[i]))); //store each string containing an int as a rating.
                    }
                    currentLine++; //count the line that was just completed
                } else {
                    importFile.close();
                    return currentLine; //if array gets filled up output the number of rows filled.
                }
            }
        }
            importFile.close(); //actually close the stream because I'm a good person
            return currentLine; //return the line the function got to.
        
    } else {
        importFile.close();
        return-1; //return -1 if file couldn't be opened
    }
}

/*
* Algorithm: Takes a given username and title, finds that users score for the given title in the array of users and books.
* Input parameters: username to find rating from, title to find rating of, the array of users to search, the array of books to search, the number of users given, the number of books given
* Output (prints to screen): nothing
* Returns: a -3 if either the user or the book couldn't be found, otherwise the rating the user gave the book
*/
int getRating (string username, string title, User users[], Book books[], int numUsers, int numBooks) {
    string lowercaseUsername = makeLowercase(username); //make username lowercase
    string lowercaseBookTitle = makeLowercase(title); //make book title lowercase
    
    int bookIndex = -1; //track the position of the book in the array
    int userIndex = -1; //track the position of the user in the array
    
    //First, find the index of the book that matches the entered book
    for (int i = 0; i < numBooks; i++) {
        if (lowercaseBookTitle == makeLowercase(books[i].getTitle())) //if the book title matches any titles stored, save the postition of that book (compares the lowercase version of both title given and title stored)
        bookIndex = i;
    }
    
    //Then find the index of the user that matches the entered username
    for (int i = 0; i < numUsers; i++) {
        if (lowercaseUsername == makeLowercase(users[i].getUsername())) //if the username matches any users stored, save the postition of that user (compares the lowercase version of both given username and stored username)
        userIndex = i;
    }
    
    //then find the Rating the given user gave the given book or -3 if book or title couldn't be found
    if (userIndex == -1 || bookIndex == -1) { //if either the title or user were unable to be found
        return -3;
    } else { //otherwise, the title and book were able to be found and the rating should be found
        return users[userIndex].getRatingAt(bookIndex); //find the user's rating with the given positions
    }
}
/*
* Algorithm: Counts the number of reviews a user given to the function has
* Input parameters: string username, array of users, number of users stored, and number of books stored.
* Output (prints to screen): nothing
* Returns: -3 if the user doesn't exist or the number of books stored is 0 (or less), otherwise the number of books reviewed by the user given
*/
int getCountReadBooks (string username, User users[], int numUsers, int numBooks) {
    int userIndex = -1;
    int numberBooksReviewed = 0;
    //First find the index of the user that matches the entered username
    for (int i = 0; i < numUsers; i++) {
        if (makeLowercase(username) == makeLowercase(users[i].getUsername())) //if the username matches any users stored, save the postition of that user (compares the lowercase version of both given username and stored username)
        userIndex = i;
    }
    
    for (int i = 0; i < numBooks; i++) { 
        if (users[userIndex].getRatingAt(i) > 0) //check the stored reviews for the user and track anytime there is a review that is greater than 0 (AKA actually been reviewed)
        numberBooksReviewed++;
    }
    
    //then find the Rating the given user gave the given book or -3 if book or title couldn't be found
    if (userIndex == -1 || numBooks <1) { //if either the title or user were unable to be found
        return -3;
    } else { //otherwise, the title and book were able to be found and the rating should be found
        return numberBooksReviewed;//find the user's rating with the given positions
    }
}
/*
* Algorithm: finds the average rating of all the stored ratings for a book
* Input parameters: Array of users, array of books, number of users in the array, number of books in the array, book title to find average for
* Output (prints to screen): nothing
* Returns: -3 if the user doesn't exist or the number of users stored is 0, if nobody has reviewed the book returns 0, otherwise return the average value
*/
double calcAverageRating (User users[], Book books[], int numUsers, int numBooks, string bookTitle) {
    //storage variables
    int bookIndex = -1; //starts at -1 so if it reaches the end of the function and still is -1, we know there were no user matches
    int totalScore = 0;
    int numberPeopleReviewed = 0;
    
    //First, find the index of the book that matches the entered book
    for (int i = 0; i < numBooks; i++) {
        if (makeLowercase(bookTitle) == makeLowercase(books[i].getTitle())) //if the book title matches any titles stored, save the postition of that book (compares the lowercase version of both title given and title stored)
        bookIndex = i;
    }
    
    //then count the number of users who have read the book and add the total score
    for (int i = 0; i < numUsers; i++) {
        if (users[i].getRatingAt(bookIndex) > 0) { //checks that the book was actually reviewed by the user, if it is, add 1 to the total number of users who have reviewed the book
            numberPeopleReviewed++;
        } 
       totalScore = totalScore + users[i].getRatingAt(bookIndex); // calculates the total score
    }
    
    if (bookIndex == -1 || numUsers == 0) { //if the book can't be found or there are no users stored, return -3
        return -3;
    } else if (numberPeopleReviewed == 0) { // if nobody has reviewed the book, return 0
        return 0;
    } else {
        return ((double) totalScore/numberPeopleReviewed); //otherwise return the average score
    }
}




//Menu from Moodle
void printMenu(){
    cout << "======Main Menu=====" << endl;
    cout << "1. Read books" << endl;
    cout << "2. Read ratings" << endl;
    cout << "3. Get rating" << endl;
    cout << "4. Find number of books user rated" << endl;
    cout << "5. Get average rating" << endl;
    cout << "6. Quit" << endl;
}

//Main Function
int main() {
    Book books[50]; //array of books
    User users[100]; // array of users
    bool restart = true; //track whether to show the menu again
    int numBooksStored = 0; //track the array position of the number of books stored (starts from 0)
    int numberBooksStored = 0; //track the number of books stored in common speak (starts from 1)
    int usersStored = 0; //tracks the number of users stored
    string username; //saves the entered username
    string title; //saves the entered title
    string fileName; //saves the entered file
    
    
    while (restart == true) {//checks whether to show the menu again
        fileName = ""; //clears saved filename
        title = ""; //clears saved title
        username = ""; //clears saved username
        
        int selection = 0; //initializes the selection variable
        printMenu(); //show the menu given on moodle
        cin >> selection; // save the given input to the selection variable
  
        if (selection == 1) { //if 1 is selected
        
            cout << "Enter a book file name:" << endl; //ask for file name
            cin >> fileName; //save file name
            int lastOutputBooks = 0; //temporary storage variable
            lastOutputBooks = readBooks(fileName, books, numBooksStored, 50); //run readBooks and save returned value to temporary storage variable
            if (lastOutputBooks > 0) { // store the number of books saved
                numBooksStored = lastOutputBooks;
            }
            if ( lastOutputBooks == -1) { //file couldn't be opened
                cout << "No books saved to the database." << endl;
            } else if ( lastOutputBooks == -2) { // database already full
                cout << "Database is already full. No books were added." << endl;
            } else if ( lastOutputBooks >= 49 || usersStored >= 49) { //if the database is full after reading
                cout << "Database is full. Some books may have not been added." << endl;
                numBooksStored = 50; //set the database to full
            } else {
                cout << "Total books in the database: " << lastOutputBooks << endl; //otherwise give number of books stored
            }
            

        } else if (selection == 2) { //2 is selected
            cout << "Enter a user file name:" << endl; //ask for file name
            cin >> fileName; //save file name
            int lastOutput = 0; //temporary storage variable
            lastOutput = readRatings(fileName, users, usersStored, 100, 100); //run readRatings and save returned value to temporary storage variable
            if (lastOutput > 0) { // store the number of users saved
                usersStored = lastOutput;
            }
            if ( lastOutput == -1) {//file couldn't be opened
                cout << "No users saved to the database." << endl;
            } else if ( lastOutput == -2) {// database already full
                cout << "Database is already full. No users were added." << endl;
            } else if ( lastOutput >= 99 || usersStored >= 99) {//if the database is full after reading
                cout << "Database is full. Some users may have not been added." << endl;
                usersStored = 100;//set the database to full
            } else {
                cout << "Total users in the database: " << lastOutput << endl; //otherwise give number of users stored
            }
            
            
        }else if (selection == 3) {//3 is selected
            cout << "Enter a user name: " << endl; //ask for user name
            cin >> username; //save username
            cout << "Enter a book title: " << endl; //ask for book title
            cin.ignore();
            getline(cin, title); //save book title
            int rating = getRating(username, title, users, books, usersStored, numBooksStored); //run getRating and save to storage variable
            if (rating == 0) {
                cout << username << " has not rated " << title << endl; //if the rating is 0, the user has not rated the title
            } else if (rating == -3) {
                cout << username << " or " << title << " does not exist." << endl; //if the rating is -3, the title or username could not be found in the array
            } else {
                cout << username <<  " rated " << title << " with " << rating << endl; //otherwise, give the rating
            }
            
        }else if (selection == 4) { //4 is selected
            cout << "Enter a user name: " << endl; //ask for user name
            cin >> username; //save username
            int readBookCount = getCountReadBooks(username, users, usersStored, numBooksStored); //run getCountReadBooks and save to storage variable
            if (readBookCount == 0) { //if user hasn't rated any books
                cout << username << " has not rated any books." << endl;
            } else if (readBookCount == -3) { //if the user couldn't be found
                cout << username << " does not exist." << endl;
            } else { //otherwise, output the number of books read.
                cout << username <<  " rated " << readBookCount << " books." << endl;
            }
            
        }else if (selection == 5) {
            cout << "Enter a book title: " << endl; //ask for book title
            cin.ignore();
            getline(cin, title); //save title
            double averageRating = calcAverageRating(users,books, usersStored, numBooksStored, title); //run calcAverageRating and save to double
            if (averageRating == -3) { //title can't be found in the array
                cout << title << " does not exist." << endl;
            } else { //otherwise output average rating
                cout << "The average rating for " << title << " is " << averageRating << endl;
            }
        }else if (selection == 6) { //6 is selected
            cout << "Good bye!" << endl;
            restart = false;//don't show menu again
        } else { 
            cout << "Invalid input." <<endl; //user entered something wrong. this user is a dummy.
        }
    }
    
}