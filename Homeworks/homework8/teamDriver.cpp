// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 8 - Problem 3

#include "Team.cpp"
#include "Player.cpp"

int main() {

    //Test Case 1
    //Expected Output 
    /*
    TeamName1
    O'Flaherty 5.5
    Ioana Fleming 6.1
    Behera 8
    Ku 4.9
    Sankaralingam 1.7
    */
    Team team1("TeamName1");
    cout << team1.getTeamName() << endl;
    team1.readRoster("Test_Files/roster1.txt");
    int num1 = team1.getNumPlayers();
    for (int i = 0; i < num1; i++) {
        cout << team1.getPlayerName(i) << " ";
        cout << team1.getPlayerPoints(i) << endl;
    }
    cout << endl;
    //Test Case 2
    //Expected Output 
    /*
    TeamName2
    Reddy 9.1
    Palavalli 2.8
    Naidu 5.6
    Tetsumichi (Telly) Umada 4.4
    Ladd 8
    */
    Team team2("TeamName2");
    cout << team2.getTeamName() << endl;
    team2.readRoster("Test_Files/roster2.txt");
    int num2 = team2.getNumPlayers();
    for (int i = 0; i < num2; i++) {
        cout << team2.getPlayerName(i) << " ";
        cout << team2.getPlayerPoints(i) << endl;
    }
}