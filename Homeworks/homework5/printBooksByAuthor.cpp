// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 5 - Problem 4

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


/*
* Algorithm: take the given input, make sure books are stored in the arrays passed to the function, and if there are, search for and output the books from the author given
* Input parameters: a string containing book names, a string containing authors, an in for the number of books stored, and a string containing the author's name to search for
* Output (prints to screen): the books written by the author given including a special message if there are none by the author, or an error stating that there are no books stored
* Returns: nothing
*/
void printBooksByAuthor(string titles[], string authors[], int number, string name)  { 
    string outputStorage[number]; //storage array for strings to be output at the end
    int numberStored = 0; //variable to store the number books in
    if (number > 0) { //make sure there are books stored in the given array
        for (int i = 0; i < number; i++) {
            if (name == authors[i]) { //check if the current book being checked matches the author passed to the function
                outputStorage[numberStored] = titles[i]; //if it is, save it to the output
                numberStored++; //add one to the number of books stored
            }
        }
        if (numberStored == 0) { 
            cout << "There are no books by Author A" << endl;//if there are no books matching the given author output message
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

//main in order to run test cases.
int main() {
    //Test Case 1
    //Expected Output 
    //Here is a list of books by Author A
    //Book 1
    //Book 3
    string titles[3] = {"Book 1", "Book 2", "Book 3"}; 
    string authors[3] = {"Author A", "Author B", "Author A" };
    int numBooks = 3;
    string author = "Author A";
    printBooksByAuthor(titles, authors, numBooks, author);
    
    //Test Case 2
    //Expected Output 
    //No books are stored
    string titles2[3] = {"Book 1", "Book 2", "Book 3"}; 
    string authors2[3] = {"Author C", "Author A", "Author B" };
    int numBooks2 = 0;
    string author2 = "Author C";
    printBooksByAuthor(titles2, authors2, numBooks2, author2);

}