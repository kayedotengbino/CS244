#ifndef STATLINK_H
#define STATLINK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node *nodeptr;
struct node {
	int item;
	nodeptr next;	
};

typedef nodeptr SetLink;

SetLink newSetLink();
void add(SetLink s,int elem);
void display(const char *name,const SetLink s);

void removeIt(SetLink s,int elem);
void destroy(SetLink *s);
int contains(const SetLink s,int elem);
int cardinality(const SetLink s);
int isEmpty(const SetLink s);
void clear(SetLink s);
int isSubset(const SetLink s1,const SetLink s2);
int areDisjoint(const SetLink s1,const SetLink s2);
SetLink getUnion(const SetLink s1,const SetLink s2);
SetLink getIntersection(const SetLink s1,const SetLink s2);
SetLink getDifference(const SetLink s1,const SetLink s2);

#endif