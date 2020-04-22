// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 2 - Problem #5

#include <iostream>
#include <math.h>
using namespace std;

//Problem
void sphereVolume (double radius) {
    //declare variables
    double volume;
    
    //calculate volume
    volume = (4.0/3.0) * M_PI * pow(radius, 3);
    
    //output answer
    cout << "volume: " << volume;
}

//Function to call sphereVolume as a test
int main(){
 sphereVolume(5);
}