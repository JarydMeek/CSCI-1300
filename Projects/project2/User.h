#include <iostream>

using namespace std;

#ifndef USER_H
#define USER_H


class User 
{ 
    private:
    string username;
    int ratings[50];
    int numRatings;
    int size;
    
    public:
     User(); // Default constructor
     User(string, int[], int); // Parameterized constructor
     string getUsername();
     void setUsername(string);
     int getRatingAt(int);
     bool setRatingAt(int, int);
     int getNumRatings();
     void setNumRatings(int);
     int getSize();
}; 

#endif 