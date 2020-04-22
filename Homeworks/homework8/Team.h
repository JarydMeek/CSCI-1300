#include "Player.h"
#include <iostream>
#include <vector>
using namespace std;

#ifndef TEAM_H
#define TEAM_H


class Team 
{ 
    private:
        string teamName;
        vector <Player> players;
        int split(string, char, string[], int);

    public:
        Team(); // Default constructor
        Team(string); // Parameterized constructor
        void setTeamName(string);
        void readRoster(string);
        string getPlayerName(int);
        double getPlayerPoints(int);
        int getNumPlayers();
        string getTeamName();
}; 

#endif 