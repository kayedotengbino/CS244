interface Statistician {

    //public void Statistician(); No constructor in interface
    public void addLast(int elem);
    public void add(int elem);
    // instead of void display(const char *name,const StatArray s);
    // override to toString() methods
    public void clear();
    public boolean isEmpty();
    public boolean contains(int elem);
    public int frequency(int elem); // number of occurrences of elem
    public int getCount();
    public int findMin();
    public int findMax();
    public int findRange();
    public float findMedian();
    public int findSum();
    public float findMean();
    public float findStandardDeviation();
    
    //implement remove such that, when you find the item to be removed
    // replace it with the last xent
    public void removeFirst(int x);
    
    //remove all occurrences, same strategy as removeFirst
    public void removeAll(int x);
    
    }