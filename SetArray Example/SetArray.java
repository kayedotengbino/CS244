class SetArray
{
    private int items[];    //pointer to an array, elements
    private int count;
    private int size;   //array size

    //Constructor
    public SetArray()
    {
        System.out.println("inside destructor");
        
        /*
            Object's name is the word 'this'
            If you have to disambiguate you need to use 'this'
        */
        this.items = new int[10];
        this.count = 0;
        this.size = 10;
        
        //No return function since this is a constructor
    }

    public void add(int elem)
    {
        if(count < size)
        {
            items[count++] = elem;
        }
    }

    public void display()
    {
        System.out.print("{ ");
    
        for(int i = 0; i < count; i++)
        {
            System.out.print(items[i] + " ");
        }
        
        System.out.print(" }");
    } 

    public static void main(String args[])
    {
        SetArray s = new SetArray();	
        s.add(2);
        s.add(3);
        s.add(3);
        s.display();
        //No need to call destroy because it will automatically be called
    }
}  