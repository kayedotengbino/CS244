#ifndef HASH_H
#define HASH_H
#include <stdio.h>
#include <stdlib.h>

typedef struct node *treeptr;
struct node {
	int key;
	treeptr left;
	treeptr right;
	treeptr parent;
};

struct hash {
	treeptr *table; // array of treeptr, just set to all NULL
	int size;
};

typedef struct hash *HashTable;

treeptr createNode(int key); 
void destroyLL(treeptr *t);
void addLL(treeptr t,int key); // add at the front
int containsLL(treeptr t,int key);
//void removeLL(treeptr t,int key);// you can change the function prototype
void clearLL(treeptr t);
void displayLL(treeptr t);

HashTable newHashTable(int size);
void destroy(HashTable *hTable);
void add(HashTable hTable,int key);
//void removeH(HashTable hTable,int key);
int contains(HashTable hTable,int key);
void clear(HashTable hTable);
void display(HashTable hTable);
int hash(HashTable hTable, int key);

#endif