#include <stdio.h>
#include <stdlib.h>

typedef struct node *nodeptr;	//Nodeptr is a pointer to struct node

struct node
{
	int item;
	nodeptr next;	
};

typedef nodeptr IntList;

IntListList newIntList();	//create header nodes, return IntList
void destroy(IntList *list);
void clear(IntList list);
void addFront(IntList list, int x);
void addRear(IntList list, int x);
void removeFront
