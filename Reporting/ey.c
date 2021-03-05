define MAX = 5
define MAXNOFVERTICES = 5

Get all SCC - Strongly Connected Components
declare a counter = 1	//maintains the number of SCC

struct vertices_s
	adj[MAX]
	adjInverse[MAX]
	visited[MAX]
	visitedInverse[MAX]
	degree
vertices

number of vertices = size of vertices/size of vertices[0]

struct stack_s
	top
	items[MAXNOFVERTICES]
stack

//For pushing stack
	increment top
	if stack.top < MAXNOFVERTICES
		stack.item[stack.top] = x
	else return 0	//stack is fulle
	
//For popping stack
	if stack.top < 0	return -1
	else	decrement stack.top then item[top]
	
dfsFirst(u)
	if(visited[x])	return -1
	otherwise 
		visited[x] will be set to 1	
		
	while i < adj[x]'s size //i = 0
		recursive call //dfs(adj[x][i])
		++i
	
	if transpose < 0	stack.push(x)
	
dfsSecond(u)
    if(visitedInverse[x]) return -1; 
    otherwise
    	visitedInverse[x] will be set 1; 
  
    while i < adjInverse[x]'s size	//i = 0
        dfsSecond(adjInv[x][i]); 
  
    scc[x] = counter; 
    

addEdge(int a, int b)
	adj[a].stack_push(b)	//add edges to form the original graph

addEdgeInverse(int a, int b)
	addInv[b].stack_push(a)	//add edges to form the inverse graph

Check if SAT//if they are in the same scc--, here is where the implication graph is made
	while i < m	//Add edges to the graph, m is the number of clauses
		if all clauses are > 0	
			addEdge(a[i]+n, b[i]) t	//n is the number of variables	
			addEdgeInverse(a[i]+n, b[i]) 	
			addEdge(b[i]+n, a[i])
			addEdgeInverse(b[i]+n, a[i])
			
		else if a's classes are > 0 but b's clauses is < 0	
			addEdge(a[i]+n, n-b[i]) t	//n is the number of variables	
			addEdgeInverse(a[i]+n, n-b[i]) 	
			addEdge(-b[i]+n, a[i])
			addEdgeInverse(-b[i]+n, a[i])
		
		else if a's classes are < 0 but b's clauses is > 0	e
			addEdge(-a[i], b[i]) t	//n is the number of variables	
			addEdgeInverse(-a[i], b[i]) 	
			addEdge(b[i]+n, n-a[i])
			addEdgeInverse(b[i]+n, n-a[i])
			
		else 
			addEdge(-a[i], n-b[i]) t	//n is the number of variables	
			addEdgeInverse(-a[i], n-b[i]) 	
			addEdge(-b[i]+n, n-a[i])
			addEdgeInverse(-b[i]+n, n-a[i])
	i++	
	
	//Step 1 of Kosaraju's Algorithm which traverses the original graph
	while i <= 2*n
		if(!visited[i])
			dfsFirst(i)
			
	/*
		Step 2 of Kosaraju's Algorithm which traverses the inversed graph
		scc[] stores the corresponding value	
	*/
	while stack is not empty
		store stack.top to x
		pop the stack
		
		if !visitedInverse[x]
			dfsSecond(x)
			counter++
			
	if i <= n	//i = 0
		// for any 2 vairable x and -x lie in 
        // same SCC 
        if(scc[i]==scc[i+n]) 
        { 
            cout << "The given expression "
                 "is unsatisfiable." << endl; 
            return; 
        } 
    } 
  
    // no such variables x and -x exist which lie 
    // in same SCC 
    cout << "The given expression is satisfiable."
         << endl; 
