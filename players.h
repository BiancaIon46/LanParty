#ifndef PLAYERS_H
#define PLAYERS_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct dataPlayer
{
    char *firstname;
    char *secondname;
    int points;
}dataPlayer;

typedef struct playerNode
{
    dataPlayer playerInfo;
    struct playerNode *nextPlayer;
}playerNode;

void readData_player(dataPlayer *, FILE *);
void deepCopy_player(dataPlayer *, dataPlayer );
void addAtBeginning_player(playerNode **, dataPlayer);
void display_playersInfo(playerNode *);
void deletePlayerList(playerNode **);

#endif