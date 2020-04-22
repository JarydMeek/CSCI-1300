// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Practicum 2 - Problem 1

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int CountUpper (string input) {
    if (input.length() == 0) {
        return -1;
    }
    int output = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] >= (int) 'A' && input[i] <= (int) 'Z') {
            output++;
        }
    }
    if (output > 0) {
    return output;
    } else if (output == 0) {
        return -2;
    }
}


//main in order to run test cases.
int main() {
 cout << CountUpper("Test");
}