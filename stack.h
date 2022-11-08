#ifndef STACK_H
#define STACK_H
#include "team.h"

typedef struct stackNode
{
    dataTeam team;
    struct stackNode *next;
}stackNode;

void push(stackNode **, dataTeam );
void pop(stackNode **);
int StackIsEmpty(stackNode *);
void deleteLosers(teamNode **, dataTeam *);
void deleteStack(teamNode **,stackNode **);
void printWinners(stackNode *, char *, int );
void deleteWinnersStack(stackNode **);

#endif