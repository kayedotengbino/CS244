#include <stdio.h>
#include <stdlib.h>

struct Graph{
 int v;
 int e;
 int **Adj;
};

struct Graph* adjMatrixOfGraph(){
 int r,c;
 int src, dest; // id of source and destination
 struct Graph* myGraph = (struct Graph*)malloc(sizeof(struct Graph));
 
 if(myGraph == NULL){
  printf("No memory allocated");
  return;
 }
 
 //definning number of vertices and edges
 printf("Enter number of vertices and edges\n");
 scanf("%d %d", &myGraph->v, &myGraph->e);
 
 //Making 2D array (MATRICE)
 myGraph->Adj = malloc(sizeof(int) * (myGraph->v));
 for(int i=0; i<myGraph->v; i++){
  myGraph->Adj[i] = malloc(sizeof(int) * (myGraph->v));
 }
 
 //Assign deffault values
 for(r=0; r<myGraph->v; r++){
  for(c=0; c<myGraph->v; c++){
   myGraph->Adj[r][c] = 0;
  }
 }
 
 printf("Enter node numbers in pair for an edge\n");
     
 for(int i=0; i<(myGraph->v)*2; i++){
  scanf("%d %d",&src, &dest);//we are using src and dest for vertice id's in matrice like 0,1,2,3 at top and left
  
  myGraph->Adj[src][dest] = 1;//beacuse it is undirected graph we give 1 to both
  myGraph->Adj[dest][src] = 1;

 }
 
 //Pirntinf Adj matrice
 for(r=0; r<myGraph->v; r++){
  for(c=0; c<myGraph->v; c++){
   printf("| %d ",myGraph->Adj[r][c]);
  }
  printf("|\n");
 }
 
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {

 adjMatrixOfGraph();
 
 return 0;
}