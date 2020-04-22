// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 6 - Problem 3

#include <iostream>
#include <string>
#include <fstream>
#include "Book.h"
using namespace std;

int main() {
    //Test Case 1
    //Checks setTitle and getTitle
    //Expected Output 
    //Book Title: Book Title Test
    Book book1 = Book();
    book1.setTitle("Book Title Test");
    cout << "Book Title: " << book1.getTitle() << endl;
    
    //Test Case 2
    //Checks setAuthor and getAuthor
    //Expected Output 
    //Book Author: Someone Who Wrote A Book At Some Point
    Book book2 = Book();
    book2.setAuthor("Someone Who Wrote A Book At Some Point");
    cout << "Book Author: " << book2.getAuthor() << endl;
}