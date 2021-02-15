#include <stdio.h>
#include <stdlib.h>
#include "Set.h"

Set newSet()
{
	Set s = (Set)malloc(sizeof(struct set));
	s->root = NULL;
}

void add(Set s, int x)
{
	if(s->root == NULL)
		s->root = createNode(x);	//establish the root, becomes the root
	else
		addInTree(s->root, x);	//call add in BST
}

void display(const char *name, Set s)
{
	printf("%s = { ", name);
	inDisplay(s->root);
	printf("}\n");
}

int cardinality(Set s)
{
	return countNodes(s->root);
}

//there is a root
void addInTree(treeptr t, int x)
{
	treeptr temp = createNode(x);
	treeptr p = t;	//t is the root
	treeptr prev = t; //pointing to the parent
	
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
		inDisplay(t->left);	//Traverse the left subtree in pre-order
		printf("%d ", t->item);	//visit root
		inDisplay(t->right);	//traverse the right subtree in pre-order
	}
}

int countNodes(treeptr t)
{
	if(t == NULL)
		return 0;
	else
		return 1 + countNodes(t->left) + countNodes(t->right);
}

treeptr createNode(int item)
{
	treeptr temp = (treeptr)malloc(sizeof(struct tnode));
	temp->item = item;
	temp->left = temp->right = NULL;
	
	return temp;
}
