#include <iostream>

using namespace std;

#ifndef PLANET_H
#define PLANET_H


class Planet 
{ 

    private:
    string planetName;
    double planetRadius;

    public:
     Planet(); // Default constructor
     Planet(string, double); // Parameterized constructor
     string getName();
     void setName(string);
     double getRadius();
     void setRadius(double);
     double getVolume();
}; 

#endif 