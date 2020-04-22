#include <iostream>

using namespace std;

#ifndef BOOK_H
#define BOOK_H


class Book 
{ 
    private:
    string title;
    string author;

    public:
     Book(); // Default constructor
     Book(string, string); // Parameterized constructor
     string getTitle();
     void setTitle(string);
     string getAuthor();
     void setAuthor(string);
}; 

#endif 