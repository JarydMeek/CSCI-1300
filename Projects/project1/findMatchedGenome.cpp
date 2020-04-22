// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Project 1 - Problem 6

#include <iostream>
#include <string>
using namespace std;

/* Algorithm: First verify that the sequence string is not longer than the genome string
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

/*
* Algorithm: First, verify none of the strings are empty, if they are return given error
             Then, make sure that the three genomes input are the same length, if they aren't return an error
             then find the best sim Score in each of the genomes, using the function above (also from problem 5)
             Compare the best sim score from each genome to find the best overall score, and output response stating which is the best.
* Input parameters: 3 strings of genomes, and 1 string of a sequence to search
* Output (prints to screen): if any of the strings passed to the function are empty, it will output an error
                            if the three genome strings passed are different lengths, it will output an error
                            otherwise, it will output which genome is the best match
* Returns: no return
*/

void findMatchedGenome (string genome1, string genome2, string genome3, string sequence) {
    if (genome1.length() == 0 || genome2.length() == 0 || genome3.length() == 0 || sequence.length() == 0) {
        cout << "Genomes or sequence is empty." << endl;
    } else if (genome1.length() != genome2.length() && genome2.length() != genome3.length()) {
        cout << "Lengths of genomes are different." << endl;
    } else {
        //Find the sim score of Genome 1
        double genome1Score = findBestSimScore(genome1, sequence);
        double genome2Score = findBestSimScore(genome2, sequence);
        double genome3Score = findBestSimScore(genome3, sequence);
        
        if (genome1Score >= genome2Score && genome1Score >= genome3Score) {
            cout << "Genome 1 is the best match." << endl;
        }
        if (genome2Score >= genome1Score && genome2Score >= genome3Score) {
            cout << "Genome 2 is the best match." << endl;
        }
        if (genome3Score >= genome1Score && genome3Score >= genome2Score) {
            cout << "Genome 3 is the best match." << endl;
        }
    }
}


//main in order to run test cases.
int main() {
    //Test Case 1
    //Expected Result
    //Genome 1 is the best match.
    findMatchedGenome("AT", "GC", "AG", "AT");
    
    //Test Case 1
    //Expected Result
    //Genome 1 is the best match.
    findMatchedGenome("AT", "GCCGA", "AGTCCTATGC", "AT");
    //Lengths of genomes are different
}