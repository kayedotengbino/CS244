#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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


// private
int findPos(StatArray s, int x);

int main() {
	
	int test=0, n1,n2,x;
	StatArray s1 = newStatArray();
	StatArray s2 = newStatArray();
	StatArray s3 = newStatArray();
	
	
	add(s1,20);
	add(s2,50);
	add(s1,2);
	add(s2,5);
	
	/* for the first set
	scanf("%d",&n1);
	for (int i=0; i < n1; i++) {
		scanf("%d",&x);
		add(s1,x);
	}
	
	// for the second set
	scanf("%d",&n2);
	for (int i=0; i < n2; i++) {
		scanf("%d",&x);
		add(s2,x);
	}
	scanf("%d",&test);
	*/
	
	add(s1,20);
	add(s2,50);
	add(s2,50);
	display("s1",s1);
	display("s2",s2);
	display("s3",s3);
	
	/*
	switch (test) {
		
		case 0: break;
		
		//findSUM
		case 1: printf("findSum(s1) = %d\n",findSum(s1));
				printf("findSum(s2) = %d\n",findSum(s2));
				printf("findSum(s3) = %d\n",findSum(s3));
				break;
				
		//findMean
		case 2: printf("findMean(s1) = %0.2f\n",findMean(s1));
				printf("findMean(s2) = %0.2f\n",findMean(s2));
				break;
		
		//findMin
		case 3: printf("findMin(s1) = %d\n",findMin(s1));
				printf("findMin(s2) = %d\n",findMin(s2));
				
				break;
				
		//findMax
		case 4: printf("findMax(s1) = %d\n",findMax(s1));
				printf("findMax(s2) = %d\n",findMax(s2));
				break;		
		
		//findMax
		case 5: printf("findRange(s1) = %d\n",findRange(s1));
				printf("findRange(s2) = %d\n",findRange(s2));
				break;		
		
		//findStandardDeviation
		case 6: printf("findStandardDeviation(s1) = %0.2f\n",findStandardDeviation(s1));
				printf("findStandardDeviation(s2) = %0.2f\n",findStandardDeviation(s2));
				break;
				
		case 7: printf("frequency(s1,20) = %d\n",frequency(s1,20));
				printf("frequency(s2,50) = %d\n",frequency(s2,50));
                printf("frequency(s3,50) = %d\n",frequency(s3,50));
                
				break;
		
		case 8:  printf("contains(s1,2)? %s\n",contains(s1,2)?"yes":"no");
                 printf("contains(s2,5)? %s\n",contains(s2,5)?"yes":"no");
                 printf("contains(s1,200)? %s\n",contains(s1,200)?"yes":"no");
                 printf("contains(s2,500)? %s\n",contains(s2,500)?"yes":"no");
		
        case 9: removeFirst(s1,2);	removeFirst(s2,5);
				display("s1",s1);
				display("s2",s2);
				break;
		
		case 10: removeAll(s1,20);	removeAll(s2,50);
				display("s1",s1);
				display("s2",s2);
				break;
				
	    case 11:    printf("isEmpty(s1)? %s\n",isEmpty(s1)?"yes":"no");
                    printf("isEmpty(s2)? %s\n",isEmpty(s2)?"yes":"no");
                    clear(s1); clear(s2);
                    display("s1",s1);
				    display("s2",s2);
                    printf("isEmpty(s1)? %s\n",isEmpty(s1)?"yes":"no");
                    printf("isEmpty(s2)? %s\n",isEmpty(s2)?"yes":"no");              
    
    }
	
	
	if (s1!=NULL) destroy(&s1);
	if (s2!=NULL) destroy(&s2);
	if (s3!=NULL) destroy(&s3);
*/
	return 0;
}


int findPos(StatArray s, int x) {
	int pos = -1;
	for (int i=0; i < s->count; i++) {
		if (s->items[i] == x) {
			pos = i; break;
		}			
	}
	return pos;
}

// using malloc
// I have read that there might be some issues to realloc
// maybe this was before
int doubleTheSize1(StatArray s){
	int *temp;
	int success = 0;
	int count = 2;
	temp = (int *) malloc(sizeof(int)*s->size*count);
	if (temp != NULL) {
		s->size *= count;
		for (int i=0; i < s->count; i++)	
			temp[i] = s->items[i];
		free(s->items);
		s->items = temp;
		success = 1;
	}
	return success;
}

// using realloc
int doubleTheSize2(StatArray s){
	int *temp;
	int success = 0;
	int count = 2;
	temp = (int *) realloc(s->items,sizeof(int)*s->size*count);
	if (temp != NULL) {
		s->items = temp;
		s->size *= count;
		success = 1;
	}
	return success;
}

StatArray newStatArray(){
	StatArray s = (StatArray) malloc(sizeof(struct stat));
	s->size = 2;
	s->items = (int *) malloc(sizeof(int)*s->size);
	s->count = 0;
	return s;	
}

void destroy(StatArray *s){
	free((*s)->items);
	free(*s);
	*s = NULL;
}

void add(StatArray s, int x){
	if ((s->count < s->size) || doubleTheSize1(s))  { 
		s->items[s->count++] = x;
	}	
}

void display(const char *name,const StatArray s){
	printf("size = %d\n",s->size);
	printf("%s = [ ",name);
	for (int i=0; i <s->count; i++) {
		printf("%d ",s->items[i]);
	}
	printf("]\n");	
}

void removeFirst(StatArray s, int x){
	int pos = findPos(s,x);
	if (pos != -1) {
		s->items[pos] = s->items[--s->count];
	}			
}

void removeAll(StatArray s, int x){
	for (int i=0; i < s->count; ) {
		if (s->items[i] == x) {
			s->items[i] = s->items[--s->count];
			continue;
		}
		else i++;
	}				
}


int contains(StatArray s, int x){
	return findPos(s,x) != -1;
}

int getCount(const StatArray s) {
	return s->count;
}

void clear(StatArray s){
	s->count = 0;
}

int isEmpty(const StatArray s){
	return s->count==0;
}

int findMin(const StatArray s){
	int min = s->items[0];
	for (int i=1; i < s->count; i++) {
		if (s->items[i] < min)
			min = s->items[i];
	}	
	return min;
}

int findMax(const StatArray s) {
	int max = s->items[0];
	for (int i=1; i < s->count; i++) {
		if (s->items[i] > max)
			max = s->items[i];
	}	
	return max;
}

int findRange(const StatArray s) {
	return findMax(s) - findMin(s);
}

int findSum(const StatArray s) {
	int sum = 0;
	for (int i=0; i < s->count; i++) {
		sum += s->items[i];
	}	
	return sum;
}


float findMean(const StatArray s){
	return (float)findSum(s)/ (float)s->count;	
}

float findStandardDeviation(const StatArray s){
	float mean = findMean(s);
    float temp;
	float sum = 0;
	for (int i=0; i < s->count; i++) {
        temp = (s->items[i] - mean);
		sum += temp * temp;
	}
	return (float)sqrt(sum/(s->count-1));
}

int frequency(StatArray s, int x){
	int count = 0;
	for (int i=0; i < s->count; i++) {
		if (s->items[i]==x)
			count++;
	}
	return count;
}

