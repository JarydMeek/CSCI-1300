#include "Pokemon.h"
#include "math.h"
using namespace std;
    // Default constructor
    /*
    * Algorithm: Initializes the Pokemon Class including making sure all values are cleared.
    * Input parameters: none
    * Output (prints to screen): nothing
    * Returns: none
    */
     Pokemon::Pokemon() {
         name = "0";
         hp = 0;
         attack = 0;
         defense = 0;
         speed = 0;
         max = 0;
         type1 = "";
         type2 = "";
         state = false;
     }

    // Parameterized constructor
    /*
    * Algorithm: Initializes the Pokemon Class including all values for the pokemon.
    * Input parameters: none
    * Output (prints to screen): nothing
    * Returns: none
    */
     Pokemon::Pokemon(string newName, int newHP, int newAttack, int newDefense, int newSpeed, int newMax, string newType1, string newType2) {
         name = newName;
         hp = newHP;
         maxHealth = newHP;
         attack = newAttack;
         defense = newDefense;
         speed = newSpeed;
         max = newMax;
         type1 = newType1;
         type2 = newType2;
         state = false;
     }
    //setter for Name
     void Pokemon::setName(string newName) {
         name = newName;
     }
     //setter for HP
     void Pokemon::setHP(int newHP) {
         if (newHP < 0) {
             newHP = 0;
             state = true;
         }
         hp = newHP;
     }
     //setter for Attack
     void Pokemon::setAttack(int newAttack) {
         attack = newAttack;
     }
     //setter for Defense
     void Pokemon::setDefense(int newDefense) {
         defense = newDefense;
     }
     //setter for Speed
     void Pokemon::setSpeed(int newSpeed) {
         speed = newSpeed;
     }
     //setter for Max
     void Pokemon::setMax(int newMax) {
         max = newMax;
     }
     //setter for Type1
     void Pokemon::setType1(string newType1) {
         type1 = newType1;
     }
     //setter for Type2
    void Pokemon::setType2(string newType2) {
         type2 = newType2;
     }
     //setter for State (Fainted or not)
     void Pokemon::setState(bool newState) {
         state = newState;
     }
    //setter for Location
     void Pokemon::setLocation(int newY, int newX) {
         locationX = newX;
         locationY = newY;
     }
     //setter for Location X
     void Pokemon::setLocationX(int newX) {
         locationX = newX;
     }
     //setter for Location Y
     void Pokemon::setLocationY(int newY) {
         locationY = newY;
     }

     //getter for Name
     string Pokemon::getName() {
         return name;
     }
     //getter for HP
     int Pokemon::getHP() {
         return hp;
     }
     //getter for MaxHP
     int Pokemon::getMaxHealth() {
         return maxHealth;
     }
     //getter for Attack
     int Pokemon::getAttack() {
         return attack;
     }
     //getter for Defense
     int Pokemon::getDefense() {
         return defense;
     }
     //getter for Speed
     int Pokemon::getSpeed() {
         return speed;
     }
     //getter for Max
     int Pokemon::getMax() {
         return max;
     }
     //getter for Type1
     string Pokemon::getType1() {
         return type1;
     }
     //getter for Type2
    string Pokemon::getType2() {
         return type2;
     }
     //getter for State
     bool Pokemon::getState() {
         return state;
     }
     //getter for Location X
     int Pokemon::getLocationX() {
         return locationX;
     }
     //getter for Location Y
     int Pokemon::getLocationY() {
         return locationY;
     }

    /*
    * Algorithm: Levels up the pokemon
    * Input parameters: none
    * Output (prints to screen): nothing
    * Returns: none
    */
     void Pokemon::levelUp() {
         level++;
         int newAttack = ceil(attack*1.02);
         int newDefense = ceil(defense*1.02);
         hp = ceil(hp*1.02);
         maxHealth = ceil(hp*1.02);
         speed = ceil(speed*1.02);
         if (newAttack <= max) {
             attack = newAttack;
         }
        if (newDefense <= max) {
             defense = newDefense;
         }
     }
     //Sets the pokemon's health to full (for use at pokemon centers)
     void Pokemon::resetHealth() {
         hp = maxHealth;
     }
     