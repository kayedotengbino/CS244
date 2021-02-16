#ifndef SET_H
#define SET_H
#include <stdio.h>
#include <stdlib.h>

// think of this as a private structure
typedef struct tnode *treeptr;
struct tnode {
	int item;
	treeptr left;
	treeptr right;
};

// think of these as private functions/methods
treeptr createNode(int item);
int countNodes(treeptr t);
void addInTree(treeptr t,int x);
void inDisplay(treeptr t);


//Implement these functions
int findMinInTree(treeptr t); // assume not empty
int findMaxInTree(treeptr t); // assume not empty
int findSumInTree(treeptr t);
int freqInTree(treeptr t,int x);
int containsInTree(treeptr t,int x);
void clearTree(treeptr t);


// This is the implementation of the set
// not very nice, since there is only one field
struct stat {
	treeptr root;
};

typedef struct stat *Stat;

void findItemAt(treeptr t,int mid,int *pos,int *item);

Stat newStat();
void destroy(Stat *s);

void add(Stat s,int x);
void display(const char *name,Stat s);
int getCount(Stat s);
int findMin(Stat s);
int findMax(Stat s);
int findRange(Stat s);
int findSum(Stat s);
float findMean(Stat s);
float findMedian(Stat s);
int contains(Stat s,int x);
int frequency(Stat s,int x);
int isEmpty(Stat s);
void clear(Stat s);
float standardDeviation(Stat s);

#endif
