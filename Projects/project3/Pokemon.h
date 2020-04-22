#include <iostream>

using namespace std;

#ifndef POKEMON_H
#define POKEMON_H


class Pokemon 
{ 
    private:
    string name;
    int hp;
    int attack;
    int defense;
    int speed;
    int max;
    string type1;
    string type2;
    bool state;
    int level;
    int maxHealth;
    int locationX;
    int locationY;
    
    public:
     int numberTimesFleed;
     Pokemon(); // Default constructor
     Pokemon(string, int, int, int, int, int, string, string); // Parameterized constructor
     void setName(string);
     void setHP(int);
     void setAttack(int);
     void setDefense(int);
     void setSpeed(int);
     void setMax(int);
     void setType1(string);
     void setType2(string);
     void setState(bool);
     void setLocation(int, int);
     void setLocationX(int);
     void setLocationY(int);
     string getName();
     int getHP();
     int getMaxHealth();
     int getAttack();
     int getDefense();
     int getSpeed();
     int getMax();
     string getType1();
     string getType2();
     bool getState();
     int getLocationX();
     int getLocationY();
     void levelUp();
     void resetHealth();


}; 

#endif 