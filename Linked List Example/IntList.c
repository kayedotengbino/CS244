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

/*
void destroy(IntList *list){
    clear(*list); //becomes empty
    free(*list); // free header node
}
*/

//void clear(IntList list);

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

