// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 8 - Problem 2

#include "Player.cpp"

int main() {

    //Test Case 1
    //Expected Output 
    /*
    Bartholomew
    6.2
    */
    Player Bartholomew("Bartholomew", 6.2);
    cout << Bartholomew.getName() << endl;
    cout << Bartholomew.getPoints() << endl;

    //Test Case 2
    //Expected Output 
    /*
    Julia
    0
    */
    Player Julia;
    Julia.setName("Julia");
    cout << Julia.getName() << endl;
    cout << Julia.getPoints() << endl;
}