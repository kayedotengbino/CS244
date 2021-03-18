void bfs(struct Graph* graph, int startVertex)
{
    struct queue* q = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    while(!isEmpty(q))
    {
        printQueue(q);
        
        int currentVertex = dequeue(q);

        printf("Visited %d\n", currentVertex);

        struct node* temp = graph->adjLists[currentVertex];

        while(temp)
        {
            int adjVertex = temp->vertex;

            if(graph->visited[adjVertex] == 0)
            {
                graph->visited[(adjVertex)] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}