// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Project 1 - Problem 7

#include <iostream>
#include <string>
using namespace std;


// Show menu function (GIVEN ON MOODLE)
void showMenu(){
    cout << "Select a numerical option:" << endl;
    cout << "=== menu ===" << endl;
    cout << "1. Find similarity score" << endl;
    cout << "2. Find the best similarity score" << endl;
    cout << "3. Analyze the genome sequences" << endl;
    cout << "4. Quit" << endl;
}




/*
* Algorithm: First check that the strings are the same length and that they are not 0, if they aren't the same length or one of them is 0, output 0
            Then go letter by letter for the length of the strings comparing the strings to make sure they are the same letter
            if they aren't, add one to a storage variable
            Calculate the simularity score
* Input parameters: Two strings to compare
* Output (prints to screen): nothing
* Returns: similarity score between 0 and 1 in the form of a double
*/

double calcSimScore(string first, string second) {
    int differences = 0; //storage variable for the number of positions that don't match
    
    if (first.length() == second.length() && first.length() != 0) { //make sure the lengths are the same and neither is 0
        for (int i = 0; i < first.length(); i++) { //count from zero to the length of the strings
            if (first[i] != second[i]){ //check that the letters at the current position don't match
                differences++; //if they don't add one to the output
            }
        }
        return (double) (first.length()-differences)/first.length(); //calculate then return the similarity score
    } else {
        return 0; //return zero if the lengths are different or one is zero
    }
}



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





/*
* Algorithm: First displays the menu (using function given on moodle)
            Then stores integer input of selected value,
            If 1 is selected, collects strings and uses the nessesary function to calculate sim score
            If 2 is selected, collects strings and uses the nessesary function to calculate the best sim score
            If 3 is selected, collects strings and uses the nessesary function to math the given sequence to the best genome
            If 4 is selected, don't repeat the loop and output friendly message
            If another integer is input, output error.
* Input parameters: number selecting what the user wants done, then nessesary values to find what the user wants
* Output (prints to screen): the result of either the Sim Score, the Best Sim Score, the Matched Genome, a friendly goodbye message, or an error message
* Returns: nothing
*/
int main() {
    bool restart = true;//boolean to be set to false, to end loop
    
    while (restart == true) { //loops until the variable is set to false, which happens when 4 is selected
        int selection = 0;
        showMenu();
        cin >> selection;
        
        if (selection == 1) { //1 is selected
            //creation of neccesary variables
            string sequence1;
            string sequence2;
            cout << "Enter sequence 1:" << endl;//prompt for the first input of sequence
            cin >> sequence1;//store sequence 1
            cout << "Enter sequence 2:" << endl;//prompt for the second input of sequence
            cin >> sequence2;//store sequence 2
            cout << "Similarity score: " << calcSimScore(sequence1, sequence2) << endl; //calculate using other function (calcSimScore) and output the similarity score
        } else if (selection == 2) { //2 is selected
            //creation of neccesary variables
            string genome;
            string sequence;
            cout << "Enter genome:" << endl;//prompt for input of genome
            cin >> genome;//store genome
            cout << "Enter sequence:" << endl; //prompt for input of sequence
            cin >> sequence; //store sequence
            cout << "Best similarity score: " << findBestSimScore(genome, sequence) << endl;//calculate using other function (findBestSimScore) and output the best similarity score
        } else if (selection == 3) { //3 is selected
            //creation of neccesary variables
            string genome1;
            string genome2;
            string genome3;
            string sequence;
            cout << "Enter genome 1:" << endl;//prompt for input of the first genome
            cin >> genome1;//store first genome
            cout << "Enter genome 2:" << endl;//prompt for input of the second genome
            cin >> genome2;//store second genome
            cout << "Enter genome 3:" << endl;//prompt for input of the third genome
            cin >> genome3;//store third genome
            cout << "Enter sequence:" << endl;//prompt for input of sequence
            cin >> sequence;//store sequence
            findMatchedGenome(genome1, genome2, genome3, sequence); //run the function (findMatchedGenome) with the given inputs. It has its own outputs, so we don't need to cout it
        } else if (selection == 4) { //4 (quit) is selected
            cout << "Good bye!" << endl; //output friendly message
            restart = false; //don't restart the function
        } else { // something other than 1-4 is input
            cout << "Invalid option." << endl; //tell the user they messed up.
        }
    }
}