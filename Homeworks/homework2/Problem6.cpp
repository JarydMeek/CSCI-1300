// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 2 - Problem #6

#include <iostream>
#include <math.h>
using namespace std;

//Problem
void sphereSurfaceArea (double radius) {
    //declare variables
   double surfaceArea;
    
    //calculate surface area
    surfaceArea = 4* M_PI * pow(radius, 2);
    
    //output answer
    cout << "surface area: " << surfaceArea;
}

//Function to call sphereVolume as a test
int main(){
 sphereSurfaceArea(5);
}