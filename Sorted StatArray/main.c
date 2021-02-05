#include <stdio.h>
#include <stdlib.h>
#include "StatArray.h"

void input1(StatArray s);
void input2(StatArray s);
void test1(StatArray s);
void test2(StatArray s);
void test3(StatArray s);
void test4(StatArray s);
void test5(StatArray s);
void test6(StatArray s);

int main() {
	int input;
	int test;
	StatArray s = newStatArray();
	scanf("%d",&input);
	scanf("%d",&test);
	if (input == 1)
		input1(s);
	else
		input2(s);
	switch (test) {
		case 1: test1(s);break;
		case 2: test2(s);break;
		case 3: test3(s);break;
		case 4: test4(s);break;
		case 5: test5(s);break;
		case 6: test6(s);break;
	}
	destroy(&s);
	return 0;
}

void input1(StatArray s){
	addLast(s,15);
	addLast(s,23);
	addLast(s,23);
	addLast(s,29);
	addLast(s,48);
	addLast(s,55);
	addLast(s,55);
	addLast(s,55);
	addLast(s,68);
	addLast(s,75);
}

void input2(StatArray s){
	add(s,15);
	add(s,23);
	add(s,75);
	add(s,23);
	add(s,73);
	add(s,3);
	add(s,23);
	add(s,15);
	add(s,9);
	add(s,15);
	add(s,33);
}


void test1(StatArray s){
	display("s",s);
	printf("isEmpty(s)? %s\n",isEmpty(s)?"yes":"no");
    printf("Clearing ...\n");
	clear(s);
	display("s",s);
	printf("isEmpty(s)? %s\n",isEmpty(s)?"yes":"no");
}

void test2(StatArray s){
	display("s",s);
	printf("findMin(s) = %d\n",findMin(s));
	printf("findMax(s) = %d\n",findMax(s));	
	printf("findRange(s) = %d\n",findRange(s));
	printf("findRange(s) = %0.2f\n",findMedian(s));
	
}

void test3(StatArray s){
	display("s",s);
	printf("findSum(s) = %d\n",findSum(s));
	printf("findMean(s) = %0.2f\n",findMean(s));
	printf("findStandardDeviation(s) = %0.2f\n",findStandardDeviation(s));	
}

void test4(StatArray s){
	display("s",s);
	printf("frequency(s,23) = %d\n",frequency(s,23));
	printf("frequency(s,55) = %d\n",frequency(s,55));
	printf("frequency(s,33) = %d\n",frequency(s,33));
	printf("contains(s1,15)? %s\n",contains(s,15)?"yes":"no");
	printf("contains(s1,75)? %s\n",contains(s,75)?"yes":"no");
	printf("contains(s1,78)? %s\n",contains(s,78)?"yes":"no");
	printf("contains(s1,115)? %s\n",contains(s,115)?"yes":"no");
}

void test5(StatArray s){
	display("s",s);
	printf("remove first 23\n");
	removeFirst(s,23);
	display("s",s);
	printf("remove first 75\n");
	removeFirst(s,75);
	display("s",s);
	printf("remove first 175\n");
	removeFirst(s,175);
	display("s",s);
}

void test6(StatArray s){
	display("s",s);
	printf("remove all 23\n");
	removeAll(s,23);
	display("s",s);
	printf("remove all 55\n");
	removeAll(s,55);
	display("s",s);	
	printf("remove all 75\n");
	removeAll(s,75);
	display("s",s);	
	printf("remove all 175\n");
	removeAll(s,175);
	display("s",s);	
}
