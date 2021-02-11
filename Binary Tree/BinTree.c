#include <stdlib.h>
#include <stdio.h>

/*
    binary tree in general
    sorry, brute force
*/

typedef struct tnode *treeptr;

struct tnode
{
    int item;
    treeptr left;
    treeptr right;
    treeptr parent; //optional
};

treeptr createNode(int item)
{
    treeptr temp = (treeptr)malloc(sizeof(struct tnode));
    temp->item = item;
    temp->left = temp->right = temp->parent = NULL;

    return temp;
}

//make a node containing item the left child of t
void setLeft(treeptr t, int item)
{
    treeptr temp = createNode(item);
	t->left = temp;
	temp->parent = t;
}

//make a node containing item the Right side of t
void setRight(treeptr t, int item)
{
	treeptr temp = createNode(item);
	t->right = temp;
	temp->parent = t;
}

int isRoot(treeptr t)
{
	return t->parent == NULL;
}

int isLeft(treeptr t)
{
	int flag = 0;
	
	if(t->parent != NULL)
	{
		if(t->parent->left == t)
			flag = 1;
	}
	
	return flag;
}

int isRight(treeptr t)
{
	int flag = 0;
	
	if(t->parent != NULL)
	{
		if(t->parent->right == t)
			flag = 1;
	}
	
	return flag;
}

treeptr getLeft(treeptr t)
{
	return t->left;
}

treeptr getRight(treeptr t)
{
	return t->right;
}

/*
	ALGO:
	visit the root (perform any operation)
	traverse the left subtree in pre-order
	traverse the right subtree in pre-order
*/
void preDisplay(treeptr t)
{
	if(t != NULL)	//will not do anything if t == NULL
	{
		printf("%d ", t->item);	//visit the root
		
		//recursive
		preDisplay(t->left);	//traverse the left subtree in pre-order
		preDisplay(t->right);	//traverse the right subtree in pre-order
	}
}

//Do not use local variables because they are stored in stack
int countNodes(treeptr t)
{
	if(t != NULL)
		return 1 + countNodes(t->left) + countNodes(t->right);	//count
	else
		return 0;
}

//1
void inDisplay(treeptr t)
{
	if(t != NULL)	//will not do anything if t == NULL
	{
		//recursive
		preDisplay(t->left);	//traverse the left subtree in pre-order
		
		printf("%d ", t->item);	//visit the root
		
		preDisplay(t->right);	//traverse the right subtree in pre-order
	}
}

//2
int countEven(treeptr t)
{
	if(t != NULL)
	{
		if(t->item % 2 == 0)
			return (t->item % 2 == 0) ? countNodes(t->left)+1 : countNodes(t->right)+1;	//count; +1 including the root
		else
			return (t->item % 2 == 0) ? countNodes(t->left) : countNodes(t->right);
	}	
	else
		return 0;
}

//3
int contains(treeptr t,int x)
{
	if(t != NULL)
	{
		if(t->item == x)
			return 1;
			
		if(contains(t->left, x))
			return 1;
			
		if(contains(t->right, x))
			return 1;
	}
}

int countOdd(treeptr t)
{
	if(t != NULL)
	{
		if(t->item % 2 != 0)
			return (t->item % 2 != 0) ? countNodes(t->left)+1 : countNodes(t->right)+1;	//count; +1 including the root
		else
			return (t->item % 2 != 0) ? countNodes(t->left) : countNodes(t->right);
	}	
	else
		return 0;
}

int main()
{
	treeptr root = createNode(1);	//establish the root before adding anything
	
	//add
	setLeft(root,2);
	setRight(root,3);
	setLeft(getLeft(root),4);
	setRight(getRight(root),5);
	setRight(getLeft(root),7);
	setLeft(getRight(root),10);
	
	printf("Preorder: ");
	preDisplay(root);
	
	printf("\nInorder: ");
	inDisplay(root);
	
	printf("\ncount = %d", countNodes(root));
	printf("\neven = %d", countEven(root));
	printf("\nodd = %d", countOdd(root));
	printf("\ncontains [0] = %d", contains(root,0));
	printf("\ncontains [2] = %d", contains(root,2));
	
	return 0;
}
