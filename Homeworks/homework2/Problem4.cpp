// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 2 - Problem #4

#include <iostream>
#include <math.h>
using namespace std;

int main(){
    cout << "Enter a radius: " << endl;
    double radius;
    cin >> radius;
    double volume;
    volume = (4.0/3.0) * M_PI * pow(radius, 3);
    cout << "volume: " << volume << endl;
    
    //your code goes here
  
    double surfaceArea;
    surfaceArea = 4* M_PI * pow(radius, 2);
    cout << "surface area: " << surfaceArea;
}