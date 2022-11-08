#ifndef BST_H
#define BST_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "team.h"

typedef struct bstNode
{
    dataTeam team;
    struct bstNode *left, *right;
}bstNode;

bstNode *createBst(dataTeam );
bstNode *insertBst(bstNode *, dataTeam );
void printBst(bstNode *, FILE *);
void deleteBst(bstNode **);

#endif