#include <stdio.h>
#include <stdlib.h>
#include "StatArray.h"

int main() {
	
	int test=0, n1,n2,x;
	StatArray s1 = newStatArray();
	StatArray s2 = newStatArray();
	StatArray s3 = newStatArray();
	
	add(s1,20);
	add(s2,50);
	add(s1,2);
	add(s2,5);
	
	// for the first set
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
	add(s1,20);
	add(s2,50);
	add(s2,50);
	display("s1",s1);
	display("s2",s2);
	display("s3",s3);
	
	switch (test) {
		
		case 0: break;
		
		//findSUM
		case 1: printf("\n");
                printf("findSum(s1) = %d\n",findSum(s1));
				printf("findSum(s2) = %d\n",findSum(s2));
				printf("findSum(s3) = %d\n",findSum(s3));
				break;
				
		//findMean
		case 2: printf("\n");
                printf("findMean(s1) = %0.2f\n",findMean(s1));
				printf("findMean(s2) = %0.2f\n",findMean(s2));
				break;
		
		//findMin
		case 3: printf("\n");
                printf("findMin(s1) = %d\n",findMin(s1));
				printf("findMin(s2) = %d\n",findMin(s2));
				break;
				
		//findMax
		case 4: printf("\n");
                printf("findMax(s1) = %d\n",findMax(s1));
				printf("findMax(s2) = %d\n",findMax(s2));
				break;		
		
		//findRange
		case 5: printf("\n");
                printf("findRange(s1) = %d\n",findRange(s1));
				printf("findRange(s2) = %d\n",findRange(s2));
				break;		
		
		//findStandardDeviation
		case 6: printf("\n");
                printf("findStandardDeviation(s1) = %0.2f\n",findStandardDeviation(s1));
				printf("findStandardDeviation(s2) = %0.2f\n",findStandardDeviation(s2));
				break;
				
		case 7: printf("\n");
                printf("frequency(s1,20) = %d\n",frequency(s1,20));
				printf("frequency(s2,50) = %d\n",frequency(s2,50));
                printf("frequency(s3,50) = %d\n",frequency(s3,50));
				break;
		
		case 8:  printf("\n");
                 printf("contains(s1,2)? %s\n",contains(s1,2)?"yes":"no");
                 printf("contains(s2,5)? %s\n",contains(s2,5)?"yes":"no");
                 printf("contains(s1,200)? %s\n",contains(s1,200)?"yes":"no");
                 printf("contains(s2,500)? %s\n",contains(s2,500)?"yes":"no");
                 break;

        case 9: 
                removeFirst(s1,2);	removeFirst(s2,5);
				display("s1",s1);
				display("s2",s2);
				break;
		
		case 10: removeAll(s1,20);	removeAll(s2,50);
				display("s1",s1);
				display("s2",s2);
				break;
				
	    case 11:    printf("\n");
                    printf("isEmpty(s1)? %s\n",isEmpty(s1)?"yes":"no");
                    printf("isEmpty(s2)? %s\n",isEmpty(s2)?"yes":"no");
                    clear(s1); clear(s2);
                    display("s1",s1);
				    display("s2",s2);
                    printf("\n");
                    printf("isEmpty(s1)? %s\n",isEmpty(s1)?"yes":"no");
                    printf("isEmpty(s2)? %s\n",isEmpty(s2)?"yes":"no");              
    
    }
		
	if (s1!=NULL) destroy(&s1);
	if (s2!=NULL) destroy(&s2);
	if (s3!=NULL) destroy(&s3);
	return 0;
}
