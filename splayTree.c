/*
    Splay Tree
        invented by Daniel Dominic Seator and Robert Endre Tarjan in 1985
        another kind of BST
        self adjusting, self balancing 
        Not balanced at all time
        Performs basic operations - in amortized time
            Search
            Delete
            Insert
        most accessed element is near the root
            utilize the principle of locatily (80-20 rul) 
        Running Time
            O(Mlog n) - M - operations, M > n
            O(log n) - average
            Theta(n) - worst

    BST
        no balance condition

    Zig - right
    Zag - Left

    Insert 
        O(n^2) - not adjusted
        O(1) - adjusted

    Algorithm Design Technique
        Divide and Conquer
*/