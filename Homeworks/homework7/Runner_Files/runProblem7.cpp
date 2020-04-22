// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 7 - Problem 7

#include "../User.cpp"
#include "../book.cpp"
#include "../calcAverageRating.cpp"


    int main() {
    //creating users and books used to test function
    Book books[2]; 
    books[0].setTitle("Title1"); 
    books[0].setAuthor("Author1"); 
    books[1].setTitle("Title2"); 
    books[1].setAuthor("Author2");
    //Create list of users 
    User users[3];
    //Setting username and ratings 
    users[0].setUsername("User1"); 
    users[0].setNumRatings(2); 
    users[0].setRatingAt(0,2); 
    users[0].setRatingAt(1,3);
    //Setting username and ratings 
    users[1].setUsername("User2"); 
    users[1].setNumRatings(4); 
    users[1].setRatingAt(0,4); 
    users[1].setRatingAt(1,4);
    //Setting username and ratings 
    users[2].setUsername("User3"); 
    users[2].setNumRatings(4); 
    users[2].setRatingAt(0,4); 
    users[2].setRatingAt(1,4);
    
    //Test Case 1
    //Expected Value - 
    //3.66667
    cout << calcAverageRating(users, books, 3, 2, "title2") << endl;
    //Test Case 2
    //Expected Value - 
    //-3
    cout << calcAverageRating(users, books, 3, 2, "NotATitleInTheArray") << endl;
    

}