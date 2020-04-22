// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Practicum 2 - Problem 1

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void printIneligiblePlayers ( string names[], double ages[], int size) {
    for (int i = 0; i < size; i++) {
        if (ages[i] < 4 || ages[i] > 6) {
            cout << names[i] << " " << ages[i] << endl;
        }
    }
}
//main in order to run test cases.
int main() {

}