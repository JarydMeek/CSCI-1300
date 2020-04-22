// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 7 - Problem 7

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


//main is in runProblem7.cpp