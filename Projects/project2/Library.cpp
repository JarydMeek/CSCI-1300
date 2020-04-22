#include "Book.h"
#include "User.h"
#include "Library.h"
#include <math.h>
using namespace std;

    /*
    * Algorithm: sets up a new Library with wiped everything (book class and library class)
    * Input parameters: none
    * Output (prints to screen): nothing
    * Returns: nothing
    */
    Library::Library() {
     sizeBook = 50;
     sizeUser = 100;
     Book books[sizeBook];
     User User[sizeUser];
     numBooks = 0;
     numUsers = 0;
    }
    
    
    /*
    * Algorithm: Takes a string and delimiter, and breaks the string into parts on the delimiter, storing the parts in the given array, checks to make sure the parts will fit in the array,
                 doesn't count the part if the delimiter is repeated the string, or if the delimiter is at the beginning or end of the string.
    * Input parameters: string, character that is the delimiter, an array to store the split parts in, and the size of the given storage array.
    * Output (prints to screen): nothing
    * Returns: either a -1 if the number of split parts is greater than the size, a zero if the given string is empty, and the number of split parts if neither of the previous are true.
    */
    int Library::split(string split, char delimiter, string words[], int size) {
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
    * Algorithm: Takes a string and converts all uppercase letters to lowercase letters
    * Input parameters: string
    * Output (prints to screen): nothing
    * Returns: a string of all lowercase letters
    */
    string Library::makeLowercase(string input) {
        for (int i=0; i < input.length(); i++) { //go through the string 1 by one
            if (input[i] >= 'A' && input[i] <= 'Z') //sees if the current letter is capital
    		input[i] = ((input[i]) + 32); //if the current letter is capital, replace it with the lowercase letter
        }
        return input; //return the all lowercase string
    }

    //Getter for the size of the book array
     int Library::getSizeBook(){
        return sizeBook;
     }
     
     //Getter for the size of the user array
     int Library::getSizeUser(){
        return sizeUser;
     }
     
     //Getter for the number of books in the book array
     int Library::getNumBooks(){
        return numBooks;
     }
     
     //Getter for the number of users in the user array
     int Library::getNumUsers(){
        return numUsers;
     }
     
     /*
    * Algorithm: open file given in the parameters into the file stream
                first check to make sure the starting number of books in the array is less than the storage we are given, if it isn't return -2
                if we can store the number of books given, take the given file, split a line into an string, then split the string on the comma which divides the string into author and book title, 
                then store each part of the book information into the array of books.
                finally if we can't open the file, return -1
    * Input parameters: file to open
    * Output (prints to screen): nothing
    * Returns: a -2 if the book number we should start reading from is greater than the storage we have, or a -1 if unable to open the file give, otherwise the number of books stored
    */
     int Library::readBooks(string fileName) {
        //open file
        ifstream importFile; //create the file stream
        importFile.open(fileName); //open the file passed to the function
        
        //process file 
        if (numBooks >= sizeBook) { //checks to make sure that the array isn't already full as given from the problem
            return -2; //if there isn't space, return -2
        } else if (importFile.is_open()){ //check to make sure the file is open
            string toSplit = ""; //storage string to pass to the split() function
            string singleBook[2]; //array to pass to the split() function for storage
            int currentLine = numBooks; //start checking books after the number of books passed to the function
            // read each line from the file 
            while (getline(importFile, toSplit)) { //save each line to the storage variable
                if (currentLine < 50){ // make sure that we still have storage remaining 
                    if (toSplit.length() != 0) { //make sure the line isn't empty
                    split(toSplit, ',', singleBook, 2); //split the line on the comma
                    books[currentLine].setAuthor(singleBook[0]); //store the current author to the correct place in the class
                    books[currentLine].setTitle(singleBook[1]);//store the current book to the correct place in the class
                    currentLine++; //add one to the current line tracker
                    }
                }
            }
            numBooks = currentLine;
            return currentLine; //return the number of lines
        } else {
            return -1;
        }
        importFile.close(); //actually close the stream because I'm a good person
    }
   /*
    * Algorithm: Prints all books stored
    * Output (prints to screen): authors and titles of books stored
    * Returns: nothing
    */
     void Library::printAllBooks(){
        if (numBooks > 0) { //make sure that there are more than one book to be printed
            cout << "Here is a list of books" << endl; //Insert top
            for (int i = 0; i < numBooks; i++) { 
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
     void Library::printBooksByAuthor(string name){
        string outputStorage[numBooks]; //storage array for strings to be output at the end
        int numberStored = 0; //variable to store the number books in
        if (numBooks > 0) { //make sure there are books stored in the given array
            for (int i = 0; i < numBooks; i++) {
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
     /*
    * Algorithm: take input file, break it down into lines, and then into strings, then store the first part of the line as the username and the following parts as the ratings
    * Input parameters: the string of the file to pull data from, an array of Users, an int for how many users are already stored, and the max rows and columns that the storage array has available
    * Output (prints to screen): nothing
    * Returns: either a -2 if there is no more space in the array, -1 if the file can't open, or the number of lines added to the array.
    */
     int Library::readRatings(string file){
        ifstream importFile; //create the file stream
        importFile.open(file); //open the file passed to the function
        string toSplit = ""; //create temporary storage variable for the line to be split
        string splitRatings[100]; //create array to store the data after it has been split
        int currentLine = numUsers; //create a variable that tracks the number of lines used by the given file
        if (numUsers == sizeUser) { //make sure there is room to add any ratings
            importFile.close();
            return -2; //if there isn't return -2
        }else if (importFile.is_open()) { //if there is room, make sure the file opened successfully
            while (getline(importFile, toSplit)) { //gets the current line, then moves to the next one,
                if (toSplit.length() != 0){ //checks to make sure the line contains data
                    if (currentLine < sizeUser) { //make sure we aren't going to try to overfill the array we were given
                        int splitted = split(toSplit, ',' , splitRatings, sizeUser); //split the line into ints stored as strings
                        users[currentLine].setUsername(splitRatings[0]); //save the first part of the line (the user) as the username
                        for (int i = 1; i < splitted; i++) {
                            users[currentLine].setRatingAt(i-1, (stoi(splitRatings[i]))); //store each string containing an int as a rating.
                        }
                        currentLine++; //count the line that was just completed
                    } else {
                        importFile.close();
                        numUsers = currentLine;
                        return currentLine; //if array gets filled up output the number of rows filled.
                    }
                }
            }
                numUsers = currentLine;
                importFile.close(); //actually close the stream because I'm a good person
                return currentLine; //return the line the function got to.
            
        } else {
            importFile.close();
            return-1; //return -1 if file couldn't be opened
        }
     }
     /*
    * Algorithm: Takes a given username and title, finds that users score for the given title in the array of users and books.
    * Input parameters: username to find rating from, title to find rating of
    * Output (prints to screen): nothing
    * Returns: a -3 if either the user or the book couldn't be found, otherwise the rating the user gave the book
    */
     int Library::getRating(string username, string title){
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
    * Input parameters: string username
    * Output (prints to screen): nothing
    * Returns: -3 if the user doesn't exist or the number of books stored is 0 (or less), otherwise the number of books reviewed by the user given
    */
     int Library::getCountReadBooks(string username){
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
    * Algorithm: Prints out all the books the given user has rated, along with the rating
    * Input parameters: string username, int 
    * Output (prints to screen): all the book the user has read and their ratings
    * Returns: nothing
    */
     void Library::viewRatings(string username, int minRating){
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
        
        if (userIndex == -1) {
            cout << username << " does not exist." << endl;//outputs if the user can't be found in storage
        } else if (numberBooksReviewed == 0) {
            cout << username << " has not rated any books yet." << endl; //outputs if the user hasn't read any books
        } else {
            cout << "Here are the books that " << username << " rated" << endl; //outputs the books the user rated that are greater than the rating given
            for (int i = 0; i < numBooks; i++) {
                if (users[userIndex].getRatingAt(i) >= minRating) {
                    cout << "Title : " << books[i].getTitle() << endl;
                    cout << "Rating : " << users[userIndex].getRatingAt(i) << endl;
                    cout << "-----" << endl;
                }
            }
        }
     }         
     /*
    * Algorithm: finds the average rating of all the stored ratings for a book
    * Input parameters: book title to find average for
    * Output (prints to screen): nothing
    * Returns: -3 if the user doesn't exist or the number of users stored is 0, if nobody has reviewed the book returns 0, otherwise return the average value
    */
     double Library::calcAvgRating(string bookTitle){
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
    /*
    * Algorithm: finds the average rating of all books by a specific author
    * Input parameters: string of author name
    * Output (prints to screen): nothing
    * Returns: -3 if the user doesn't exist or the number of users stored is 0, if nobody has reviewed the book returns 0, otherwise return the average value
    */
     double Library::calcAvgRatingByAuthor(string authorName){
         int totalScore = 0;
         int numberPeopleReviewed = 0;
         int authorIndex = -1;
        //First, find the index of the book that matches the entered book
        for (int i = 0; i < numBooks; i++) {
            if (makeLowercase(authorName) == makeLowercase(books[i].getAuthor())){ //if the book title matches any titles stored, save the postition of that book (compares the lowercase version of both title given and title stored)
                authorIndex = i;
                for (int j = 0; j < numUsers; j++) {
                    if (users[j].getRatingAt(authorIndex) > 0) { //checks that the book was actually reviewed by the user, if it is, add 1 to the total number of users who have reviewed the book
                        numberPeopleReviewed++;
                    } 
                    totalScore = totalScore + users[j].getRatingAt(authorIndex); // calculates the total score
                }
            }
        }
        if (authorIndex == -1 || numUsers == 0) { //if the book can't be found or there are no users stored, return -3
            return -3;
        } else if (numberPeopleReviewed == 0) { // if nobody has reviewed the book, return 0
            return 0;
        } else {
            return ((double) totalScore/numberPeopleReviewed); //otherwise return the average score
        }
     }
         /*
    * Algorithm: adds a user to the database
    * Input parameters: string of username
    * Output (prints to screen): nothing
    * Returns: 1 if user was added successfully, -2 if the user database is already full, and 0 if there is already a user with that name
    */
     int Library::addUser(string userName){
         bool repeatUser = false;
         for (int i = 0; i < numUsers; i++) { 
             if (makeLowercase(users[i].getUsername()) == makeLowercase(userName)) { //checks to make sure there isn't already a user in the database with that name.
                 repeatUser = true;
             }
         }
         if (numUsers >= sizeUser) { //if the array is full
             return -2;
         } else if (repeatUser == true) { //repeat user
             return 0;
         } else { //otherwise save the new user
            users[numUsers].setUsername(userName);
            numUsers++;
            return 1;
         }
     }
    /*
    * Algorithm: adds or updates a review by a user of a book
    * Input parameters: string of username, string of title, and int of the new rating
    * Output (prints to screen): nothing
    * Returns: -3 if the user doesn't exist, if the rating is invalid -4, otherwise return 1
    */
     int Library::checkOutBook(string username, string title, int rating){
        string lowercaseUsername = makeLowercase(username); //make username lowercase
        string lowercaseBookTitle = makeLowercase(title); //make book title lowercase
        
        int bookIndex = -1; //track the position of the book in the array
        int userIndex = -1; //track the position of the user in the array
        bool ratingValid = true;
        int numReccomendaions = 0;
        
        //Make sure the rating is valid
        if (rating > 5 || rating < 0) {
            ratingValid = false;
        }
        
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
        if (ratingValid == false) {
            return -4;
        } else if (userIndex == -1 || bookIndex == -1) { //if either the title or user were unable to be found
            return -3;
        } else { //otherwise, the title and book were able to be found and the rating should be found
            users[userIndex].setRatingAt(bookIndex, rating);
            return 1; //find the user's rating with the given positions
        }
     }
    /*
    * Algorithm: reccomends a book a user may like
    * Input parameters: string of uername
    * Output (prints to screen): the reccomendations
    * Returns: nothings
    */
     void Library::getRecommendations(string username){
        string lowercaseUsername = makeLowercase(username); //make username lowercase
        int userIndex = -1;
        int numReccomendaions = 0;
        string toOutput[5]; //storage for output strings
        for (int i = 0; i < numUsers; i++) { 
            if (lowercaseUsername == makeLowercase(users[i].getUsername())) {//if the username matches any users stored, save the postition of that user (compares the lowercase version of both given username and stored username)
                userIndex = i;
            }
        }
        
        //SSD
        int bestUser = -1;
        int currentBestComparison = 1000000; //really big number so that generally any number will be lower than it
        int sumSquaredDifferences = 0; //temporary storage variable
        for (int i = 0; i < numUsers; i++) {
            sumSquaredDifferences = 0; //reset the temp variable to 0
            if (userIndex != i) { //makes sure we aren't checking same user index
                for (int j = 0; j < numBooks; j++) { 
                    sumSquaredDifferences = sumSquaredDifferences + ( pow ((users[userIndex].getRatingAt(j) - users[i].getRatingAt(j)), 2)); //calculate the sum squared difference
                }
                if (sumSquaredDifferences == 0){  //if it is zero do nothing because it is likely the same user
                } else if (currentBestComparison > sumSquaredDifferences) { //see if the current sumsquared difference is closer than the previous one
                currentBestComparison = sumSquaredDifferences; //if it is save the new one
                bestUser = i; //store the index of the best user
                } 
            }
        }
        
        for (int i = 0; i < numBooks; i++){
                if (numReccomendaions < 5) { //only output 5 reccomendations
                    if (users[userIndex].getRatingAt(i) == 0 && users[bestUser].getRatingAt(i) > 2) { //make sure the user hasn't read the book and that the rating is 3,4 or 5
                        toOutput[numReccomendaions] = (books[i].getTitle() + " by " + books[i].getAuthor()); //save the output string to the output array
                        numReccomendaions++;
                    }
                }
            }
        
        if (userIndex == -1) {
            cout << username << " does not exist." << endl; //invalid username
        } else if (bestUser == -1 || numReccomendaions == 0) {
            cout << "There are no recommendations for " << username << " at present." << endl; //no reccomendations
        } else {
            cout << "Here is the list of recommendations" << endl; //output the title and storage array.
            for (int i = 0; i < numReccomendaions; i++) {
                cout << toOutput[i] << endl;
            }
        }
    }