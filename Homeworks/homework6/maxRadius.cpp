// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 6 - Problem 2

#include <iostream>
#include <string>
#include <fstream>
#include "planet.h"
using namespace std;

/*
* Algorithm: if the array has stored data, find the highest radius in the array of planets passed to the function and return the index of the planet with the largest radius
* Input parameters: array of planets, and the size of the array
* Output (prints to screen): nothing
* Returns: the index of the planet with the largest radius, or -1 if the array is empty
*/
int maxRadius(Planet planets[], int size) {
    double currentBest = 0; //storage varaible for the current highest radius
    int bestPosition = 0; //storage of wehat position in the array the currentbest is
    if (size == 0) { //make sure the array isn't empty
        return -1;
    } else { 
        for (int i = 0; i < size; i++ ) {
            if (currentBest < planets[i].getRadius()) { //see if the radius at the current position is greater than the current highest
            currentBest = planets[i].getRadius(); //if it is, make that the current highest radius
            bestPosition = i; //update the stored position of the current best
            }
        }
    }
    return bestPosition; //return the position of the highest radius
}


int main() {
    //Test Case 1
    //Expected Output 
    //PlanetName
    //7809
    //1.99469e+12
    Planet planets[5];
    planets[0] = Planet("On A Cob Planet",6908);
    planets[1] = Planet("Bird World",4592);
    planets[2] = Planet("Earth",6400);
    planets[3] = Planet("PlanetName",7809);
    int idx = maxRadius(planets, 4);
    cout << planets[idx].getName() << endl;
    cout << planets[idx].getRadius() << endl;
    cout << planets[idx].getVolume() << endl;
    
    //Test Case 2
    //Expected Output 
    //Bird World
    //4321
    //3.37941e+11
    Planet planets2[5];
    planets2[0] = Planet("On A Cob Planet",1234);
    planets2[1] = Planet("Bird World",4321);
    planets2[2] = Planet("TestPlanet3",2812);
    int idx2 = maxRadius(planets2, 3);
    cout << planets2[idx2].getName() << endl;
    cout << planets2[idx2].getRadius() << endl;
    cout << planets2[idx2].getVolume() << endl;
}