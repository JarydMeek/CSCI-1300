// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 5 - Problem 3

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//SPLIT FROM HOMEWORK 4
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
            then store each part of the book information into different arrays for title and author.
            finally if we can't open the file, return -1
* Input parameters: file to open, an array to store titles in, an array to store authors in, an int for the number of books we need to store, and an int for the size of the storage that we have been passed
* Output (prints to screen): nothing
* Returns: a -2 if the book number we should start reading from is greater than the storage we have, or a -1 if unable to open the file give, otherwise the number of books stored
*/

int readBooks (string file, string titles[], string authors[], int numBooks, int size) {
    //open file
    ifstream importFile; //create the file stream
    importFile.open(file); //open the file passed to the function
    
    //process file 
    if (numBooks >= size){ //checks to make sure that the array isn't already full as given from the problem
        return -2; //if there isn't space, return -2
    } else if (importFile.is_open()){ //check to make sure the file is open
        string toSplit = ""; //storage string to pass to the split() function
        string singleBook[2]; //array to pass to the split() function for storage
        int currentLine = numBooks; //start checking books after the number of books passed to the function
        // read each line from the file 
        while (getline(importFile, toSplit)) { //save each line to the storage variable
            if (currentLine < size){ // make sure that we still have storage remaining 
                if (toSplit.length() != 0) { //make sure the line isn't empty
                split(toSplit, ',', singleBook, 2); //split the line on the comma
                authors[currentLine] = singleBook[0]; //store the current author to the correct place in the author array
                titles[currentLine] = singleBook[1];//store the current book to the correct place in the book array
                currentLine++;
                }
            }
        }
        return currentLine; //return the number of lines
    } else {
        return -1; //return -1 if file won't open
    }
    importFile.close(); //actually close the stream because I'm a good person
}


/*
* Algorithm: chjeck to make sure that there are books stored, if there are, print the arrays out for 
* Input parameters: titles array, authors array, and number of books to print
* Output (prints to screen): "here is a list of books" then the list of books, or "no books are stored"
* Returns: none
*/
void printAllBooks(string titlesToPrint[], string authorsToPrint[], int numberBooks) {
    if (numberBooks > 0) { //make sure that there are more than one book to be printed
        cout << "Here is a list of books" << endl; //Insert top
        for (int i = 0; i < numberBooks; i++) { 
            cout << titlesToPrint[i] << " by " << authorsToPrint[i] << endl; //output each book on each line
        }
    } else { //if there are no books stored, output error.
        cout << "No books are stored" << endl;
    }
}


//main in order to run test cases.
int main() {
    //Test Case 1
    //Expected Results
    //Here is a list of books
    //The Hitchhiker's Guide To The Galaxy by Douglas Adams
    //Watership Down by Richard Adams
    //The Five People You Meet in Heaven by Mitch Albom
    //Speak by Laurie Halse Anderson
    //I Know Why the Caged Bird Sings by Maya Angelou
    //Thirteen Reasons Why by Jay Asher
    //The Sisterhood of the Travelling Pants by Ann Brashares
    //A Great and Terrible Beauty by Libba Bray
    //The Da Vinci Code by Dan Brown
    string authors[10];
    string titles[10];
    int nb = readBooks("./Input Files/books.txt",titles,authors, 0, 10); 
    printAllBooks(titles, authors, nb);
    
    
    cout << endl;
    //Test Case 2
    //Expected Results
    //No books are stored
    string authors2[10];
    string titles2[10];
    int nb2 = readBooks("./Input Files/books.txt",titles,authors, 10, 0); 
    printAllBooks(titles2, authors2, nb2);
    
}