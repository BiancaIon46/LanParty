#ifndef QUEUE_H
#define QUEUE_H
#include "team.h"

typedef struct queueNode
{
    dataTeam team1;
    dataTeam team2;
    struct queueNode *next;
}queueNode;

typedef struct queue
{
    queueNode *front, *rear;   
}queue;

queue* createQueue();
void enQueue(queue *, teamNode *, teamNode *);
int QueueIsEmpty(queue *);
void deQueue(queue *);

#endif