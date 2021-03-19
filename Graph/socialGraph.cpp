#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct graph
{
	int graph[MAX][MAX];
	int size;
};

typedef struct graph* Graph;

Graph newGraph() 
{
	Graph g = (Graph) malloc (sizeof(struct graph));
	g->size = MAX; 
	
	for (int i = 0; i < g->size; i++) 
	{
		for (int j = 0; j < g->size; j++) 
		{
			if (j == i)
				g->graph [i][i] = 1;
			else
				g->graph[i][j] = 0;
		}
	}
	
	return g;
}

void display(Graph g) 
{
	printf ("Graph g = [\n");
	for (int i = 0; i < g->size; i++ ) 
	{
		for (int j = 0; j < g->size; j++) 
			printf("  %d",g->graph[i][j]);
			
		printf("\n");
	}
	printf(" ]\n");
}

void makeFriends(Graph g, int i,int j) 
{
	g->graph[i][j] = 1;
}

int countFriends(Graph g, int i) 
{
	int numOfFriends = 0;
	
	for (int j = 0 ; j < g->size; j++) 
	{
		if (g->graph[i][j] == 1)
			numOfFriends++;
	}
	
	return numOfFriends;
}

int countEnemies(Graph g, int i) 
{
	int numOfEnemies = 0;
	
	for (int j = 0 ; j < g->size; j++) 
	{
		if (g->graph[i][j] == 0)
			numOfEnemies++;
	}
	
	return numOfEnemies;
}

int commonFriends(Graph g, int i, int j) 
{
	int commonFriends = 0;

	for(int k = 0; k < g->size; k++) 
	{
		if (g->graph[i][k] == 1)
			commonFriends++;
	}
	
	for(int k = 0; k < g->size; k++) 
	{
		if (g->graph[j][k] == 1)
			commonFriends++;
	}
	
	return commonFriends;
}

int commonEnemies(Graph g, int i, int j) {
	
	int commonEnemies = 0;
	
	for(int k = 0; k < g->size; k++) 
	{
		
		if (g->graph[i][k] == 1)
			commonEnemies++;
	}
	
	for(int k = 0; k < g->size; k++) 
	{
		if (g->graph[j][k] == 1)
			commonEnemies++;
	}
	
	return commonEnemies;
}

int findBestFriends(Graph g,int i)
{
    int x = i, temp, temp2 = 0;
    
    for(int j = 0; j < g->size; j++)
	{
        temp = 0;
        
        if(j != i)
            temp = commonFriends(g, i, j);
        if(temp > temp2)
		{
            temp2 = temp;
            x = j;
        }
    }
    
    return x;
}

int main()
{
	Graph g = newGraph();
	
	display(g);
	makeFriends(g,2,1);
	makeFriends(g,1,2);
	makeFriends(g,1,3);
	makeFriends(g,8,5);
	makeFriends(g,6,5);
	makeFriends(g,6,8);
	makeFriends(g,7,3);
	makeFriends(g,10,1);
	makeFriends(g,6,0);
	makeFriends(g,0,10);	
	display(g);
	
	int choice, test, test1;
	
	while(choice != 9)
	{
		printf("\n\nSOCIALGRAPH\n\n[1] Count Friends\n[2] Count Enemies\n");
		printf("[3] Count Common Friends\n[4] Count Common Enemies\n");
		printf("[5] Find Best Friends\n[6] Find Friendliest\n");
		printf("[6] Find Loner\n[7] Find Recluse\n");
		printf("[8] Find Famous\n[9] Exit\n\nChoice:");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1: 
				printf("Number to check: ");
				scanf("%d", &test);
				printf("Number of friends: %d", countFriends(g, test) );
				break;
			case 2:
				printf("Number to check: ");
				scanf("%d", &test);
				printf("Number of enemies: %d", countEnemies(g, test) );
				break;
			case 3:
				printf("Number to check: ");
				scanf("%d", &test);
				printf("Number to check: ");
				scanf("%d", &test1);
				printf("Number of common friends: %d", commonFriends(g, test, test1) );
				break;
			case 4:
				printf("Number to check: ");
				scanf("%d", &test);
				printf("Number to check: ");
				scanf("%d", &test1);
				printf("Number of common enemies: %d", commonEnemies(g, test, test1) );
				break;
			case 5:
				printf("Number to check: ");
				scanf("%d", &test);
				printf("Best Friend: %d", findBestFriends(g, test) );
				break;
			default:
				printf("Invalid input");
		}
	}
	
}
