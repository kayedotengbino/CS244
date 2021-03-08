#include <stdio.h>
#include <stdlib.h>
#include "SetLink.h"

nodeptr createNode(int item) {
	nodeptr temp;
	temp = (nodeptr) malloc(sizeof(struct node));
	temp->item =item;
	temp->next = NULL;
	return temp;
}

SetLink newSetLink(){
	return createNode(0);	
}

//O(n)
void display(const char *name,const SetLink s){
	nodeptr p = s->next;
	printf("%s = { ",name);
	while (p!=NULL) {
		printf("%d ",p->item);
		p=p->next;
	}
	printf("}\n");	
}

//O(n) because it needs to be distinct
void add(SetLink s,int elem)
{
    if(!contains(s, elem))
    {
        nodeptr temp = createNode(elem);
        nodeptr p = s;

        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

int isEmpty(const SetLink s)
{
    return s->next == NULL;
}

int contains(const SetLink s,int elem)
{
    nodeptr temp = s;

    while(temp->next != NULL)
    {
        temp = temp->next;

        if(elem == temp->item)
            return 1; 
    }

    return 0;
}

int cardinality(const SetLink s)
{
    nodeptr p = s;
    int ctr = 0;

    while(p->next != NULL)
    {
        ctr++;
        p = p->next;
    }

    return ctr;
}

void removeIt(SetLink s,int elem)
{
    nodeptr prev = s;
    nodeptr p = s->next;

    while(p != NULL)
    {
        if(p->item == elem)
        {
            prev->next = p->next;
            free(p);
            break;
        }
        prev = p;
        p = p->next;
    }
}

int isSubset(const SetLink s1,const SetLink s2)
{
    int res = 0;
    
    nodeptr p = s1->next;

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

            p = p->next;
        }
    }

    return res;
}

int areDisjoint(const SetLink s1,const SetLink s2)
{
    nodeptr p = s1->next;
    nodeptr q = s2->next;

    int res = 1;

    while(q != NULL)
    {
        if(contains(s1, q->item))
        {
            res = 0;
            break;
        }
        q = q->next;
    }

    return res;
}

//O(n)
SetLink getUnion(const SetLink s1,const SetLink s2)
{
    SetLink res = newSetLink();
    
    nodeptr p = s1->next;
    nodeptr q = s2->next;

    while(p != NULL)
    {
        add(res, p->item);
        p = p->next;
    }

    while(q != NULL)
    {
        if(!contains(res, q->item))
            add(res, q->item);
        
        q = q->next;
    }

    return res;
}

SetLink getIntersection(const SetLink s1,const SetLink s2)
{
    SetLink res = newSetLink();
    
    nodeptr p = s1->next;

    while(p != NULL)
    {
        if(contains(s2, p->item))
            add(res, p->item);
        
        p = p->next;
    }

    return res;
}

SetLink getDifference(const SetLink s1,const SetLink s2)
{
    SetLink res = newSetLink();
    
    nodeptr p = s1->next;

    while(p != NULL)
    {
        if(!contains(s2, p->item))
            add(res, p->item);
        
        p = p->next;
    }

    return res;
}

void clear(SetLink s)
{
    nodeptr p = s->next;

    while(p != NULL)
    {
        p->item = 0;
        p = p->next;
    }

    s->next = NULL;
}

void destroy(SetLink *s)
{
    clear(*s);
    free(*s);
}
