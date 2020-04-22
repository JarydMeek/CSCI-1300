// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 3 - Extra Credit

#include <iostream>
using namespace std;

/*
Algorithm - Have the user pick a story and prompt for the correct entries, then create the story
            loop picking stories till 4 is selected
Input - A number to select the story, then the prompted for values
Output - a prompt for whatever story the reader wants, then the words neccesary for the story, then a goodbye message
Returns - no return
*/
void storyGenerator() {
    //variable to decide to continue or not
    bool restart = true;

    while (restart == true) {//Loop until 4 is selected
        
        //Select a story
        int storyNumber= 0;
        cout << "Which story would you like to play? Enter the number of the story (1, 2, or 3) or type 4 to quit" << endl;
        cin >> storyNumber;
    
        if (storyNumber == 1) {//Story 1
            //Variables
            string noun1;
            //prompt for and store entries
            cout << "Enter a noun:" << endl;
            cin >> noun1;
            //produce story
            cout << "Be careful not to vacuum the " << noun1 << " when you clean under your bed." << endl;
        } else if (storyNumber == 2) {//Story 2
            //Variables
            string name1;
            string occupation1;
            string place1;
            //prompt for and store entries
            cout << "Enter a name:" << endl;
            cin >> name1;
            cout << "Enter an occupation:" << endl;
            cin >> occupation1;
            cout << "Enter a place:" << endl;
            cin >> place1;
            //produce story
            cout << name1 <<" is a " << occupation1 << " who lives in "<< place1 <<"." << endl;
        } else if (storyNumber == 3) {//Story 3
            //Variables
            string noun1;
            string occupation1;
            string animal1;
            string place1;
            //prompt for and store entries
            cout << "Enter a plural noun:" << endl;
            cin >> noun1;
            cout << "Enter an occupation:" << endl;
            cin >> occupation1;
            cout << "Enter an animal:" << endl;
            cin >> animal1;
            cout << "Enter a place:" << endl;
            cin >> place1;
            //produce story
            cout << "In the book War of the " << noun1 << ", the main character is an anonymous " << occupation1 << " who records the arrival of the " << animal1 << "s in " << place1 <<"." << endl;
        } else if (storyNumber == 4) {//Story 4
            cout << "Good bye!" <<endl;
            restart = false; // end the loop
        } else {
         cout << "ERROR" << endl;//entry other than 1-4
        }
        
        cout << "\n"; 
    }
}

int main(){
    
//Actually runs the function
    storyGenerator();
 
}