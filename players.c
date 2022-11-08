#include "players.h"

void readData_player(dataPlayer *player, FILE *file)
{
    char name[50];

    fscanf(file, "%s", name);
    player->secondname=strdup(name); // citesc numele de familie
    
    fscanf(file, "%s", name); // citesc prenumele
    player->firstname=strdup(name);

    fscanf(file, "%d", &player->points);
}

void deepCopy_player(dataPlayer *a, dataPlayer b)
{
    a->firstname = strdup(b.firstname);
    a->secondname = strdup(b.secondname);
    a->points = b.points;
}

void addAtBeginning_player(playerNode **headPlayer, dataPlayer player)
{
    playerNode *newPlayer;

    newPlayer = (playerNode*)malloc(sizeof(playerNode));
    newPlayer->nextPlayer=NULL;

    deepCopy_player(&newPlayer->playerInfo, player);

    if(*headPlayer == NULL)
        (*headPlayer)=newPlayer;
    else
    {
        newPlayer->nextPlayer = (*headPlayer);
        (*headPlayer) = newPlayer;
    }
}

void display_playersInfo(playerNode *headPlayer)
{
    for(headPlayer; headPlayer; headPlayer=headPlayer->nextPlayer)
    {
        printf("%s %s %d\n", headPlayer->playerInfo.firstname, headPlayer->playerInfo.secondname, headPlayer->playerInfo.points);
    }
}

void deletePlayerList(playerNode **head)
{
    playerNode *temp;

    while((*head) != NULL)
    {
        temp = (*head);
        (*head) = (*head)->nextPlayer;
        free(temp);
    }
    (*head) = NULL;
}