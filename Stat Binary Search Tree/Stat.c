#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Stat.h"

Stat newStat()
{
    Stat s = (Stat)malloc(sizeof(struct stat));
    s->root = NULL;
}

treeptr createNode(int item)
{
    treeptr temp = (treeptr)malloc(sizeof(struct tnode));
    temp->item = item;
    temp->left = temp->right = NULL;

    return temp;
}

int countNodes(treeptr t)
{
    if(t == NULL)
        return 0;
    else
        return 1 + countNodes(t->left) + countNodes(t->right);
}

void addInTree(treeptr t,int x)
{
    treeptr temp = createNode(x);
    treeptr p = t;
    treeptr prev = t;

    while(p != NULL)
    {
        prev = p;

        if(x < p->item)
            p = p->left;
        else    
            p = p->right;
    }

    if(x < prev->item)
        prev->left = temp;
    else
        prev->right = temp;
}

void inDisplay(treeptr t)
{
    if(t != NULL)
    {
        inDisplay(t->left);
        printf("%d ", t->item);
        inDisplay(t->right);
    }
}

void add(Stat s,int x)
{
    if(s->root == NULL)
        s->root = createNode(x);
    else    
        addInTree(s->root, x);
}

void display(const char *name,Stat s)
{
    printf("%s = [ ", name);
    inDisplay(s->root);
    printf("]\n");
}

int getCount(Stat s)
{
    return countNodes(s->root);
}

int isEmpty(Stat s)
{
    return s->root == NULL;
}

void clearTree(treeptr t)
{
    if(t == NULL)
    {
        clearTree(t->left);
        clearTree(t->right);
    }
}

void clear(Stat s)
{
    while(s->root != NULL)
    {
        clearTree(s->root);
        s->root = NULL;
    }
}

void destroy(Stat *s)
{
    clear(*s);
    free(*s);
}

int findMinInTree(treeptr t)
{
    treeptr current = t;

    while(current->left != NULL)
        current = current->left;

    return current->item;
}

int findMin(Stat s)
{
    return findMinInTree(s->root);
}

int findMaxInTree(treeptr t)
{
    treeptr current = t;

    while(current->right != NULL)
        current = current->right;

    return current->item;
}

int findMax(Stat s)
{
    return findMaxInTree(s->root);
}

int findRange(Stat s)
{
    return findMaxInTree(s->root) - findMinInTree(s->root);
}

int findSumInTree(treeptr t)
{
    if(t == NULL)
        return 0;

    return (t->item + findSumInTree(t->left) + findSumInTree(t->right));
}

int findSum(Stat s)
{
    return findSumInTree(s->root);
}

int freqInTree(treeptr t,int x)
{
    if(t != NULL)
        return (t->item == x) + freqInTree(t->left,x) + freqInTree(t->right,x) ;
    
    return 0;
}

int frequency(Stat s,int x)
{
    return freqInTree(s->root, x);
}

int containsInTree(treeptr t,int x)
{
   if(t != NULL)
    {
        if(x == t->item)
            return 1;

        if(containsInTree(t->left, x))
            return 1;

        if(containsInTree(t->right, x))   
            return 1;
    }

    return 0;
}

int contains(Stat s,int x)
{
    return containsInTree(s->root,x);
}

float findMean(Stat s)
{
    return (float)findSumInTree(s->root) / (float)countNodes(s->root);
}

float standardDeviation(Stat s)
{
    float stdDeviation = 0;
    float mean = findMean(s);

    treeptr p = s->root;

    if(p != NULL)
    {
        if(p->left != NULL)
        {
            stdDeviation += pow((p->item) - mean, 2);
            p = p->left;
        }
        if(p->right != NULL)
        {
            stdDeviation += pow((p->item) - mean, 2);
            p = p->right;
        }
    }

    stdDeviation += pow((p->item) - mean, 2);

    return sqrt(stdDeviation / (countNodes(s->root) - 1));
}
/*
float findMedian(Stat s)
{
    if(countNodes(s->root) % 2 == 0)
        return (getCount(s->root)/2) + 1
}*/
