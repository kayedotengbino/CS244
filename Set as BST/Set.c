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

void clear(Set s)
{
	treeptr p = s->root;
	
	if(p != NULL)
	{
		while(p->left != NULL)
		{
			p->left = 0;
		}
		
		while(p->right != NULL)
		{
			p->right= 0;
		}
	}
	
	s->root = NULL;
}

void destroySet(Set *s)
{
	clear(*s);
	free(*s);
}

int contains(const Set s,int elem)
{
	treeptr p = s->root;	
	
	while(p != NULL)
	{
		if(elem < p->item)
			p = p->left;	
		else if(elem > p->item)
			p = p->right;
		else
			return 1;
	}
	
	return 0;
}

int isEmpty(const Set s)
{
	return s->root == NULL;
}

int isSubset(const Set s1,const Set s2)
{
	int res = 0;
	
	treeptr p = s1->root;
	
	if(cardinality(s1) < cardinality(s2))
	{
		res = 1;
		
		while(p != NULL)
		{
			if(!contains(s2, p->item))
			{
				res = 0;
				break;
			}
			
			p = p->right;
		}
	}
	
	return res;
}

int areDisjoint(const Set s1,const Set s2)
{
	int res = 0;
	
	treeptr p = s1->root;
	
	if(cardinality(s1) < cardinality(s2))
	{
		res = 1;
		
		while(p != NULL)
		{
			if(contains(s2, p->item))
			{
				res = 0;
				break;
			}
			
			p = p->right;
		}
	}
	
	return res;
}

//needs to be fixed
Set getUnion(const Set s1,const Set s2)
{
    Set res = newSet();
    
    treeptr p = s1->root;
    treeptr q = s2->root;

    while(p != NULL)
    {
        add(res, p->item);
        p = p->right;
    }

    while(q != NULL)
    {
        if(!contains(res, q->item))
            add(res, q->item);
        
        q = q->right;
    }

    return res;
}

//needs to be fixed
Set getIntersection(const Set s1,const Set s2)
{
	Set res = newSet();
	
	treeptr p = s1->root;
	treeptr q = s2->root;
	
	while(p != NULL)
	{
		if(contains(s2, p->item))
            add(res, p->item);
			
		p = p->right;
	}
	
	return res;
}

//needs to be fixed
Set getDifference(const Set s1,const Set s2)
{
	 Set res = newSet();
    
    treeptr p = s1->root;

    while(p != NULL)
    {
        if(!contains(s2, p->item))
            add(res, p->item);
        
        p = p->right;
    }

    return res;
}
