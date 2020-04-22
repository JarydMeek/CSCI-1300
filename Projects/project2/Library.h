#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#ifndef LIBRARY_H
#define LIBRARY_H


class Library 
{ 
    private:
    int sizeBook;
    int sizeUser;
    Book books[50];
    User users[100];
    int numBooks;
    int numUsers;
    int split(string, char, string[], int);
    string makeLowercase(string);
    
    public:
     Library(); // Default constructor
     int getSizeBook();
     int getSizeUser();
     int getNumBooks();
     int getNumUsers();
     int readBooks(string);
     void printAllBooks();
     void printBooksByAuthor(string);
     int readRatings(string);
     int getRating(string, string);
     int getCountReadBooks(string);
     void viewRatings(string, int);
     double calcAvgRating(string);
     double calcAvgRatingByAuthor(string);
     int addUser(string);
     int checkOutBook(string, string, int);
     void getRecommendations(string);
}; 

#endif 