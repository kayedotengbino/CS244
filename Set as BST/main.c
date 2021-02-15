#include <stdio.h>
#include <stdlib.h>
#include "Set.h"

int main(int argc, char *argv[])
{
	Set s = newSet();
	
	add(s, 50);
	add(s, 25);
	add(s, 75);
	add(s, 10);
	add(s, 35);
	add(s, 97);
	add(s, 66);
	add(s, 135);
	
	display("s", s);
	printf("\nCardinality of s = %d", cardinality(s));
	
	return 0;
}
