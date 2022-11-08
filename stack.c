#include "stack.h"

void push(stackNode **top, dataTeam team)
{
    stackNode *newNode;

    newNode=(stackNode*)malloc(sizeof(stackNode));

    deepCopy_team(&newNode->team, team);
    newNode->next=(*top);
    (*top)=newNode;
}

int StackIsEmpty(stackNode* top)
{
    return (top==NULL);
}

void pop(stackNode **top)
{
    stackNode *temp;

    if(StackIsEmpty(*top))
        return ;

    temp=(*top);

    *top=(*top)->next;
    free(temp);
}

void deleteLosers(teamNode **headTeam, dataTeam *team)
{
    teamNode *curr = *headTeam, *temp;

    if(strcmp((*headTeam)->teamInfo.teamName, (*team).teamName) == 0)
    {
        temp = (*headTeam);
        (*headTeam) = (*headTeam)->nextTeam;
        deletePlayerList(&temp->teamInfo.headPlayer);
        free(temp);
        return ;
    }

    while(curr != NULL && curr->nextTeam != NULL)
    {
        if(strcmp(curr->nextTeam->teamInfo.teamName, (*team).teamName) == 0)
        {
            temp = curr->nextTeam;
            curr->nextTeam = curr->nextTeam->nextTeam;
            deletePlayerList(&temp->teamInfo.headPlayer);
            free(temp);
            return ;
        }
        curr = curr->nextTeam;
    }
}

void deleteStack(teamNode **headTeam, stackNode **top)
{
    stackNode *temp;

    while(*top)
    {
        deleteLosers(&(*headTeam), &(*top)->team);
        temp=(*top);
        *top=(*top)->next;
        free(temp);
    }
    (*top) = NULL;
}

void printWinners(stackNode *headTeam, char *fileN, int round)
{
    FILE *f = fopen(fileN, "a");
    stackNode *curr = headTeam;

    if(f == NULL)
    {
        printf("File cannot open");
        exit(1);
    }

    fprintf(f, "\nWINNERS OF ROUND NO:%d\n", round);
    while(curr != NULL)
    {
        fprintf(f, "%-34s-  %3.2f\n", curr->team.teamName, curr->team.score);
        curr = curr->next;
    }

    fclose(f);
}

void deleteWinnersStack(stackNode **top)
{
    stackNode *temp;

    while(*top)
    {
        temp=(*top);
        *top=(*top)->next;
        free(temp);
    }
    (*top) = NULL;
}
