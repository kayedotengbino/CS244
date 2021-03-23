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

/*
    BFS
        Breadth-First Search
        one of the most common way to traverse a graph
        similar to level order of a tree but its main difference is that it
            may contain a cycle
        to not visit an already node - mark it as visited
        queue data for finding the shortest path
        used to find single source shortest path in an unweighted graph
        incore suitable for searching vertices which are closer to the given 
            source
        not suitable for decision making tree
            because it considers neighboors first
        ALGO:
            1: Start by putting any of the graph's vertices at the back 
                of the queue
            2: Take the front of the queue and add it to the visited list
            3: Create a list of vertex's adj nodes and add the ones that 
                are not yet visited at the back of the queue
            4: Repeat 2 and 3 until stack is empty
        TIME COMPLEXITY - O(V + E)
        Slower than DFS
        APPLICATION
            1: Shortest path and minimum spanning tree for unweighted
                graph
            2: Peer to peer network
            3: Crawlers in search engines
            4: GPS Navigation System
            5: To test if a graph is barpartite
            6: Ford-Fulkerson algorithm
                a greedy aooroach for calculating the maximum possible flow
                in a networ or a graph
            7: Path finding
            8: Finding all nodes within one connected components

    Clycle
        a node or vertex will be visited more than once

*/