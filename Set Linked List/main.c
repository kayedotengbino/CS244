#include <stdio.h>
#include <stdlib.h>
#include "SetLink.h"

void input1(SetLink s);
void input2(SetLink s);

int main() {
	int input;
	int test;
	SetLink s1 = newSetLink();
	SetLink s2 = newSetLink();
	SetLink s3 = newSetLink();
	SetLink result=NULL;
	input1(s1);
	input2(s2);
	scanf("%d",&test);
	switch (test) {
		case 1: display("s1",s1);
				printf("isEmpty(s1)? %s\n",isEmpty(s1)?"yes":"no");
    			display("s3",s3);
				printf("isEmpty(s3)? %s\n",isEmpty(s3)?"yes":"no");
				break;
				
		case 2: display("s1",s1);
				printf("cardinality(s1)? %d\n",cardinality(s1));
				display("s2",s2);
				printf("cardinality(s2)? %d\n",cardinality(s2));
				break;
		
		case 3: display("s1",s1);
				printf("contains(s1,15)? %s\n",contains(s1,15)?"yes":"no");
				printf("contains(s1,175)? %s\n",contains(s1,175)?"yes":"no");
				display("s2",s2);
				printf("contains(s2,15)? %s\n",contains(s2,15)?"yes":"no");
				printf("contains(s2,175)? %s\n",contains(s2,175)?"yes":"no");
				break;
				
		case 4: display("s1",s1);
				printf("remove 23\n");
				removeIt(s1,23);
				display("s1",s1);
				printf("remove 75\n");
				removeIt(s1,75);
				display("s1",s1);
				printf("remove 175\n");
				removeIt(s1,175);
				display("s1",s1);
				break;
				
		case 5: display("s1",s1);
				display("s2",s2);
				display("s3",s3);
				printf("isSubset(s3,s1)? %s\n",isSubset(s3,s1)?"yes":"no");
				printf("isSubset(s1,s2)? %s\n",isSubset(s1,s2)?"yes":"no");
				add(s3,15); add(s3,29);
				display("s3",s3);
				printf("isSubset(s3,s1)? %s\n",isSubset(s3,s1)?"yes":"no");
				printf("isSubset(s3,s2)? %s\n",isSubset(s3,s2)?"yes":"no");
				break;

		case 6: display("s1",s1);
				display("s2",s2);
				display("s3",s3);
				printf("areDisjoint(s3,s1)? %s\n",areDisjoint(s3,s1)?"yes":"no");
				printf("areDisjoint(s1,s2)? %s\n",areDisjoint(s1,s2)?"yes":"no");
				add(s3,55); add(s3,29);
				display("s3",s3);
				printf("areDisjoint(s3,s1)? %s\n",areDisjoint(s3,s1)?"yes":"no");
				printf("areDisjoint(s3,s2)? %s\n",areDisjoint(s3,s2)?"yes":"no");
				break;
				
		case 7: display("s1",s1);
				display("s2",s2);
				result = getUnion(s1,s2);
				display("s1 union s2",result);
				break;
				
		case 8:	display("s1",s1);
				display("s2",s1);
				result = getIntersection(s1,s2);
				display("s1 intersection s2",result);
				break;
				
		case 9: display("s1",s1);
				display("s2",s2);
				result = getDifference(s1,s2);
				display("s1 - s2",result);
				break;	
				
		case 10: 	display("s1",s1);
				 	display("s2",s2);
					printf("clearing s1 and s2\n");
					clear(s1); clear(s2);
					display("s1",s1);
				 	display("s2",s2);
				 	add(s1,20); add(s2,30);
				 	printf("adding 20 to s1 and 30 to s2\n");
					display("s1",s1);
				 	display("s2",s2);
				 	
					break;
					
	}
	
	destroy(&s1);
	destroy(&s2);
	if (result != NULL) 
		destroy(&result);
	return 0;
}

void input1(SetLink s){
	add(s,15);
	add(s,23);
	add(s,23);
	add(s,29);
	add(s,48);
	add(s,55);
	add(s,55);
	add(s,55);
	add(s,68);
	add(s,75);
}

void input2(SetLink s){
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