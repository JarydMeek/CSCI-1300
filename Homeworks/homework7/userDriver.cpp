// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 7 - Problem 3

#include <iostream>
#include <string>
#include <fstream>
#include "User.h"
using namespace std;

int main() {
    //Test Case 1
    //Expected Output
    /*  
    getUsername() returned: Person Name
    getNumRatings() returned: 50
    users.getRatingAt(0)  = 3
    users.getRatingAt(10) = 0
    users.getRatingAt(50) = -1
    */
    int testRatings[] = {3,1,4,2,1,3,5,0,3,4,0,4,0,3,4,1,4,5,1,5,0,3,0,4,3,3,0,2,1,0,0,3,2,1,2,1,4,2,2,5,3,2,5,4,2,1,3,1,4,2,2,1,3,3,1};
    User users = User("Person Name", testRatings, 50);
    
    cout << "getUsername() returned: " << users.getUsername() << endl;
    cout << "getNumRatings() returned: " << users.getNumRatings() << endl;
    
    cout << "users.getRatingAt(0)  = " << users.getRatingAt(0) << endl;
    cout << "users.getRatingAt(10) = " << users.getRatingAt(10) << endl;
    cout << "users.getRatingAt(50) = " << users.getRatingAt(50) << endl;
    
    //Test Case 2
    //Expected Output
    /*  
    getUsername() returned: Person Name 2
    getNumRatings() returned: 10
    users2.getRatingAt(0)  = 1
    users2.getRatingAt(5) = 1
    users2.getRatingAt(10) = 0
    */
    int testRatings2[] = {1,2,3,4,5,1,2,3,4,5};
    User users2 = User("Person Name 2", testRatings2, 10);
    
    cout << "getUsername() returned: " << users2.getUsername() << endl;
    cout << "getNumRatings() returned: " << users2.getNumRatings() << endl;
    
    cout << "users2.getRatingAt(0)  = " << users2.getRatingAt(0) << endl;
    cout << "users2.getRatingAt(5) = " << users2.getRatingAt(5) << endl;
    cout << "users2.getRatingAt(10) = " << users2.getRatingAt(10) << endl;
}