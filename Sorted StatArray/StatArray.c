#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "StatArray.h"

StatArray newStatArray()
{
    StatArray s = (StatArray)malloc(sizeof(struct stat));
    s->items = (int *)malloc(sizeof(int)*10);
    s->count = 0;
    s->size = 10;

    return s;
}

void destroy(StatArray *s)
{
    free((*s)->items);
    free(*s);
    *s = NULL;
}

/*
    will just add at the end
    this can be used assiming that add in sorted does not work
    STILL NEEDS TO BE FIXED
*/
void addLast(StatArray s, int elem)
{
    if(s->count < s->size) 
        s->items[s->count++] = elem;
}

void add(StatArray s, int elem)
{
    int position;

    //Determine pos
    for(int i = 0; i < s->count; i++)
    {
        if(elem < s->items[i])
        {
            position = i;
            break;
        }
    }

    //Move all data at the right side of the array
    for(int i = s->count; i >= position; i--)
        s->items[i] = s->items[i-1];
    
    s->items[position] = elem;  //insert value at the proper pos
}

void display(const char *name,const StatArray s)
{
    printf("%s = [", name);
    for(int i = 0; i < s->count; i++)
        printf(" %d", s->items[i]);

    printf(" ]\n");
}

void clear(StatArray s)
{
    s->count = 0;
}

int isEmpty(const StatArray s)
{
    return s->count == 0;
}

int getCount(const StatArray s)
{
    return s->count;
}

int findSum(const StatArray s)
{
    int sum = 0, i;

    for(i = 0; i < s->count; i++)
        sum += s->items[i];

    return sum;
}

float findMean(const StatArray s)
{
    return (float)findSum(s)/(float)s->count;
}

float findStandardDeviation(const StatArray s)
{
    float stdDeviation = 0, average = 0, sum = 0, mean = findMean(s), n = s->count-1;
    
    for(int i = 0; i < s->count; i++)
    {
        stdDeviation = pow(s->items[i] - mean, 2);
        sum += stdDeviation;
        stdDeviation = 0;
    }

    return sqrt(stdDeviation/(s->count-1));
}


int contains(StatArray s, int elem)
{
    for(int i = 0; i < s->count; i++)
    {
        if(s->items[i] == elem)
            return 1;
    }

    return 0;
}

int frequency(StatArray s, int elem) // number of occurrences of elem
{
    int freq = 0;

    for(int i = 0; i < s->count; i++)
    {
        if(s->items[i] == elem)
            freq++;
    }

    return freq;
}

int findMin(const StatArray s)
{
    return s->items[0];
}

int findMax(const StatArray s)
{
    return s->items[s->count-1];
}

int findRange(const StatArray s)
{
    return s->items[s->count-1] - s->items[0];
}

float findMedian(const StatArray s)
{
    int index, index1;

    if(s->count % 2 != 0)   //odd
        return s->items[s->count / 2];
    else    //Even
        return ((float)s->items[(s->count-1) / 2] + (float)s->items[((s->count-1) / 2)+1])/2;
}

//implement remove such that, when you find the item to be removed
// replace it with the last xent
void removeFirst(StatArray s, int x)
{
    for(int i = 0; i < s->count; i++)
    {
        if(s->items[i] == x)
        {
            s->items[i] = s->items[s->count - 1];
            s->count = s->count-1;
        }
    }
}

//remove all occurrences, same strategy as removeFirst
void removeAll(StatArray s, int x)
{
    for(int i = 0; i < s->count;)
    {
        if(s->items[i] == x)
        {
            s->items[i] = s->items[--s->count];
            continue;
        }
        else i++;
    }
}
