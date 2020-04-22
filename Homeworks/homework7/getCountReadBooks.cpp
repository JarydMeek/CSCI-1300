// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 7 - Problem 6

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

//main is in runProblem6.cpp