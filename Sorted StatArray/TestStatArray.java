public class TestStatArray
{
    public static void main(String[] args)
    {
        StatArray stat = new StatArray();
        stat.add(5);
        stat.add(3);
        stat.add(1);
        stat.add(4);
        stat.display();
        System.out.println("Clearing");
        stat.clear();
        if(stat.isEmpty())
            System.out.println("yes");
        else
            System.out.println("no");
        stat.addLast(10);
        stat.addLast(20);
        stat.addLast(30);
        stat.addLast(40);
        stat.addLast(40);
        stat.display();
        System.out.println("");
        System.out.println("Empty");
        if(stat.isEmpty())
            System.out.println("yes");
        else
            System.out.println("no");
            System.out.println("Empty");
        if(stat.contains(10))
            System.out.println("yes");
        else
            System.out.println("no");
        if(stat.contains(8))
            System.out.println("yes");
        else
            System.out.println("no");
        System.out.println("AddLast");
        stat.addLast(40);
        stat.addLast(10);
        stat.display();
        System.out.println("");
        System.out.println("Count: " + stat.getCount());
        
        System.out.println("Max: " + stat.findMax());
        
        System.out.println("Mean: " + stat.findMean());
        
        System.out.println("Min: " + stat.findMin());
        
        System.out.println("Median: " + stat.findMedian());
        
        System.out.println("Mean: " + stat.findMean());
        
        System.out.println("Sum: " + stat.findSum());
    }
}