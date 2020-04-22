// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 6 - Problem 1

#include <iostream>
#include <string>
#include <fstream>
#include "planet.h"
using namespace std;

int main() {
    //Test Case 1
    //Checks setRadius and getRadius
    //Expected Output 
    //Planet Radius: 300
    Planet planet1 = Planet();
    double radius = 300;
    planet1.setRadius(radius);
    cout << "Planet Radius: " << planet1.getRadius() << endl;
    
    //Test Case 2
    //Checks setRadius and getVolume
    //Expected Output 
    //Planet Volume: 1.13097e+08
    Planet planet2 = Planet();
    double radius2 = 300;
    planet2.setRadius(radius2);
    cout <<"Planet Volume: " << planet2.getVolume() << endl;
}