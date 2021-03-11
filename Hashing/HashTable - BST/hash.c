#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"


int hash(HashTable hTable, int key){
	return key % hTable->size;
}

treeptr createNode(int key)
{
    treeptr temp;

    temp = (treeptr)malloc(sizeof(struct node));
    temp->key = key;
    temp->left = temp->right = NULL;

    return temp;
}

HashTable newHashTable(int size)
{
    HashTable hashTable = (HashTable)malloc(sizeof(struct hash));
    hashTable->table = (treeptr*) malloc(sizeof(struct node) * size);
    hashTable->size = size;
    
    return hashTable;
}

void destroyLL(treeptr *t)
{
    clearLL(*t);
    free(*t);
    *t = NULL;
}

void destroy(HashTable *hTable)
{
	for(int i = 0; i < (*hTable)->size; i++)
		destroyLL(&(*hTable)->table[i]);

	free(*hTable);
	*hTable = NULL;
}

void addLL(treeptr t,int key)
{
    treeptr temp = createNode(key);
    treeptr p = t;
    treeptr prev;

    while(p != NULL)
    {
        prev = p;

        if(key < p->key) 
            p = p->left;
        else 
            p = p->right;
    }

    if(key < prev->key)
    {
        prev->left = temp;
        temp->parent = prev;
    }
    else
    {
        prev->right = temp;
        temp->parent = prev;
    }
}

void add(HashTable hTable,int key)
{
    int index = hash(hTable, key);
    
    if(hTable->table[index] == NULL)
        hTable->table[index] = createNode(key);
    else
        addLL(hTable->table[index], key);
}

int containsLL(treeptr t,int key)
{
    if(t == NULL)
        return 0;
    else if(t->key == key)
        return 1;
    else if(t->key > key)
        return containsLL(t->left, key);

    return containsLL(t->right, key);
}

int contains(HashTable hTable,int key)
{
    int index = hash(hTable, key);
    
    return containsLL(hTable->table[index], key);
}

/*
int removeLL(treeptr t,int key)
{
    if(t != NULL)
    {
        if(key < t->key)
        {
            t->left = removeLL(t->left, key);
            
            return t;
        }
        else if(key > t->key)
        {
            t->right = removeLL(t->right, key);

            return t;
        }
        else    //reached the node
        {
            if(t->left == NULL && t->right == NULL)
            {
                size--;

                return t->left;
            }
            else if(t->left != NULL && t->right == NULL)
            {
                size--;

                return t->left;
            }
            else if(t->left == NULL && t-?right != NULL)
            {
                size--;

                return t->right;
            }
            else
            {
                treeptr temp = t->left; //before the left

                while(temp->right != NULL)
                    temp = temp->right
            }

            t->key = temp->key;
            t->parent = t->parent;
            t->left = removeLL(t->left, t->key);

            return key;
        }
    }
}

void removeH(HashTable hTable,int key)
{
    int index = hashcode(key);
    treeptr tree = (treeptr)hTable[index]->parent;

    if (tree != NULL)
    {
        tree ptr temp = containsLL(tree, key);
        if (temp == NULL) 
            break;
        else 
            tree = removeLL(tree, key);
    }
}
*/

void clearLL(treeptr t)
{
    if(t != NULL)
    {
        clearLL(t->left);
        clearLL(t->right);
        free(t);
        t = NULL;
    }
}

void clear(HashTable hTable)
{
    for(int i = 0; i < hTable->size; i++)
    {
        clearLL(hTable->table[i]);
        hTable->table[i] = NULL;
    }     
}

void displayLL(treeptr t)
{
    if(t != NULL)
    {
        displayLL(t->left);
        printf("%d ", t->key);
        displayLL(t->right);
    } 
}

void display(HashTable hTable)
{
    for(int index = 0; index < hTable->size; index++)
    {
        printf("[%d] = ", index);
        printf("[ ");
        displayLL(hTable->table[index]);
        printf("]");
        printf("\n");
    }
}