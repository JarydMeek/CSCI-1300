// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Practicum 2 - Problem 1

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string removeCapitals(string input) {
    for (int i=0; i < input.length(); i++) { //go through the string 1 by one
        if (input[i] >= 'A' && input[i] <= 'Z') //sees if the current letter is capital
		input[i] = ('0'); //if the current letter is capital, replace it with the lowercase letter
    }
    string output = "";
     for (int i=0; i < input.length(); i++) {
    if (input[i] != '0') {
        
        output = output + input[i];
    }
    }
    
    return output; //return the all lowercase string
}

//main in order to run test cases.
int main() {
    cout << removeCapitals("TeST");
}