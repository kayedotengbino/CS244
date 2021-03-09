#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"


int hash(HashTable hTable, int key)
{
	return key % hTable->size;
}

nodeptr createNode(int key)
{
    nodeptr temp;
    temp = (nodeptr)malloc(sizeof(struct node));
    temp->key = key;
    temp->next = NULL;

    return temp;
}

LinkedList newLinkedList()
{
    return createNode(0);
}

HashTable newHashTable(int size) 
{
    HashTable hTable = (HashTable) malloc(sizeof(struct hash));
    hTable->table = (LinkedList*) malloc(sizeof(LinkedList) * size);
    hTable->size = size;
    
    for(int i = 0; i < hTable->size; i++) 
         hTable->table[i] = newLinkedList();
        
    return hTable;
}

void clearLL(LinkedList list)
{
    nodeptr p = list->next;
    nodeptr temp;

    while(p != NULL ) {
        temp = p;
        p = p->next;
        free(temp);
    }
    list->next = NULL;
}

void clear(HashTable hTable) 
{
    for(int i = 0; i < hTable->size; i++) 
        clearLL(hTable->table[i]);
}

void destroyLL(LinkedList *list)
{
    clearLL(*list);
    free(*list);
    *list = NULL;
}

void destroy(HashTable *hTable) 
{
    clear(*hTable);
    free(*hTable);
    *hTable = NULL;
}

void addLL(LinkedList list,int key) // add at the front
{
    nodeptr temp = createNode(key);
	temp->next = list->next;
	list->next = temp;
}

void add(HashTable hTable,int key) 
{
    int index = hash(hTable, key);
    addLL(hTable->table[index], key);
}

int containsLL(LinkedList list,int key)
{
    nodeptr temp = list;

    while(temp->next != NULL)
    {
        temp = temp->next;

        if(key == temp->key)
            return 1; 
    }

    return 0;
}

int contains(HashTable hTable,int key) 
{
    int index = hash(hTable, key);

    return containsLL(hTable->table[index], key);
}

void removeLL(LinkedList list,int key)
{
    nodeptr prev = list;
    nodeptr p = list->next;

    while(p != NULL)
    {
        if(p->key == key)
        {
            prev->next = p->next;
            free(p);
            break;
        }
        prev = p;
        p = p->next;
    }
}

void removeH(HashTable hTable,int key) 
{
    int index = hash(hTable, key);
    removeLL(hTable->table[index], key);
}

void displayLL(LinkedList list)
{
    nodeptr p = list->next;
    printf("[ ");

    while(p != NULL) 
    {
        printf("%d ", p->key);
        p = p->next;
        
    }
    printf("]\n");
}

void display(HashTable hTable) 
{
    for(int index = 0; index < hTable->size; index++) 
    {
        printf("[%d] = ", index);
        displayLL(hTable->table[index]);
    }
}