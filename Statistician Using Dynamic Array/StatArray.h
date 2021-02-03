#include <stdio.h>
#include <stdlib.h>


struct stat {
	int *items; // pointer to an array, elements
	int count;
	int size; // array size
};

typedef struct stat *StatArray;

StatArray newStatArray();
void destroy(StatArray *s);
void add(StatArray s, int elem);
void display(const char *name,const StatArray s);
void clear(StatArray s);
int isEmpty(const StatArray s);
int contains(StatArray s, int elem);
int frequency(StatArray s, int elem); // number of occurrences of elem
int getCount(const StatArray s);
int findMin(const StatArray s);
int findMax(const StatArray s);
int findRange(const StatArray s);
int findSum(const StatArray s);
float findMean(const StatArray s);
float findStandardDeviation(const StatArray s);

//implement remove such that, when you find the item to be removed
// replace it with the last xent
void removeFirst(StatArray s, int x);

//remove all occurrences, same strategy as removeFirst
void removeAll(StatArray s, int x);
