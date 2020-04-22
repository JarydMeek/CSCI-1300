// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 8 - Problem 1

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

/*
* Algorithm: Takes two vectors of ints, and combines them by alternating from each string.
* Input parameters: vector of ints, vector of ints,
* Output (prints to screen): nothing
* Returns: a vector of the two input strings "shuffled" togther.
*/
vector<int> shuffle(vector<int> input1, vector<int> input2) {
    int sizeVector1 = input1.size(); //variable to store the size of the first vector input.
    int sizeVector2 = input2.size(); //variable to store the size of the second vector input.
    int outputSize = 0; //tracks how many times the vectors need to be shuffled
    bool output2 = false; //tracks if output 2 is the larger vector. 
    vector<int> output; //output vector

    if (sizeVector1 >= sizeVector2) {//if the first vector is longer than the second one
         outputSize = sizeVector1; //go to the size of the first vector
    } else {
        outputSize = sizeVector2; //if the second vector is longer, go to the size of the second vector
        output2 =true; //stores that 2 is longer
    }

    for (int i = 0; i < (outputSize); i++) { //go through the number of the ints stored in the longer vector
        if (output2 == true) { //if 2 is the longer vector
            if (i < sizeVector2) { //if we haven't already added all the vectors of vector 2
                output.push_back(input2.at(i)); //add the int to the output variable
            }
            if (i < sizeVector1) { //if we haven't already added all the vectors of vector 1
                output.push_back(input1.at(i));//add the int to the output variable
            } 
        } else {
            if (i < sizeVector1) { //if we haven't already added all the vectors of vector 1
                output.push_back(input1.at(i));//add the int to the output variable
            }
            if (i < sizeVector2) { //if we haven't already added all the vectors of vector 2
                output.push_back(input2.at(i));//add the int to the output variable
            }
        }
    }

    return output; //return the output vector
}

int main() {
    
    //Test Case 1
    //Expected Output
    /*
    0
    10
    1
    11
    2
    12
    3
    13
    4
    14
    5
    6
    */
    vector<int> input1;
    vector<int> input2;
    for (int i = 0; i < 7; i++) {
        input1.push_back(i);
    }
    for (int i = 10; i < 15; i++) {
        input2.push_back(i);
    }
    vector<int> output = shuffle(input1, input2);
    for (int i = 0; i < input1.size()+input2.size(); i++) {
        cout << output.at(i) << endl;
    }

    cout << endl;
    //Test Case 2
    //Expected Output
    /*
    200
    100
    201
    101
    202
    102
    203
    204
    */
    vector<int> input3;
    vector<int> input4;
    for (int i = 100; i < 103; i++) {
        input3.push_back(i);
    }
    for (int i = 200; i < 205; i++) {
        input4.push_back(i);
    }
    vector<int> output2 = shuffle(input3, input4);
    for (int i = 0; i < input3.size()+input4.size(); i++) {
        cout << output2.at(i) << endl;
    }
}