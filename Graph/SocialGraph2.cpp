#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

struct graph{
	int graph[SIZE][SIZE];
	int size;
};

typedef struct graph* Graph;

Graph NewGraph();	
void makeFriends(Graph g, int i,int j);//–make i and j friends
int countFriends(Graph g, int i);//–will return the number of friends of i, excluding itself
int countEnemies(Graph g, int i);//–will return the number of enemies of i 
int countCommonFriends(Graph g, int i,int j);//-the number of common friends of i and j 
int countCommonEnemies(Graph g,int i,int j);//-the number of common enemies of i and j 
int findBestFriends(Graph g,int i);//will return a possible best friend of i. The possible best friend is the friend with the most number of common friendswith i.There may be more than one possible best friend, return only 1. If there is none, return i
int friendliest(Graph g);//–will return the node with the most number of friends 
int loner(Graph g);//–will return the node with the least number of friends
int recluse(Graph g,int i);// –will return true if i has no friends.
int famous(Graph g,int i);// –will return true if node i is a friend of everybody in the group
void display(Graph g);
int main(){
	Graph g = NewGraph();
	
	display(g);
	makeFriends(g,4,1);
	makeFriends(g,4,2);
	makeFriends(g,3,4);
	makeFriends(g,8,3);
	makeFriends(g,7,4);
	makeFriends(g,6,4);
	makeFriends(g,9,4);
	makeFriends(g,2,6);
	printf("\n\n");
	display(g);
	
	int friends = countFriends(g,4);
	printf("\nNumber of friends of (4) = %d\n", friends);
	
	int enem = countEnemies(g,5);
	printf("Number of Enemies of (5) = %d\n", enem);
	
	int f = countCommonFriends(g,4,2);
	printf("count COMMONFRIENDS OF [4][2]: %d\n", f);
	
	int e = countCommonEnemies(g,5,1);
	printf("count COMMONENEMIES OF [5][1]: %d\n", e);
	
	int bf = findBestFriends(g,4);
	printf("BESTFRIEND OF 4: %d\n", bf);
	
	
	int fr = friendliest(g);
	printf("FriendLiest: %d\n", fr);
	
	int lr = loner(g);
	printf("Loneliest: %d\n", lr);
	
	int fam = famous(g,4);
	printf("is (4) famous: %d\n", fam);
	int no = recluse(g,5);
	printf("is (5) recluse: %d", no);
}

void display(Graph g){
    int i,j;
    printf("  ");
    for(i = 0; i < SIZE;i++){
        printf("%d ",i);
    }
    printf("\n");

    for(i = 0; i < SIZE;i++){
            printf("%d ",i);

        for(j = 0; j <SIZE;j++){
            printf("%d ",g->graph[i][j]);
        }
        printf("\n");
    }
}


Graph NewGraph(){
    Graph g = (Graph) malloc(sizeof(struct graph));
    g->size = SIZE; 
    for (int i = 0; i < g->size; i++) {
        for (int j = 0; j < g->size; j++) {
            if (j == i)
                g->graph [i][i] = 1;
            else
                g->graph[i][j] = 0;

        }
    }
    return g;
}

	
void makeFriends(Graph g, int i, int j){
	g->graph[i][j] = 1;
	g->graph[j][i] = 1;
}

int countFriends(Graph g, int i){
	int friends = 0;
	int j;
	for(j = 0; j < g->size; j++){
		if(g->graph[i][j] == 1)
			friends++;
	}
	return friends-1;
}

int countEnemies(Graph g, int i) {
    int Enemies = 0;
    for (int j = 0 ; j < g->size; j++) {
        if (g->graph[i][j] == 0)
            Enemies++;
    }
    return Enemies;
}

int countCommonFriends(Graph g, int i,int j){
    int k;
	int count=0;
    for(k = 0;k < g->size; k++){
        if(g->graph[i][k] == 1 && g->graph[j][k] == 1)
        count++; 
    }
    return count;
}


int countCommonEnemies(Graph g, int i, int j) {
	int k;
	int count=0;
    for(k = 0;k < g->size; k++){
        if(g->graph[i][k] == 1 && g->graph[j][k] == 1)
        count++; 
    }
    return count;
}

int findBestFriends(Graph g,int i){
    int finder = i, temp, temp2 = 0;
    for(int j = 0; j < SIZE; j++){
        temp = 0;
        if(j != i)
            temp = countCommonFriends(g, i, j);
        if(temp > temp2){
            temp2 = temp;
            finder = j;
        }
    }
    return finder;
}

int friendliest(Graph g){
	int count = countFriends(g,0);
    int friendliest = 0;
    int i;
    for (i = 1; i < g->size; i++) {
        if (count < countFriends(g,i)) {
            friendliest = i;
            count = countFriends(g,i);
        }
    }
    return friendliest;
}

int loner(Graph g){
    int count = countFriends(g,0);
    int loner = 0;
    int i;
    int temp;
    for (i = 1; i < g->size; i++) {
        	if(temp < count)
            count = temp;
            loner = countFriends(g,i);
    }
    return loner;
}

int recluse(Graph g,int i) {
    int friends = 0;
    if(countFriends(g,i) == 0)
        friends = 1;
    return friends;
}
	
int famous(Graph g,int i) {
    int friends = 0;
    if (countFriends(g,i) == g->size)
        friends = 1;
    return friends;
}

