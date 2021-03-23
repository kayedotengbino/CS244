void dfs(struct Graph *graph, int vertex)
{
    struct node* adjList = graph->adjList[vertex];
    struct npde* temp = adjList;

    graph->visited[vertex] = 1;
    printf("Visited %d", vertex);

    while(temp != NULL)
    {
        int connectedVertex = temp->vertex;

        if(graph->visited[connectedVertex] == 0)
            dfs(graph, connectedVertex);

        temp = temp->next;
    }
}

/*
    DFS 
        Depth-First Search
        starts at the root then explore as far as possible along each 
            branch before backtracking (if it is a tree)
        ALGO:
            1: Start by putting any one of the graph's vertices to the top
                of the stack
            2: Take the top of the stack and add it to the visited list
            3: Create a list of the vertex's adj nodes and add the ones 
                that are not yet visited at the top of the stack
            4: Repeat 2 and 3 until stack is empty
        TIME COMPLEXITY - O(V + E)
*/