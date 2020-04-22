// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 7 - Problem 5

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



//main is in runProblem5.cpp