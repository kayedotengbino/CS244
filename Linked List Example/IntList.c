#include <stdio.h>
#include <stdlib.h>

typedef struct node *nodeptr;
struct node {
    int item;
    nodeptr next;
};

typedef nodeptr IntList;

IntList newIntList(); // create header node
void destroy(IntList *list);
void clear(IntList list);
void addFront(IntList list,int x);
void addRear(IntList list,int x);
void removeFront(IntList list);
void removeRear(IntList list);
void display(const char *name,const IntList list);
void removeIt(IntList list,int x);

// implement these functions for practice
int contains(const IntList list,int x);
int frequency(const IntList list,int x);
int findSum(const IntList list);

void removeAll(IntList list,int x); // remove all occurences of x
void removeAllNegative(IntList list); 

// returns the item of the node at position pos
// example getItemAtPos(list,1) - will return the first item
// example getItemAtPos(list,5) - will return the fifth item
// assume that pos is a valid value
int getItemAt(IntList list,int pos);

// remove the node at position pos
// example removeItemAtPos(list,1) - will remove first node
// example removeItemAtPos(list,5) - will remove the fifth node
void removeItemAtPos(IntList list,int pos);


int main(){

    IntList list = newIntList();
    removeIt(list,100);
    addRear(list,100);
    display("list",list);
    removeIt(list,100);
    display("list",list);
    addFront(list,10);
    addFront(list,20);
    addFront(list,30);
    addFront(list,40);
    display("list",list);
    removeIt(list,20);
    display("list",list);
    removeIt(list,40);
    display("list",list);
    printf("Contains: %d\n", contains(list,8));
    addFront(list,8);
    addFront(list,8);
    addFront(list,40);
    display("list",list);
    printf("Frequency: %d\n", frequency(list,4));
    printf("Sum: %d\n", findSum(list));
    removeAll(list,8);
    display("list",list);
    addFront(list,-1);
    addFront(list,-2);
    addFront(list,-40);
    display("list",list);
    removeAllNegative(list);
    display("list",list);
    removeItemAtPos(list,1);
    display("list",list);
    printf("Item: %d\n", getItemAt(list,1));
    
    return 0;
}


// private
nodeptr createNode(int x) {
    nodeptr temp = (nodeptr) malloc(sizeof(struct node));
    temp->item = x;
    temp->next = NULL;
    return temp;
}

IntList newIntList() { // create header node
    return createNode(0); // header
}

void destroy(IntList *list)
{
    clear(*list); //becomes empty
    free(*list); // free header node
}

//Still needs to be fixed
void clear(IntList list)
{
	nodeptr temp;

    while(list != NULL)
    {
        temp = list;
        list = list->next;

        free(temp);
    }
}

void addFront(IntList list,int x){
    nodeptr temp = createNode(x);
    temp->next = list->next;
    list->next = temp;
}

void removeFront(IntList list) {
    nodeptr temp = list->next;
    if (temp != NULL) {
        list->next = temp->next;
        free(temp);
    }
}

void addRear(IntList list,int x) {
    nodeptr temp = createNode(x);
    nodeptr p = list;
    while (p->next != NULL) {
         p=p->next;
    }
    p->next = temp;
}

void removeRear(IntList list){
    nodeptr prev = list;
    nodeptr p = list->next;
    if (p!=NULL) { // not empty
        while (p->next!=NULL) {
               prev = p; // prev = prev->next
               p = p->next; 
        }
        free(p);
        prev->next = NULL;
    }
}


void display(const char *name,const IntList list){
    nodeptr p = list->next;
    printf("%s = [",name);
    while (p!=NULL) {
        printf("%d ",p->item);
        p=p->next;
    }
    printf("]\n");
}


// removes occurrence
void removeIt(IntList list,int x){
    nodeptr prev = list;
    nodeptr p = list->next;
    while (p!=NULL) {
        if (p->item == x) { // found it
            prev->next = p->next;
            free(p);
            break;
        }
        prev = p;
        p = p->next;
    }
}

int contains(const IntList list,int x)
{
	int flag = 0;
    nodeptr temp = list;

    // Iterate till last element until x is not found
    while (temp != NULL && temp->item != x)
    {
        flag = 1;
        temp = temp->next;
    }

    return (temp != NULL) ? flag : -1;
}

int frequency(const IntList list,int x)
{
	nodeptr temp = list;
	int cont = contains(list, x);	//check if x is in the items
	int freq = 0;
	
	if(cont != -1)
	{
		while(temp != NULL && temp->item != x)
		{
			freq++;
			temp = temp->next;
		}
	}
	
	return freq;
}

int findSum(const IntList list)
{
	nodeptr temp = list;
	int sum = 0;
	
	while(temp != NULL)
	{
		sum += temp->item;
		temp = temp->next;
	}
	
	return sum;
}

//helper function, private
int getCount(const IntList list) 
{ 
    // Base case 
    if (list == NULL) 
        return 0; 
  
    // count is 1 + count of remaining list 
    return 1 + getCount(list->next); 
} 

void removeAll(IntList list,int x)
{
	// Store head node
    nodeptr temp = list, prev;
 
    // If head node itself holds the key or multiple
    // occurrences of key
    while (temp != NULL && temp->item == x) 
    {
        list = temp->next; // Changed head
        free(temp); // free old head
        temp = list; // Change Temp
    }
 
    // Delete occurrences other than head
    while (temp != NULL) 
    {
        // Search for the key to be deleted, keep track of
        // the previous node as we need to change
        // 'prev->next'
        while (temp != NULL && temp->item != x) 
        {
            prev = temp;
            temp = temp->next;
        }
 
        // If key was not present in linked list
        if (temp == NULL)
            return;
 
        // Unlink the node from linked list
        prev->next = temp->next;
 
        free(temp); // Free memory
 
        // Update Temp for next iteration of outer loop
        temp = prev->next;
    }
}

//Still needs to be fixed
void removeAllNegative(IntList list)
{
    nodeptr temp = list, prev;
    int x = temp->item < 0;
 
    while (temp != NULL && temp->item < 0) 
    {
        list = temp->next; // Changed head
        free(temp); // free old head
        temp = list; // Change Temp
    }
 
    while (temp != NULL) 
    {
        while (temp != NULL && temp->item > x) 
        {
            prev = temp;
            temp = temp->next;
        }
 
        if (temp == NULL)
            return;
 
        prev->next = temp->next;
 
        free(temp); // Free memory
 
        temp = prev->next;
    }
}

void removeItemAtPos(IntList list,int pos)
{
	nodeptr temp = list;
	nodeptr ptr;
	nodeptr nextnode;
	int i;
	
	if(list == NULL)
		return;
	
	//Delete head
	if(pos == 0)
	{
		list = temp->next;
		free(temp);
		return;
	}
	
	//Store previous node	
	for(i = 1; temp != NULL && i < pos; i++)
		temp = temp->next;
		
	if(temp == NULL || temp->next == NULL)
		return;
		
	//Delete node at pos-1
	nextnode = temp->next->next;
	free(temp->next);
	temp->next = nextnode;
}

int getItemAt(IntList list,int pos)
{
	nodeptr current = list; 
  
    int count = 0; 
    while (current != NULL) 
	{ 
        if (count == pos) 
            return (current->item); 
            
        count++; 
        current = current->next; 
    } 
}
