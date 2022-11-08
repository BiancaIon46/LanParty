#ifndef MATCH_H
#define MATCH_H
#include "queue.h"
#include "team.h"
#include "stack.h"

queue *createMatches(teamNode *);
queue *createMatchesFromStack(stackNode **);
void printMaches(queueNode *, char *, int);
void getWinnersAndLosers(queue *, stackNode **, stackNode **);
#endif