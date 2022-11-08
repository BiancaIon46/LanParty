#include "players.h"
#include "team.h"
#include "stack.h"
#include "queue.h"
#include "match.h"
#include "bst.h"
#include "avl.h"

int main(int argc, char *argv[])
{
    FILE *file;
    teamNode *headTeam = NULL;
    dataTeam team;
    int NoTeams, NoToDelete, i, cerinte[6], round = 0;
    stackNode *winners = NULL, *losers = NULL;
    queue *matches = NULL;
    bstNode *bst = NULL;
    avlNode *avl = NULL;


    if((file = fopen(argv[2], "r"))==NULL)
    {
        printf("Cannot open file.");
        exit(1);
    }

    if(!feof(file))
        fscanf(file, "%d", &NoTeams);

    for(i=0; i<NoTeams; i++)
    {
        readData_team(&team, file);
        addAtBeginning_team(&headTeam, team);
    }

    fclose(file);

    // display_teamInfo(headTeam);
    
     if((file = fopen(argv[1], "r"))==NULL)
    {
        printf("Cannot open file.");
        exit(1);
    }

    while(!feof(file))
    {
        fscanf(file, "%d %d %d %d %d", &cerinte[1], &cerinte[2], &cerinte[3], &cerinte[4], &cerinte[5]);
    }

    fclose(file);

    if(cerinte[1] && !cerinte[2])
        display_teamNames(headTeam, argv[3]);
    
    if(cerinte[2])
    {
        NoToDelete = teamsToBeDeleted(NoTeams); // returneaza numarul de echipe care trebuie sa fie sterse pentru a ajunge la o putere a lui 2

        NoTeams -= NoToDelete;

        //printf("---%d-----", NoToDelete);
        deleteTeamByScore(&headTeam, NoToDelete);
        display_teamNames(headTeam, argv[3]);
    }

    if(cerinte[3])
    {
        matches = createMatches(headTeam);
        round++;
            printMaches(matches->front, argv[3], round);

            getWinnersAndLosers(matches, &winners, &losers);
            printWinners(winners, argv[3], round);
            deleteStack(&headTeam, &losers);

            NoTeams /=2;

        while(NoTeams != 1)
        {
            if(NoTeams == 8)
            {
                stackNode *curr = winners;

                while(curr != NULL)
                {
                    bst = insertBst(bst, curr->team);
                    curr = curr->next;
                }   
            }

            matches = createMatchesFromStack(&winners);
            round++;

            printMaches(matches->front, argv[3], round);

            getWinnersAndLosers(matches, &winners, &losers);
            printWinners(winners, argv[3], round);
            deleteStack(&headTeam, &losers);

            NoTeams /=2;
        }
    }

    if(cerinte[4])
    {
        FILE *f;

        if((f = fopen(argv[3], "at")) == NULL)
        {
            printf("File cannot open");
            exit(1);
        }
        
        fprintf(f, "\nTOP 8 TEAMS:\n");
        printBst(bst, f);
        
       // deleteBst(&bst);

        fclose(f);
    }

    if(cerinte[5])
    {
        FILE *f;

        if((f = fopen(argv[3], "at")) == NULL)
        {
            printf("File cannot open");
            exit(1);
        }

        
        populateAvl(&avl, bst);
        
        fprintf(f, "\nTHE LEVEL 2 TEAMS ARE:\n");
        printAvl(avl, f, 0);

        fclose(f);

        deleteBst;
        deleteAvl;
    }    

    return 0;
}