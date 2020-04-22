// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Project 1 - Problem 5

#include <iostream>
#include <string>
using namespace std;

/*
* Algorithm: First verify that the sequence string is not longer than the genome string
                If it is output 0
                If it isn't check the genome for the sequence moving one letter each time
                    Calculate the sim score for each sequence of letters, if it is better than the previous best, save that as the best.
                output the best
* Input parameters: Two strings, one being the genome to search, and one being the sequence we are searching.
* Output (prints to screen): nothing
* Returns: the best sim score found in the genome.
*/
double findBestSimScore(string genome, string sequence) {
    //Variables for storage
    double currentBest = 0; //the current best simscore found
    double newScore = 0; //the current simscore we are comparing to the best
    int differences = 0; // number of differences found between the current part of the genome we are searching and the sequence we are using to search.
    
    if (sequence.length() > genome.length()) { //checks to make sure the genome length is longer than the sequence length.
        return 0; // if it isn't return 0
    } else {
        for (int i = 0; i < genome.length()-sequence.length()+1; i++) { //for loop to pick the starting position in the genome string
            for (int j = 0; j < sequence.length(); j++) { //for loop for comparing the sequence to the genome at the different starting points
                if (genome[i+j] != sequence[j]) { //count the differences in the comparison between genome and sequence
                    differences++; //add one to the total differences for this start point
              }
            }
            newScore = (double) (sequence.length()-differences)/sequence.length(); //calculate then stores the current similarity score
            differences = 0; //resets the difference counter for the next repeat of the loop
            if (newScore > currentBest) { //compares to see if the new sim score calculated is better than the previous ones found.
                currentBest = newScore; //if it is, make it the new best
            }
        }
    }
    return currentBest; //return the best found throughout the strings
}



//main in order to run test cases.
int main() {
    //Test Case 1
    //Expected Result
    //2/3
    cout << findBestSimScore("ATACGC", "CGT") << endl;
    
    //Test Case 2
    //Expected Result
    //1
    cout << findBestSimScore("ATATATAT", "AT") << endl;
    
}