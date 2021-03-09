#ifndef HASH_H
#define HASH_H
#include <stdio.h>
#include <stdlib.h>

typedef struct node *nodeptr;
struct node {
	int key;
	nodeptr next;
};
typedef nodeptr LinkedList;

struct hash {
	LinkedList *table; // array of nodeptrs
	int size;
};

typedef struct hash *HashTable;

LinkedList newLinkedList(); 
void destroyLL(LinkedList *list);
void addLL(LinkedList list,int key); // add at the front
int containsLL(LinkedList list,int key);
void removeLL(LinkedList list,int key);
void clearLL(LinkedList list);
void displayLL(LinkedList list);

HashTable newHashTable(int size);
void destroy(HashTable *hTable);
void add(HashTable hTable,int key);
void removeH(HashTable hTable,int key);
int contains(HashTable hTable,int key);
void clear(HashTable hTable);
void display(HashTable hTable);
int hash(HashTable hTable, int key);

#endif