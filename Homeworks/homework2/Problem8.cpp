// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 2 - Problem #8

#include <iostream>
#include <math.h>
using namespace std;

//Problem
int population(int calculatePopulation) {
    //declare variables
    int births = 8;
    int deaths = 12;
    int immigrants = 27;
    int secondsYear = 31536000;
    
    //calculations
    calculatePopulation = calculatePopulation + secondsYear / births;
    calculatePopulation = calculatePopulation - secondsYear / deaths;
    calculatePopulation = calculatePopulation + secondsYear / immigrants;
    //output answer
    return calculatePopulation;
}

//Function to call sphereVolume as a test
int main(){
 cout << population(1000000);
}