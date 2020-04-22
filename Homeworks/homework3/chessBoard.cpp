// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 3 - Problem #3

#include <iostream>
using namespace std;


/*
Algorithm - Takes input and validates that it is within expected values
            Takes input and determines if the column the piece is in begins with a white square or a black square.
            If the column begins with "a, c, e, g", the first square is black
                if the number is odd, it is a black square
                if the number is even, it is a white square
            otherwise the first square is white
                if the number is odd, it is a white square
                if the number is even, it is a black square
Input - 1 character and 1 integer based on the location we are trying to find the color of
Output - either "white" or "black" based on the location of the piece
Returns - no returns
*/
void chessBoard (char inputChar, int inputInt) {
    if (inputChar >= 'a' && inputChar <= 'h' && inputInt > -1 && inputInt < 9) { //check to make sure input is valid
        if (inputChar == 'a' ||inputChar == 'c' ||inputChar == 'e' ||inputChar == 'g') { // check if the first square in the column is black
            if (inputInt % 2 == 0) { //is the row even?
                cout << "white"; // if even, output white
            } else {
                cout << "black"; //if odd, output black
            }
        } else { //move on to the columns that the first square is white
            if (inputInt % 2 == 1) { //is the row odd?
                cout << "white";//if odd, output white
            }else {
                cout << "black";//if even, output black
            }
        }
    } else {
            cout << "Chessboard squares can only have letters between a-h and numbers between 1-8."; // output if something is outside of expected values
    }
}


//Function to call chessBoard as a test
int main(){
    //Test Case 1
    //Expected Result
    //white
    chessBoard('a', 2);
    
    //Test Case 1
    //Expected Result
    //black
    chessBoard('b', 4);
}