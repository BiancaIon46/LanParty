#ifndef AVL_H
#define AVL_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "bst.h"

typedef struct avlNode
{
    dataTeam team;
    int height;
    struct avlNode *left, *right;
}avlNode;

avlNode *insertAvl(avlNode *, dataTeam );
int maxValue(int , int );
int nodeHeight(avlNode *);
void populateAvl(avlNode **, bstNode *);
void printAvl(avlNode *, FILE *, int );
avlNode *rightRotation(avlNode *);
avlNode *leftRotation(avlNode *);
avlNode *RLRotation(avlNode *);
avlNode *LRRotation(avlNode *);
void deleteAvl(bstNode **);

#endif