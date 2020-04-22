// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 7 - Problem 4
#include "../User.cpp"
#include "../readRatings.cpp"

//main in order to run test cases.
int main() {
    //Test Case 1
    //Expected Output 
    //10
    
    //4
    //1
    //2
    //0
    //0
    //4
    //3
    //1
    //1
    //1
    
    User users[10] = {};
    int numUsers = 0;
    int maxRows = 10;
    int maxColumns = 50;
    cout << readRatings("ratings.txt", users, numUsers, maxRows, maxColumns) << endl << endl;
    for (int i = 0; i < maxRows; i++) {
        cout << users[i].getRatingAt(i) << endl;
    }
    cout << "-------------------" << endl;//make a spacer
    
    
    //Test Case 2
    //Expected Output 
    //-1
    User users2[10] = {};
    int numUsers2 = 0;
    int maxRows2 = 10;
    int maxColumns2 = 50;
    cout << readRatings("NotARealFile.txt", users2, numUsers2, maxRows2, maxColumns2) << endl;

}