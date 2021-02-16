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

//private
float getSummation(treeptr t, float mean)
{
    if(t != NULL)
        return pow((t->item - mean),2) + getSummation(t->left,mean) + getSummation(t->right,mean);
    else    
        return 0;
}

float standardDeviation(Stat s)
{
    float mean = findMean(s);
    float sum = getSummation(s->root, mean);
    float count = countNodes(s->root) - 1;

    return sqrt(sum/count);
}

float findMedian(Stat s)
{
    if (s->root == NULL) 
        return 0; 
  
    int count = countNodes(s->root), ctr = 0; 
    treeptr current = s->root, pre, prev; 
  
    while (current != NULL) 
    { 
        if (current->left == NULL) 
        { 
            ctr++; // count current node 
  
            // check if current node is the median 
            if (count % 2 != 0 && ctr == (count/2)+1)   //odd
                return prev->right->item; 
            else if (count % 2 == 0 && ctr == (count/2)+1) // Even case 
                return (float)(prev->item + current->item)/2; 
  
            prev = current; // Update prev for even no of nodes 
  
            current = current->right;  //Move to the right 
        } 
        else
        { 
            //Find the inorder predecessor of current 
            pre = current->left; 

            while (pre->right != NULL && pre->right != current) 
                pre = pre->right; 
  
            //Make current as right child of its inorder predecessor
            if (pre->right == NULL) 
            { 
                pre->right = current; 
                current = current->left; 
            } 
            //Revert the changes made in if part to restore the original tree
            else
            { 
                pre->right = NULL; 
                prev = pre; 
  
                ctr++; // Count current node 
  
                // Check if the current node is the median 
                if (count % 2 != 0 && ctr == (count/2)+1) 
                    return current->right->item; 
  
                else if (count%2==0 && ctr == (count/2)+1) 
                    return (float)(prev->item+current->item)/2; 
  
                // update prev node for the case of even 
                prev = current; 
                current = current->right; 
  
            }
        } 
    } 
}
