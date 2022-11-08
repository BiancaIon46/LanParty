#include "queue.h"

queue* createQueue()
{
    queue *q;
    q=(queue*)malloc(sizeof(queue));
    if(q==NULL)
    {
        printf("Mem fail");
        return NULL;
    }

    q->front=q->rear=NULL;

    return q;
}

void enQueue(queue *q, teamNode *team1, teamNode *team2)
{
    queueNode *newNode=(queueNode*)malloc(sizeof(queueNode));
    
    deepCopy_team(&newNode->team1, team1->teamInfo);
    deepCopy_team(&newNode->team2, team2->teamInfo);
    newNode->next=NULL;

    if(q->rear==NULL)
        q->rear=newNode;
    else
    {
        q->rear->next=newNode;
        q->rear=newNode;
    }

    if(q->front==NULL)
        q->front=newNode;
}

int QueueIsEmpty(queue *q)
{
    return (q->front==NULL);
}

void deQueue(queue *q)
{
    queueNode *temp;
    queueNode *aux=NULL;

    if(QueueIsEmpty(q))
        return ;

    temp=q->front;
    q->front=q->front->next;
    free(temp);
}