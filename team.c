#include "team.h"

void readData_team(dataTeam *team, FILE *file)
{
    char name[50];
    int i;
    dataPlayer player;

    team->headPlayer = NULL;

    fscanf(file, "%d", &team->NoPlayers);
    fgets(name, 50, file);

    strcpy(name, name+1); // de verificat in caz ca nu merge codul
    if(name[strlen(name)-2]==' ')
        name[strlen(name)-2]='\0';
    else
        name[strlen(name)-1]='\0';
    team->teamName=strdup(name);
    team->score=0;

    for(i=0; i<team->NoPlayers; i++)
    {
        readData_player(&player, file);
        team->score += player.points;
        addAtBeginning_player(&team->headPlayer, player);
    }

    team->score = team->score / team->NoPlayers;
}

void deepCopy_team(dataTeam *a, dataTeam b)
{
    a->NoPlayers = b.NoPlayers;
    a->teamName = strdup(b.teamName);
    a->score = b.score;
    a->headPlayer = b.headPlayer;
}

void addAtBeginning_team(teamNode **headTeam, dataTeam team)
{
    teamNode *newTeam;

    newTeam = (teamNode*)malloc(sizeof(teamNode));
    newTeam->nextTeam=NULL;

    deepCopy_team(&newTeam->teamInfo, team);
    if(*headTeam==NULL)
        (*headTeam)=newTeam;
    else
    {
        newTeam->nextTeam = (*headTeam);
        (*headTeam) = newTeam;
    }
}

void display_teamInfo(teamNode *headTeam)
{
    for(headTeam; headTeam!=NULL; headTeam=headTeam->nextTeam)
    {
        printf("%d %.2f %s \n", headTeam->teamInfo.NoPlayers, headTeam->teamInfo.score, headTeam->teamInfo.teamName);
        display_playersInfo(headTeam->teamInfo.headPlayer);
        printf("\n");
    }

}

void display_teamNames(teamNode *headTeam, char *fileN)
{
    FILE *file;

    if((file = fopen(fileN, "w")) == NULL)
    {
        printf("Cannot open file.");
        exit(1);
    }

    for(headTeam; headTeam!=NULL; headTeam=headTeam->nextTeam)
        fprintf(file, "%s\n", headTeam->teamInfo.teamName);

    fclose(file);
}

int teamsToBeDeleted(int NoTeams)
{
    int NoToDelete=0,i=0;

    while(pow(2,i) <= NoTeams)
        i++;

    NoToDelete = NoTeams - pow(2,i-1);

    return NoToDelete;
}

void deleteTeamByScore(teamNode **headTeam, int NoToDelete)
{
    int i;
    float mini;
    teamNode *temp, *aux=NULL;

    for(i=0; i<NoToDelete; i++)
    {
        mini=(*headTeam)->teamInfo.score;
        temp=(*headTeam);
        for(teamNode *curr = (*headTeam); curr && curr->nextTeam!=NULL; curr=curr->nextTeam)
            if(curr->nextTeam->teamInfo.score < mini)
            {
                mini = curr->nextTeam->teamInfo.score;
                temp = curr;
            }
        if (temp == (*headTeam) && mini == (*headTeam)->teamInfo.score)
        {
            aux=(*headTeam);
            (*headTeam) = (*headTeam)->nextTeam;
            free(aux);
        }
        else
        {
            aux = temp->nextTeam;
            temp->nextTeam = temp->nextTeam->nextTeam;
            free(aux);
        }
    }
}