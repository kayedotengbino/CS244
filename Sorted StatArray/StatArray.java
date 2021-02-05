import java.util.*;

public class StatArray implements Statistician
{
    private int count;
    private int size;
    private int items[];

    StatArray()
    {
        this.items = new int[10];
        this.count = 0;
        this.size = 10;
    }

    public void addLast(int elem)
    {
        if(count < this.size)
            this.items[this.count++] = elem;
    }

    public void add(int elem)
    {
        int i;

        for(i = (this.count++) - 1; i >= 0 && this.items[i] > elem; i--)
            this.items[i+1] = this.items[i];

        this.items[i+1] = elem;
    }

    public String toString()
    {
        

        return Arrays.toString(this.items);  
    }

    public void clear()
    {
        this.count = 0;
    }

    public boolean isEmpty()
    {
        return this.count == 0;
    }

    public boolean contains(int elem)
    {
        for(int i = 0; i < this.count; i++)
        {
            if(this.items[i] == elem)
                return true;
        }

        return false;
    }
    
    public int frequency(int elem) // number of occurrences of elem
    {
        int freq = 0;

        for(int i = 0; i < this.count; i++)
        {
            if(this.items[i] == elem)
                freq++;
        }

        return freq;
    }

    public int getCount()
    {
        return this.count;
    }

    public int findMin()
    {
        return this.items[0];
    }

    public int findMax()
    {
        return this.items[this.count - 1];
    }

    public int findRange()
    {
        return this.items[this.count - 1] - this.items[0];
    }

    public float findMedian()
    {
        //odd
        if(this.count % 2 != 0) 
            return this.items[(this.count / 2) + 1];

        //even
        else    
            return (float)(this.items[(this.count - 1) / 2] + (float)this.items[((this.count - 1) /2) + 1]) / 2;
    }

    public int findSum()
    {
        int sum = 0;

        for(int i = 0; i < this.count; i++)
            sum += this.items[i];

        return sum;
    }

    public float findMean()
    {
        return (float)findSum() / this.count;
    }

    public float findStandardDeviation()
    {
        float stdDeviation = 0;

        for(int i = 0; i < this.count; i++)
            stdDeviation += Math.pow(this.items[i] - findMean, 2);

        return Math.sqrt(stdDeviation / (this.count - 1));
    }

    private int findPos(int elem)
    {
        int pos = -1;

        for(int i = 0; i < this.count; i++)
        {
            if(this.items[i] == elem)
            {
                pos = i;
                break;
            }
        }

        return pos;
    }
    
    //implement remove such that, when you find the item to be removed
    // replace it with the last xent
    public void removeFirst(int x)
    {
        int pos = findPos(s, x);

        if(pos != -1)
        {
            for(int i = 0; i < this.count; i++)
                this.items[i] = this.items[i+1];

            this.count--;
        }
    }
    
    //remove all occurrences, same strategy as removeFirst
    public void removeAll(int x)
    {
        for(int i = 0; i < this.count; i++)
            removeFirst(s, x);
    }

    public void display()
    {
        System.out.print("{ ");
    
        for(int i = 0; i < this.count; i++)
        {
            System.out.print(this.items[i] + " ");
        }
        
        System.out.print(" }");
    }
}

