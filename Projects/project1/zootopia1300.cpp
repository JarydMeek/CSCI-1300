// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Project 1 - Problem 3

#include <iostream>
#include <string>
using namespace std;

/*
* Algorithm: run printMenu to create menu
            accept input and store it.
                If 1 is selected > prompt for input (and store) agility and strength
                If 2 is selected > prompt for input (and store) agility and speed 
                If 3 is selected > prompt for input (and store) strength and speed
                If 4 is selected > quit function and don't output
            Then calculate and output the hireScore
* Input parameters: a number to select something in the menu
                    then a combination of agility, strength, and speed corresponding to selected animal
* Output (prints to screen): menu, prompts for agility, strength, and speed, then calculated hire score
* Returns: nothing
*/

//given printMenu function. creates menu
void printMenu(){
	cout<<"Select a numerical option:"<<endl;
	cout<<"=== menu ==="<<endl;
	cout<<"1. Fox"<<endl;
	cout<<"2. Bunny"<<endl;
	cout<<"3. Sloth"<<endl;
	cout<<"4. Quit"<<endl;
}

void zootopia1300() {
    //boolean variable creation in order to repeat function
    bool restart = true;
    
    
    while(restart == true) { // if the repeat bool is true, repeat the program
        printMenu(); //print the menu
        int menuSelection = 0; //variable to store the selection in.
        cin >> menuSelection; //store the selection
    
        //Variables for storage of entered characteristics
        double agility = 0;
        double strength = 0;
        double speed = 0;
    
        if (menuSelection == 1) { //if "fox" is selected
            cout << "Enter agility:" << endl; //prompt for input of agility
            cin >> agility; //store entered agility
            cout << "Enter strength:" << endl; //prompt for input of strength
            cin >> strength; //store entered strength
            
        } else if (menuSelection == 2) { //if "bunny" is selected
            cout << "Enter agility:" << endl; //prompt for input of agility
            cin >> agility; //store entered agility
            cout << "Enter speed:" << endl; //prompt for input of speed
            cin >> speed; //store entered speed
            
        } else if (menuSelection == 3) { //if "sloth" is selected
            cout << "Enter strength:" << endl; //prompt for input of strength
            cin >> strength; //store entered strength
            cout << "Enter speed:" << endl; //prompt for input of speed
            cin >> speed; //store entered speed
            
        } else if (menuSelection == 4) { //if "quit" is selected
                restart = false; //do not repeat the function
                break; //quit the function without printing the Hire Score
        } else { //somebody entered something other than 1-4
            cout << "ERROR" << endl; //Print error
            break;
        }
        
                    
        //Calculate and output hireScore
        cout << "Hire Score: " << (1.8*agility)+(2.16*strength)+(3.24*speed) << endl;
    }
}

//main in order to run function.
int main() {
    
    //Run function
    zootopia1300();
    
    //since 0 parameters are passed, and no return statement, only need 1 test case
}