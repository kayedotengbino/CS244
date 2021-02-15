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

//add if there is a root
/*void add(treeptr t, int x)
{
	treeptr temp = createNode(x);
	treeptr p = t;	//t is the root
	
	while(p != NULL) 
	{
		if(x < p->item)
		{
			if(p->left == NULL)	//found the position
			{
				p->left = temp;
				temp->parent = p;
				break;				
			}	
			else 
				p = p->left;	//move to the left if p != NULL
		}
		else
		{
			if(p->right == NULL)	//found the position
			{
				p->right = temp;
				temp->parent = p;	
				break;			
			}	
			else 
				p = p->right;	//move to the right if p != NULL
		}
	}
}*/

//Version 2, 2 pointers moving, There is a loop
void addWithRoot(treeptr t, int x)
{
	treeptr temp = createNode(x);
	treeptr p = t;	//t is the root
	treeptr prev = t;	//always pointing to the parent
	
	while(p != NULL) 
	{
		prev = p;
		
		if(x < p->item)
			p = p->left;
		else
			p = p->right;	//move to the right if p != NULL
	}
	
	if(x < prev->item)
		prev->left = temp;
	else
		prev->right = temp;
	
	//p = temp;
		
	temp->parent = prev;
}


//recursive version, root can be NULL, no root
/*void add(treeptr *t, int x)
{
	if(*t == NULL)
		*t = createNode(x);
	else
		addWithRoot(*t, x);
}*/


//recursive, no root, no parent
/*void add(treeptr *t, int x)
{
	if(*t == NULL)
		*t = createNode(x);
	else if(x < (*t)->item)
		add(&(*t)->left, x);
	else
		add(&(*t)->right, x);
}*/

//iterative
int containsV1(treeptr t,int x)
{
	treeptr p = t;	
	
	while(p != NULL)
	{
		if(x < p->item)
			p = p->left;	
		else if(x > p->item)
			p = p->right;
		else
			return 1;
	}
	
	return 0;
}

//Recursive
int containsV2(treeptr t,int x)
{
	if(t != NULL)
	{
		if(t->item == x)
			return 1;
			
		if(containsV2(t->left, x))
			return 1;
			
		if(containsV2(t->right, x))
			return 1;
	}
	
	return 0;
}

//add recursive with root
void addV2(treeptr t, int x)
{
	if(x > t->item)
	{
        if(t->right == NULL)
            t->right = createNode(x);
        else
            addV2(t->right, x);
    }
	else
	{
        if(t->left == NULL)
            t->left = createNode(x);
        else
            addV2(t->left, x);
    }
}

int main()
{
	treeptr root = NULL;
	root = createNode(100);	//establish the root before adding anything
	
	//add
	addV2(root, 50);
	addV2(root, 30);
	addV2(root, 75);
	addV2(root, 200);
	addV2(root, 250);
	addV2(root, 125);
	addV2(root, 160);
	
	//printf("Preorder: "); preDisplay(root);
	
	printf("\nInorder: "); inDisplay(root);
	printf("\nContainsv1 [0] = %d", containsV1(root,0));
	printf("\nContainsv1 [50] = %d", containsV1(root,50));
	printf("\nContainsv2 [8] = %d", containsV2(root,0));
	printf("\nContainsv2 [160] = %d", containsV2(root,50));
	
	/*printf("\ncount = %d", countNodes(root));
	printf("\neven = %d", countEven(root));
	printf("\nodd = %d", countOdd(root));
	printf("\ncontains [2] = %d", contains(root,2));*/
	
	return 0;
}
