#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

//private
nodeptr createNode(int x)
{
	nodeptr temp = (nodeptr)malloc(sizeof(struct node));
	temp->item = x;
	temp->next = NULL;
	
	return temp;
}

IntList newIntList()	//create header node
{
	return 
}

void addFront(IntList list, int x)
{
	nodeptr temp = createNode(x);
	temp->next = list->next;
	list->next = temp;
}

void addRear(IntList list, int x)
{
	nodeptr temp = createNode(x);
	nodeptr p = list;
	
	while(p->next != NULL)
	{
		p = p->next;
	}
	p->next = temp;
}

void removeFront(IntList list)
{
	nodeptr temp = list->next;
	
	if(temp != NULL)
	{
		list->next = temp->next;
	}
}

void removeRear(IntList list)
{
	nodeptr prev = list;	//pointing to the header
	nodeptr p = list->next;
	
	if(p != NULL)	//not empty
	{
		while(p->next ! = NULL)	
		{
			prev = p;	//prev = prev->next
			p = p->next;
		}
		free(p);
		prev->next = NULL; 
	}
}

void display(const char *name, const IntList list)
{
	nodeptr p = list->next;
	
	printf("%s = [", name);
	while(p != NULL)
	{
		printf("%d ", p->item);
		p = p->next;
	}
	printf("]\n");
}
