// CS1300 Fall 2019
// Author: Jaryd Meek
// Recitation: 102 – Matthew Luebbers
// Homework 8 - Problem 4

#include "Team.cpp"
#include "Player.cpp"

/*
* Algorithm: takes two teams, and finds which team "wins" the game
* Input parameters: two teams (with players)
* Output (prints to screen): nothing
* Returns: forfeit if either team doesn't have 4 players, draw if the teams tie, or the name of the team that won.
*/
string game(Team team1, Team team2) {
    double team1Total = 0; //storage for the total points for team 1
    double team2Total = 0; //storage for the total points for team 2
    int team1Size = team1.getNumPlayers(); //storage for the size for team 1
    int team2Size = team2.getNumPlayers(); //storage for the size for team 2
    if (team1Size < 4 || team2Size < 4) { //if either team has less than 4 people, they forfeit
        return "forfeit";
    } else if (team2Size >= 4 && team1Size >= 4) { //if both teams have greater than 4 people
        for (int i = 0; i < 4; i++) {
            team1Total = team1Total+ team1.getPlayerPoints(i); //total the 4 players on team 1 and store to variable
            team2Total = team2Total+ team2.getPlayerPoints(i); //total the 4 players on team 2 and store to variable
        }
        if (team1Total == team2Total) { //if the two teams tie
            return "draw"; //output tie
        } else if (team1Total > team2Total) { //if team 1 wins
            return team1.getTeamName(); //team 1 wins
        } else {
            return team2.getTeamName(); //team 2 wins
        }
    }
    return "Error"; //just in case we somehow don't return gracefully
}

int main() {
    //Test Case 1
    //Expected Output
    /*
    The winner is: Seg Faultline
    */
    Team team1("Seg Faultline");
    team1.readRoster("Test_Files/roster1.txt");
    Team team2("Team Maim");
    team2.readRoster("Test_Files/roster2.txt");
    string winner = game(team1, team2);
    cout << "The winner is: " << winner << endl;

    cout << endl;

    //Test Case 2
    //Expected Output
    /*
    The winner is: forfeit
    */
    Team team3("Hurt Shoebox");
    team3.readRoster("Test_Files/InvalidFile.txt");
    string winnergame2 = game(team3, team2);
    cout << "The winner is: " << winnergame2 << endl;
}