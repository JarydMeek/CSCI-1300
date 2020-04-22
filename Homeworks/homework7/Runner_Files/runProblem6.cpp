// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 7 - Problem 6

#include "../User.cpp"
#include "../getCountReadBooks.cpp"

    int main() {
    //creating users and reviews used to test function
    User users[2];
    //Setting username and ratings for User1 
    users[0].setUsername("User1"); 
    users[0].setNumRatings(2); 
    users[0].setRatingAt(0,2); 
    users[0].setRatingAt(1,2);
    //Setting username and ratings for User2 
    users[1].setUsername("User2"); 
    users[1].setNumRatings(4); 
    users[1].setRatingAt(0,4); 
    users[1].setRatingAt(1,4);
    // getCountReadBooks for User2
    
    //Test Case 1
    //Expected Output -
    //2
    cout << getCountReadBooks("User2",users,2,3) << endl;
    
    //Test Case 2
    //Expected Output -
    //-3
    cout << getCountReadBooks("UserNotInDB",users,2,3) << endl;
}