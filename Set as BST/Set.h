#ifndef SET_H
#define SET_H
#include <stdio.h>
#include <stdlib.h>

//think of this as a private structure
typedef struct tnode *treeptr;

struct tnode
{
	int item;
	treeptr left;
	treeptr right;
};

//think of this as a private functions/methods
treeptr createNode(int item);	
int countNodes(treeptr t);	
void addInTree(treeptr t, int x);	
void inDisplay(treeptr t);	
	
/*
	THis is the implementation of the set
	Not very nice, since there is only one field
*/
struct set
{
	treeptr root;
};

typedef struct set *Set;

Set newSet();
void destroySet(Set *s);
void add(Set s, int x);
void display(const char *name, Set s);
int cardinallity(Set s);
void clear(Set s);	
int contains(const Set s,int elem);
int isEmpty(const Set s);
int isSubset(const Set s1,const Set s2);
int areDisjoint(const Set s1,const Set s2);
Set getUnion(const Set s1,const Set s2);
Set getIntersection(const Set s1,const Set s2);
Set getDifference(const Set s1,const Set s2);

#endif
