#include "match.h"

queue *createMatches(teamNode *headTeam)
{
    queue *matches=NULL;
    matches = createQueue();
    
    for(teamNode *curr = headTeam; curr && curr->nextTeam; curr=curr->nextTeam->nextTeam)
        {
            enQueue(matches, curr, curr->nextTeam);
        }
    return matches;  
}

queue *createMatchesFromStack(stackNode **headTeam)
{
    queue *matches=NULL;
    
    matches = createQueue();

    while(!StackIsEmpty((*headTeam)))
    {
        teamNode *team1, *team2;
        team1 = (teamNode*)malloc(sizeof(teamNode));
        team2 = (teamNode*)malloc(sizeof(teamNode));
        team1->nextTeam = team2->nextTeam = NULL;
        deepCopy_team(&team1->teamInfo, (*headTeam)->team);
        deepCopy_team(&team2->teamInfo, (*headTeam)->next->team);
        enQueue(matches, team1, team2);
        pop(headTeam);
        pop(headTeam);
    }

    /*for(stackNode *curr = (*headTeam); curr && curr->next; curr=curr->next->next)
        {
            enQueue(matches, curr, curr->next);
        }
    deleteWinnersStack(headTeam);*/
    return matches;  
}

void getWinnersAndLosers(queue *matches, stackNode **winners, stackNode **losers)
{
    while(!QueueIsEmpty(matches))
    {
        if(matches->front->team1.score > matches->front->team2.score)
        {
            matches->front->team1.score++;
            push(winners, matches->front->team1);
            push(losers, matches->front->team2);
        }
        else
        {
            matches->front->team2.score++;
            push(winners, matches->front->team2);
            push(losers, matches->front->team1);
        }
        deQueue(matches);
    }
}  

void printMaches(queueNode *headTeam, char *fileN, int round)
{
    FILE *f = fopen(fileN, "a");
    queueNode *curr = headTeam;

    if(f == NULL)
    {
        printf("File cannot open");
        exit(1);
    }

    fprintf(f, "\n--- ROUND NO:%d\n", round);
    while(curr != NULL)
    {
        fprintf(f, "%-33s-%33s\n", curr->team1.teamName, curr->team2.teamName);
        curr = curr->next;
    }

    fclose(f);
}