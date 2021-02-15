#include <stdio.h>
#include <stdlib.h>
#include "Set.h"

int main(int argc, char *argv[])
{
	Set s = newSet();
	
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
	
	Set s1 = newSet();
	
	add(s1,15);
	add(s1,23);
	add(s1,75);
	add(s1,23);
	add(s1,73);
	add(s1,3);
	add(s1,23);
	add(s1,15);
	add(s1,9);
	add(s1,15);
	add(s1,33);
	
	Set s3 = newSet();

	display("s", s);
	printf("\nCardinality of s = %d", cardinality(s));
	printf("\nContains [0] = %d", contains(s, 0));	
	printf("\nContains [50] = %d", contains(s, 50));
	printf("\nIs set empty? %s", isEmpty(s) ? "Yes" : "No");
	
	printf("\nisSubset(s3,s)? %s", isSubset(s3,s) ? "Yes" : "No");
	printf("\nisSubset(s,s1)? %s", isSubset(s,s1) ? "Yes" : "No");
	//add(s3,15); 
	//add(s3,29);
	printf("\nisSubset(s3,s)? %s", isSubset(s3,s) ? "Yes" : "No");
	printf("\nisSubset(s3,s1)? %s", isSubset(s3,s1) ? "Yes" : "No");
	
	printf("\nareDisjoint(s3,s)? %s",areDisjoint(s3,s)? "Yes" : "No");
	printf("\nareDisjoint(s,s1)? %s",areDisjoint(s,s1)? "Yes" : "No");
	//add(s3,55);
	//add(s3,29);
	printf("\nareDisjoint(s3,s)? %s",areDisjoint(s3,s)? "Yes" : "No");
	printf("\nareDisjoint(s3,s1)? %s",areDisjoint(s3,s1)? "Yes" : "No");
	
	Set result = newSet();
	
	result = getUnion(s,s1);
	display("\ns1 union s2",result);
	
	result = getIntersection(s,s1);
	display("s1 intersection s2",result);
	
	result = getDifference(s,s1);
	display("s1 - s2",result);
	
	clear(s);
	printf("\n\nClearning...\n\n");
	display("s", s);	
	
	printf("\nIs set empty? %s", isEmpty(s) ? "Yes" : "No");
	
	destroySet(&s);
	if(s != NULL)	
		printf("\nSet destroyed");
	else
		printf("\n\nSet not destroyed");
	
	return 0;
}
