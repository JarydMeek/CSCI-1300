#include <iostream>

using namespace std;

#ifndef PLAYER_H
#define PLAYER_H


class Player 
{ 
    private:
    string name;
    double points;
    
    public:
     Player(); // Default constructor
     Player(string, double); // Parameterized constructor
     string getName();
     double getPoints();
     void setName(string);
     void setPoints(double);
}; 

#endif 