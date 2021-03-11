//for Step 1 of Kosaraju's Algorithm
func dfsFirst(vertex u):	
    visited[u] = true
    for each vertex u adjacent to i do:
        if not marked[i]:
            dfsFirst(i)
    stack.push(u)

//for Step 2 of Kosaraju's Algorithm
func dfsSecond(vertex u):
    markedInv[u] = true
    for each vertex u adjacent to i do:
        if not marked[i]:
            dfsSecond(i)
    component[i] = counter

for i = 1 to n do:
    addEdge(not x[i], y[i])
    addEdge(not y[i], x[i])
   
/*
	+ clauses are mapped to x
	- classes are mapped to (number of variables + x)
*/
for i = 1 to m do:
	if x[i] and y[i] > 0
		addEdge(x[i] + number of variables, y[i])
    	addEdgeInv(x[i] + number of variables, x[i])
    	addEdge(y[i] + number of variables, x[i])
    	addEdgeInv(y[i] + number of variables, x[i])
    else if x[i] > 0 but y[i] < 0
    	addEdge(x[i] + number of variables, number of variables - y[i])
    	addEdgeInv(x[i] + number of variables, number of variables - y[i])
    	addEdge(not y[i], x[i])
    	addEdgeInv(not y[i], x[i])
    else if x[i] < 0 but y[i] > 0
    	addEdges(not x[i], y[i])
    	addEdgesInv(not x[i], y[i])
    	addEdges(y[i] + number of variables, number of variables - x[i])
    	addEdgesInv(y[i] + number of variablesm, number of variables - x[i])
    else
    	addEdges(not x[i], number of variables - y[i])
    	addEdgesInv(not x[i], number of variables - y[i])
    	addEdges(not y[i], number of variables - x[i])
    	addEdgesInv(not y[i], number of variables - x[i])
    	
for i = 1 to 2*number of variables do:
	if not visited[i]
		dfsFirst(i)

while stack is not empty do:
    i = stack.top
    stack.pop
    if not visited[i]
    	dfsSecond(i)
        counter = counter + 1
        
for i = 1 to n do:
    if scc[x[i]] == scc[not x[i]]:
        it is unsatisfiable
        exit
    if component[y[i]] == component[not y[i]]:
        it is unsatisfiable
        exit
