#include "avl.h"

int nodeHeight(avlNode *root)
{
    int hs,  hd;

    if(root == NULL)
        return -1;
    hs = nodeHeight(root->left);
    hd = nodeHeight(root->right);

    return 1 + ((hs>hd) ? hs:hd);
}

int maxValue(int a, int b)
{
    return ((a>b) ? a:b);
}

avlNode *rightRotation(avlNode *z)
{
    avlNode *y = z->left;
    avlNode *T3 = y->right;

    y->right = z;
    z->left = T3;

    z->height = maxValue(nodeHeight(z->left), nodeHeight(z->right)) + 1;
    y->height = maxValue(nodeHeight(y->left), nodeHeight(y->right)) + 1;

    return y;
}

avlNode *leftRotation(avlNode *z)
{
    avlNode *y = z->right;
    avlNode *T2 = y->left;

    y->left = z;
    z->right = T2;

    z->height = maxValue(nodeHeight(z->left), nodeHeight(z->right)) + 1;
    y->height = maxValue(nodeHeight(y->left), nodeHeight(y->right)) + 1;

    return y;
}

avlNode *LRRotation(avlNode *z)
{
    z->left = leftRotation(z->left);
    return rightRotation(z);
}

avlNode *RLRotation(avlNode *z)
{
    z->right = rightRotation(z->right);
    return leftRotation(z);
}

avlNode *insertAvl(avlNode *node, dataTeam team)
{
    if(node == NULL)
    {
        node = (avlNode*)malloc(sizeof(avlNode));
        deepCopy_team(&(node->team), team);
        node->height = 0;
        node->left = node->right = NULL;
        return node;
    }
    if(team.score < node->team.score || (team.score == node->team.score && strcmp(team.teamName, node->team.teamName) < 0))
        node->left = insertAvl(node->left, team);
    else
        node->right = insertAvl(node->right, team);

    node->height = 1 + maxValue(nodeHeight(node->left), nodeHeight(node->right));

    int k = (nodeHeight(node->left) - nodeHeight(node->right));

    if(k > 1 && (team.score < node->left->team.score || (team.score == node->left->team.score && strcmp(team.teamName, node->left->team.teamName) < 0)))
        return rightRotation(node);
    
    if(k < -1 && (team.score > node->right->team.score || (team.score == node->right->team.score && strcmp(team.teamName, node->right->team.teamName) > 0)))
        return LRRotation(node);
    
    if(k > 1 && (team.score > node->left->team.score || (team.score == node->left->team.score && strcmp(team.teamName, node->left->team.teamName) > 0)))
        return RLRotation(node);
    
    if(k < -1 && (team.score < node->right->team.score || (team.score == node->right->team.score && strcmp(team.teamName, node->right->team.teamName) < 0)))
        return leftRotation(node);
    
    return node;
}

void populateAvl(avlNode **avl, bstNode *bst)
{
    if(bst == NULL)
        return ;

    populateAvl(avl, bst->right);
    *avl = insertAvl((*avl), bst->team);
    populateAvl(avl, bst->left);
}

void printAvl(avlNode *avl, FILE *f, int level)
{
    if(avl == NULL)
        return;

    printAvl(avl->right, f, level+1);
    printAvl(avl->left, f, level+1);
    if(level == 2)
        fprintf(f, "%s\n", avl->team.teamName);
   
}

void deleteAvl(bstNode **avl)
{
    if(*avl == NULL) 
        return;

    deleteAvl(&(*avl)->left);
    deleteAvl(&(*avl)->right);

    free(*avl);

    (*avl) = NULL;
}