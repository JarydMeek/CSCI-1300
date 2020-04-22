// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 2 - Problem #7

#include <iostream>
#include <math.h>
using namespace std;

//Problem
void convertSeconds(int seconds) {
    //declare variables
   int hours;
   int mins;
    
    //calculations
    hours = seconds/3600;
    seconds = seconds - hours*3600;
    mins = seconds/60;
    seconds = seconds - mins*60;
    
    
    //output answer
    cout << hours << " hour(s) " << mins << " minute(s) "<< seconds << " second(s) ";
}

//Function to call sphereVolume as a test
int main(){
 convertSeconds(3671);
}