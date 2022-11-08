#include "bst.h"

bstNode *createBst(dataTeam team)
{
    bstNode *node = (bstNode*)malloc(sizeof(bstNode));
    deepCopy_team(&node->team, team);
    node->left = node->right = NULL;
    return node;
}

bstNode *insertBst(bstNode *node, dataTeam team)
{
    if(node == NULL)
        return createBst(team);
    if(team.score < node->team.score || (team.score == node->team.score && strcmp(team.teamName, node->team.teamName) <0))
        node->left = insertBst(node->left, team);
    else
        node->right = insertBst(node->right, team);
    return node;
}

void printBst(bstNode *bst, FILE *f) ///DRS
{
    if(bst == NULL)
        return;

    printBst(bst->right, f);
    fprintf(f, "%-34s-  %3.2f\n", bst->team.teamName, bst->team.score);
    printBst(bst->left, f);
}

void deleteBst(bstNode **bst)
{
    if(*bst == NULL) 
        return;

    deleteBst(&(*bst)->left);
    deleteBst(&(*bst)->right);

    free(*bst);

    (*bst) = NULL;
}