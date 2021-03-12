#include <stdio.h>

int fibo1(int n)
{
	int first = 0;
	int second = 1;
	int sum;
	
	if(n <= 1)
		return n;
	else
	{
		for(int i = 2; i <= n; i++)
		{
			sum = first + second;
			first = second;
			second = sum;
		}
		return sum;
	}
}

int fibo2(int n)
{
	if(n <= 1)
		return n;
	else
		return fibo2(n-1) + fibo2(n-2);
}

int fibo3(int n)
{
	int table[n];
 
    table[0]=0;
    table[1]=1;
 
    for(int i=2;i<=n;i++)
        table[i] = table[i-1] + table[i-2];
 
    return table[n];
}

int main()
{
	int n;
	
	scanf("%d", &n);
	
	printf("fibo1(%d)=%d", n,fibo1(n));
	printf("\nfibo2(%d)=%d", n,fibo2(n));
	printf("\nfibo3(%d)=%d", n,fibo3(n));
}
