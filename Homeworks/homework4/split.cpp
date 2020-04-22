// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 4 - Problem 6

#include <iostream>
#include <iomanip>

using namespace std;

/*
* Algorithm: Takes a string and delimiter, and breaks the string into parts on the delimiter, storing the parts in the given array, checks to make sure the parts will fit in the array,
             doesn't count the part if the delimiter is repeated the string, or if the delimiter is at the beginning or end of the string.
* Input parameters: string, character that is the delimiter, an array to store the split parts in, and the size of the given storage array.
* Output (prints to screen): nothing
* Returns: either a -1 if the number of split parts is greater than the size, a zero if the given string is empty, and the number of split parts if neither of the previous are true.
*/
int split(string split, char delimiter, string words[], int size) {
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

//main in order to run test cases.
int main() {
    //Test Case 1
    //Expected Result
    //2
    //test
    //test2
    string words[6];
    cout << split("test/test2/", '/', words, 6) << endl;
    for (int i = 0; i < 6; i++) {
        cout << words[i] << endl;
    }
    
    //Test Case 1
    //Expected Result
    //9
    //the
    //quick
    //brown
    //fox
    //jumps
    //over
    //the
    //lazy
    //dog
    string words2[10];
    cout << split("the quick brown fox jumps over the lazy dog", ' ', words2, 10) << endl;
    for (int i = 0; i < 6; i++) {
        cout << words2[i] << endl;
    }
    
    //Test Case 3
    //Expected Result
    //0
    string words3[6];
    cout << split("", '/', words3, 6) << endl;
    for (int i = 0; i < 6; i++) {
        cout << words3[i] << endl;
    }
}