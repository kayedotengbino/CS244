#include <stdio.h>
#include <stdlib.h>

//Dynamically allocated in array (Set)
struct set	//Object
{
	//Data members
	int *items;	//pointer to an array, elements
	int count;
	int size;	//array size
};

typedef struct set *SetArray;	//SetArray is a pointer to a structure

SetArray newSetArray(); 
void destroy(SetArray *s);
void add(SetArray s, int elem);
//void remove(SetArray s, int elem);
int contains(SetArray s, int elem);
void display(const SetArray s);
int cardinality(const SetArray s);	

int main()
{
	SetArray s = newSetArray();
	add(s, 2);
	add(s, 3);
	add(s, 4);
	display(s);
	destroy(&s);
	
	return 0;
}

SetArray newSetArray()
{
	SetArray s = (SetArray)malloc(sizeof(struct set));
	s->items = (int *)malloc(sizeof(int)*10);
	s->count = 0;
	s->size = 10;
	
	return s;
}

void destroy(SetArray *s)
{
	/*
		Free the array first 
		Use '()' becuse of precedence rule
	*/
	free((*s)->items);	
	free(*s);	//Then free the structure
	*s = NULL;	//To avoid dangling referrence
}

void add(SetArray s, int elem)
{
	if(s->count < s->size)
	{
		s->items[s->count++] = elem;
	}
}

void display(const SetArray s)
{
	int i;
	
	printf("{ ");
	
	for(i = 0; i < s->count; i++)
	{
		printf("%d ", s->items[i]);
	}
	printf(" }");
}
