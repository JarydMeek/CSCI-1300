// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 2 - Problem #9

#include <iostream>
#include <math.h>
using namespace std;

//Problem
double carnot(int tCold,int tHot) {
    //declare variables
    double carnotEfficiency;
    double cold = tCold;
    double hot = tHot;
    
    //calculations
    carnotEfficiency = 1 - (cold / hot);
    
    //output answer
    return carnotEfficiency;
}

//Function to call sphereVolume as a test
int main(){
 cout << carnot(160,1100);
}