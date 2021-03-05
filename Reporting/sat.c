#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

int main(int argc, char *argv[]){
	if (argc != 3){
		printf("Usage: %s <input> <solution>\n", argv[0]);
		exit(1);
	}

	FILE *in = fopen(argv[1], "r"),
	     *soln = fopen(argv[2], "r");
	
	int size, nclauses;
	fscanf(in, "%d %d", &size, &nclauses);
	
	bool vals[size];
	memset(vals, false, sizeof(vals));
int i;
	for (i = 0; i < size; ++i){
		int val = fgetc(soln);
		if (val == 'T') vals[i] = true;
		else if (val == 'F') vals[i] = false;
		else printf("invalid value [%c]\n", val);
		fgetc(soln);
	}

	for (i = 0; i < nclauses; ++i){
		int m, n;
		fscanf(in, "%d %d", &m, &n);
		bool mv = vals[abs(m)-1], nv = vals[abs(n)-1];
		if (m < 0) mv = !mv;
		if (n < 0) nv = !nv;
		printf("checking %d(%d) || %d(%d)\n", m, mv, n, nv);
		assert(mv || nv);
	}

	printf("all good\n");
}
