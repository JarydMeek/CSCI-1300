#include "Player.h"
using namespace std;

//default constructo
Player::Player() {
    name = "";
    points = 0;
}
//parameterized constructor
Player::Player(string inputName, double inputPoints) {
    name = inputName;
    points = inputPoints;
}
//getter for name
string Player::getName() {
    return name;
}
//getter for points
double Player::getPoints() {
    return points;
}
//setter for name
void Player::setName(string inputName) {
    name = inputName;
}
//setter for points
void Player::setPoints(double inputPoints) {
    points = inputPoints;
}

