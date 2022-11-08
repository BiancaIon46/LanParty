#ifndef TEAM_H
#define TEAM_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include "players.h"

typedef struct dataTeam
{
    int NoPlayers;
    float score;
    char *teamName;
    playerNode *headPlayer;
}dataTeam;

typedef struct teamNode
{
    dataTeam teamInfo;
    struct teamNode *nextTeam;
}teamNode;

void readData_team(dataTeam *, FILE *);
void deepCopy_team(dataTeam *, dataTeam );
void addAtBeginning_team(teamNode **, dataTeam );
void display_teamInfo(teamNode * );
void display_teamNames(teamNode * , char *);
void deleteTeamByScore(teamNode **, int );
int teamsToBeDeleted(int );

#endif