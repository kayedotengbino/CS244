#include <stdio.h>
#include <stdlib.h>
#include "Stat.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Stat s = newStat();
	int test = 1;
	scanf("%d",&test);
	add(s,50);
	add(s,25);
	add(s,75);
	add(s,10);
	add(s,13);
	add(s,97);
	add(s,66);
	add(s,135);
	add(s,75);
	add(s,10);
	add(s,15);
	add(s,85);
	add(s,10);
	add(s,35);
	display("s",s);
	switch (test) {
		case 1: break;
		case 2: printf("count of s = %d\n",getCount(s));
				break;
		case 3: printf("frequency(s,35) = %d\n",frequency(s,10));
				printf("frequency(s,75) = %d\n",frequency(s,75));
				printf("frequency(s,5) = %d\n",frequency(s,5));
				break;
		case 4:	printf("contains(s,10) = %d\n",contains(s,10));
				printf("contains(s,35) = %d\n",contains(s,35));
				printf("contains(s,5) = %d\n",contains(s,5));
				break;
		case 5:	printf("findSum(s) = %d\n",findSum(s));
				break;				
		case 6:	printf("findMean(s) = %0.2f\n",findMean(s));
				break;				
		case 7:	printf("findMin(s) = %d\n",findMin(s));
				break;				
		case 8:	printf("findMax(s) = %d\n",findMax(s));
				break;				
		case 9:	printf("findRange(s) = %d\n",findRange(s));
				break;				
		case 10: printf("standardDeviation(s) = %0.2f\n",standardDeviation(s));
				 break;
		case 11: printf("isEmpty(s) = %d\n",isEmpty(s));
				printf("clearing s...\n");
				clear(s);
				printf("isEmpty(s) = %d\n",isEmpty(s));
				break;
		case 12: printf("findMedian(s) = %0.2f\n",findMedian(s));
				 add(s,45);
				 display("s",s);
				 printf("findMedian(s) = %0.2f\n",findMedian(s));
				 break;	
	}
	destroy(&s);
	return 0;
}
