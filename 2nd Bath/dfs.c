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