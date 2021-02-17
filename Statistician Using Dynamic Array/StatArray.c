#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "StatArray.h"

//implement the functions here, T(n) = n+5
StatArray newStatArray()
{
    StatArray stat = (StatArray)malloc(sizeof(struct stat));
    stat->items = (int *)malloc(sizeof(int)*10);
    stat->count = 0;
    stat->size = 10;

    return stat;
}

//T(n) = 3
void destroy(StatArray *s)
{
    free((*s)->items);
    free(*s);
    *s = NULL;
}

//T(n) = n+3
void add(StatArray s, int elem)
{
    if(s->count < s->size)
        s->items[s->count++] = elem;
}

//T(n) = 2n+4
void display(const char *name,const StatArray s)
{
    printf("\n%s = [", name);
    for(int i = 0; i < s->count; i++)
        printf(" %d", s->items[i]);

    printf(" ]");
}

//T(n) = constant
void clear(StatArray s)
{
    s->count = 0;
}

//T(n) = 2n+5
int isEmpty(const StatArray s)
{
    for(int i = 0; i < s->size; i++)
    {
        if(s->items[i] != 0)
            return 0;
    }

    return 1;
}

//T(n) = 2n+5
int contains(StatArray s, int elem)
{
    for(int i = 0; i < s->count; i++)
    {
        if(s->items[i] == elem)
            return 1;
    }

    return 0;
}

//number of occurence of elem, T(n) = 2n+7
int frequency(StatArray s, int elem)
{
    int frequency = 0;

    for(int i = 0; i < s->count; i++)
    {
        if(s->items[i] == elem)
            frequency++;
    }

    return frequency;
}

//T(n) = constant
int getCount(const StatArray s)
{
    return s->count;
}

//T(n) = 3n+9
int findMin(const StatArray s)
{
    int min = s->items[0];  //Default min value

    for(int i = 0; i < s->count; i++)
    {
        if(min > s->items[i])
            min = s->items[i];  //new min
    }

    return min;
}

//T(n) = 3n+9
int findMax(const StatArray s)
{
    int max = s->items[0];  //Default max value

    for(int i = 0; i < s->count; i++)
    {
        if(max < s->items[i])
            max = s->items[i];  //new max
    }

    return max;
}

//T(n) = 6n+18
int findRange(const StatArray s)
{
    return findMax(s) - findMin(s);
}

//T(n) = 2n+6
int findSum(const StatArray s)
{
    int sum = 0;

    for(int i = 0; i < s->count; i++)
        sum += s->items[i];

    return sum;
}

//T(n) = 2n+11
float findMean(const StatArray s)
{
    float sum = 0, ctr = 0, mean = 0;

    //Sum
    for(int i = 0; i < s->count; i++)
    {
        sum += s->items[i];
        ctr++;
    }
        
    mean = sum / ctr; //Getting the mean

    return mean;
}

//T(n) = 5n+19
float findStandardDeviation(const StatArray s)
{
    float sum = 0, average, stdDeviation = 0;

    //Average
    for(int i = 0; i < s->count; i++)
        sum += s->items[i];
        
    average = sum / s->count; 

    for(int i = 0; i < s->count; i++)
        stdDeviation += pow(s->items[i] - average, 2);
    
    return sqrt(stdDeviation /(s->count - 1));
}

/*
    implement remove such that, when you find the item to be removed
    replace it with the last xent
    T(n) = 3n+11
*/
void removeFirst(StatArray s, int x)
{
    for(int i = 0;  i < s->count; i++)
    {
        if(s->items[i] == x)
        {
            s->items[i] = s->items[s->count - 1];
            s->count = s->count - 1;
        }
    }
}

//remove all occurences, same strategy as removeFirst, T(n) = 3n+11
void removeAll(StatArray s, int x)
{
    for(int i = 0;  i < s->count; i++)
    {
        if(s->items[i] == x)
        {
            s->items[i] = s->items[s->count - 1];
            s->count = s->count - 1;
        }
    }
}
