#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "StatArray.h"

//T(n) = n+5
StatArray newStatArray()
{
    StatArray s = (StatArray)malloc(sizeof(struct stat));
    s->items = (int *)malloc(sizeof(int)*10);
    s->count = 0;
    s->size = 10;

    return s;
}

//T(n) = 3
void destroy(StatArray *s)
{
    free((*s)->items);
    free(*s);
    *s = NULL;
}

/*
    will just add at the end
    this can be used assuming that add in sorted does not work
    T(n) = n+3
*/
void addLast(StatArray s, int elem)
{
    if(s->count < s->size)
        s->items[s->count++] = elem;
}

// will add in sorted order, T(n) 5n+14
void add(StatArray s, int elem)
{
    int i;
    
    for(i = (s->count++) - 1; i >= 0 && s->items[i] > elem; i--)
        s->items[i+1] = s->items[i];

    s->items[i + 1] = elem;
}

//T(n) = 2n+4
void display(const char *name,const StatArray s)
{
    printf("%s = [", name);
    for(int i = 0; i < s->count; i++)
        printf(" %d", s->items[i]);
    printf(" ]\n");
}

//T(n) = constant
int isEmpty(const StatArray s)
{
    return s->count == 0;
}

//T(n) = constant
void clear(StatArray s)
{
    s->count = 0;
}

//T(n) = constant
int findMin(const StatArray s)
{
    return s->items[0];
}

//T(n) = constant
int findMax(const StatArray s)
{
    return s->items[s->count-1];
}

//T(n) = 2n+4
int findRange(const StatArray s)
{
    return s->items[s->count-1] - s->items[0];
}

//T(n) = n+4
float findMedian(const StatArray s)
{
    if(s->count % 2 != 0)   //odd
        return s->items[(s->count / 2) + 1];
    else    //even
        return (float)(s->items[(s->count - 1) / 2] + (float)s->items[((s->count - 1) / 2) + 1]) / 2;
}

//T(n) = 3n+5
int findSum(const StatArray s)
{
    int sum = 0;

    for(int i = 0; i < s->count; i++)
        sum += s->items[i];

    return sum;
}

//T(n) = 3n^2+5n+1
float findMean(const StatArray s)
{
    return (float)findSum(s) / s->count;
}

//T(n) = 7n^2+5n+1
float findStandardDeviation(const StatArray s)
{
    float stdDeviation = 0;

    for(int i = 0; i < s->count; i++)
        stdDeviation += pow(s->items[i] - findMean(s), 2);

    return sqrt(stdDeviation / (s->count - 1));
}

// number of occurences of elem, T(n) = 3n+5
int frequency(StatArray s, int elem)
{
    int freq = 0;

    for(int i = 0; i < s->count; i++)
    {
        if(s->items[i] == elem) 
            freq++;
    }

    return freq;
}

//T(n) = 3n+5
int findPos(StatArray s, int elem)
{
    int pos = -1;

    for(int i = 0; i < s->count; i++)
    {
        if(s->items[i] == elem)
        {
            pos = i;
            break;
        }
    }

    return pos;
}

//T(n) = 3n+6
int contains(StatArray s, int elem)
{
    return findPos(s, elem) != -1;
}

//T(n) = 10
int binarySearch(StatArray s, int x, int first, int last)
{
    int mid;

    if(first <= last)
    {
        mid = (first + last) / 2;

        if(x == s->items[mid])
            return binarySearch(s, x, first, mid - 1);
        else 
            return binarySearch(s, x, mid+1, last);
    } 
        
    return 0;
}

/*
    there might be changes also in the implementation here
    implement remove such that, when you find the item to be removed
    replace it with the last xent
    T(n) = 3n^2+13n+5
*/
void removeFirst(StatArray s, int x)
{
    int pos = findPos(s, x);

    if(pos != -1)
    {
        for(int i = pos; i < s->count; i++)
            s->items[i] = s->items[i+1];

        s->count--;
    }
}

//remove all occurrences, same strategy as removeFirst, T(n) = 3n^2+16n+5
void removeAll(StatArray s, int x)
{
    for(int i = 0; i < s->count; i++)
        removeFirst(s, x);
}
