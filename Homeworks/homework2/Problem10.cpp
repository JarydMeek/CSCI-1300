// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 2 - Problem #10 
#include <iostream> 
using namespace std; 
//Problem 
double calculateSalary(int rainy,int cold, int sunny) {
    //declare variables 
    int moneyMade; 
    //calculations 
    moneyMade = (5 * rainy + 4 * cold + 8 * sunny)*10; 
    //output answer 
    return moneyMade; } 
    //Function to call sphereVolume as a test 
    int main(){ cout << calculateSalary(5, 8, 19); }