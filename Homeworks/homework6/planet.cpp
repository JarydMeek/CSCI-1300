#include "planet.h"
#include <math.h>
using namespace std;
Planet::Planet() {
    planetRadius = 0;
    planetName = "";
}
Planet::Planet(string name, double radius) {
    planetName = name;
    planetRadius = radius;
}
string Planet::getName() {
    return planetName;
}
void Planet::setName(string inputName) {
    planetName = inputName;
}
double Planet::getRadius() {
    return planetRadius;
}
void Planet::setRadius(double inputRadius) {
    planetRadius = inputRadius;
}
double Planet::getVolume() {
    return (4*M_PI*pow(planetRadius,3))/3;
}