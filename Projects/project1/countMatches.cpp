// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Project 1 - Problem 2

#include <iostream>
#include <string>
using namespace std;

/*
* Algorithm: Determine first if the string entered is empty or not, 
                If empty, output message stating that the string is empty
                If not empty, count the number of letters in the comparison string and assign . 
                    then pick the first 
* Input parameters: String to be broken down by letter (or empty)
* Output (prints to screen): Either an error as the string is empty, or the word split out letter by letter.
* Returns: nothing
*/
int countMatches(string input, string search) {
    //initialize variables
    int output = 0;
    int searchLength = search.length(); //find the length of characters to search
    if (input.length()==0 || searchLength == 0) {//make sure the length is greater than 0
        return -1;// if it isn't output -1
    } else {
        for (int i = 0; i < input.length(); i++) {//if it is, begin a loop that prints each letter for the entirety of the word.
           if (input.substr(i,searchLength) == search) { // compares the string we are seaching vs the string that we were given
               output++; //adds 1 to the output for each occurence
           }
        }
    }
    return output; //return
}


//main in order to run test cases.
int main() {
    //Test Case 1
    //Expected Result
    //1
    cout << countMatches("test", "es") << endl;
    
    //Test Case 2
    //Expected Result
    //2
    cout << countMatches("mississippi", "si");
    
}