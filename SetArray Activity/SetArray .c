#include <stdio.h>
#include <stdlib.h>

struct set {
	int *items; // pointer to an array, elements
	int count;
	int size; // array size
};

typedef struct set *SetArray;

SetArray newSetArray();
void destroy(SetArray *s);
void add(SetArray s, int elem);
void display(const char *name,const SetArray s);
void clear(SetArray s);
int isEmpty(const SetArray s);
int contains(SetArray s, int elem);
int cardinality(const SetArray s);
SetArray getUnion(const SetArray s1,const SetArray s2);
SetArray getIntersection(const SetArray s1,const SetArray s2);
SetArray getDifference(const SetArray s1,const SetArray s2);
int isSubset(const SetArray s1,const SetArray s2);
int areDisjoint(const SetArray s1,const SetArray s2);

//implement remove such that, when you find the item to be removed
// replace it with the last element
void removeIt(SetArray s, int elem);



int main() {
    
    int test=0, n1,n2,elem;
    SetArray u_result=NULL, i_result=NULL, d_result=NULL;
    SetArray s1 = newSetArray();
    SetArray s2 = newSetArray();
    add(s1,50); add(s2,30);
    
    // for the first set
    scanf("%d",&n1);
    for (int i=0; i < n1; i++) {
        scanf("%d",&elem);
        add(s1,elem);
    }
    
    // for the second set
    scanf("%d",&n2);
    for (int i=0; i < n2; i++) {
        scanf("%d",&elem);
        add(s2,elem);
    }
    
    add(s1,50); add(s2,30);
    // will determine which code to run in the switch part
    scanf("%d",&test);
    display("s1",s1);
    display("s2",s2);
    add(s1,9); add(s1,20);
    removeIt(s1,50); removeIt(s1,30);
    removeIt(s2,30); removeIt(s2,0);
    
    display("s1",s1);
    display("s2",s2);
    
    switch (test) {
        // subset
        case 7: printf("isSubset(s1,s2)? %s\n",isSubset(s1,s2)?"yes":"no");
        
        // disjoint 
        case 6: printf("areDisjoint(s1,s2)? %s\n",areDisjoint(s1,s2)?"yes":"no");
        
        //difference
        case 5: d_result = getDifference(s1,s2);
                display("difference",d_result);
        
        //intersection
        case 4: i_result = getIntersection(s1,s2);
                display("intersection",i_result);       
        //union
        case 3: u_result = getUnion(s1,s2);
                display("union",u_result);
            
        //isEmpty, clear
        case 2: printf("isEmpty(s1)? %s\n",isEmpty(s1)?"yes":"no");
                printf("isEmpty(s2)? %s\n",isEmpty(s2)?"yes":"no");
                clear(s1); clear(s2);
                printf("isEmpty(s1)? %s\n",isEmpty(s1)?"yes":"no");
                printf("isEmpty(s2)? %s\n",isEmpty(s2)?"yes":"no");
                        
        //add, removeIt
        case 1: break;              
    }
    
    
    if (s1!=NULL) destroy(&s1);
    if (s2!=NULL) destroy(&s2);
    if (u_result!=NULL) destroy(&u_result);
    if (i_result) destroy(&i_result);
    if (d_result) destroy(&d_result);
    return 0;
}


SetArray newSetArray(){
	SetArray s = (SetArray) malloc(sizeof(struct set));
	s->items = (int *) malloc(sizeof(int)*10);
	s->count = 0;
	s->size = 10;
	return s;	
}

void destroy(SetArray *s){
	free((*s)->items);
	free(*s);
	*s = NULL;
}

void add(SetArray s, int elem){
	if ((s->count < s->size) && !contains(s,elem)) { 
		s->items[s->count++] = elem;
	}
}

void display(const char *name,const SetArray s){
	printf("%s = { ",name);
	for (int i=0; i <s->count; i++) {
		printf("%d ",s->items[i]);
	}
	printf("}\n");	
}

void clear(SetArray s)
{
	s->count = 0;
}	

int isEmpty(const SetArray s)
{
	int i;
	
	for(i = 0; i < s->count; i++)
	{
		if(s->items[i] != 0)
			return 0;
	}
	
	return 1;
}	

int contains(SetArray s, int elem)
{
	int i;
	
	for(i = 0; i < s->count; i++)
	{
		if(s->items[i] == elem)
			return 1;
	}
	
	return 0;
}

int cardinality(const SetArray s)
{
	int i, cardinality = 0;
	
	for(i = 0; i < s->count; i++)
	{
		if(s->items != NULL)
			cardinality++;
	}
	
	return cardinality;
}

SetArray getUnion(const SetArray s1,const SetArray s2)
{
	int i;
	SetArray res = newSetArray();
	
	for(i = 0; i < s1->count; i++)
		add(res, s1->items[i]);
		
	for(i = 0; i < s2->count; i++)
		add(res, s2->items[i]);
	
	return res;
}

SetArray getIntersection(const SetArray s1,const SetArray s2)
{
	int i, j;
	SetArray intersection = newSetArray();
	
	for(i = 0; i < s1->count; i++)
	{
		for(j = 0; j < s2->count; j++)
		{
			if(s1->items[i] == s2->items[j])
				add(intersection, s1->items[i]);
		}
	}
	
	return intersection;
}

SetArray getDifference(const SetArray s1,const SetArray s2)
{
	int i, j;
	SetArray difference = newSetArray();
	
	for(i = 0; i < s1->count; i++)
	{
		if(!contains(s2, s1->items[i]))
			add(difference, s1->items[i]);

	}
	
	return difference;
}

int isSubset(const SetArray s1,const SetArray s2)
{
	int i, j;
	
	for(i = 0; i < s1->count; i++)
	{
		if(!contains(s2, s1->items[i]))
			return 0;	
	}
	
	return 1;
}

int areDisjoint(const SetArray s1,const SetArray s2)
{
	int i, j;
	
	for(i = 0; i < s1->count; i++)
	{
		for(j = 0; j < s2->count; j++)
		{
			if(s1->items[i] == s2->items[i])
				return 0;	
		}
	}
	
	return 1;
}

void removeIt(SetArray s, int elem)
{
	int i;
	
	for(i = 0; i < s->count; i++)
	{
		if(s->items[i] == elem)
		{
			s->items[i] = s->items[s->count-1];
			s->count = s->count-1;
		}
	}
}
