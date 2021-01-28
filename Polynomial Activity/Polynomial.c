#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef int *Polynomial;

//functions
Polynomial newPoly();	//allocate return the pointer
void destroyPoly(Polynomial *p);	//set to NULL after freeing
void addTerm(Polynomial p, int coef, int exp);	
void display(const Polynomial p);

//return a new polynomial that represents the sum of p1 and p2
Polynomial add(const Polynomial p1, const Polynomial p2);

// return a new polynomial that represents the difference of p1 and p2
Polynomial subtract(const Polynomial p1, const Polynomial p2);

// return a new polynomial that represents the derivative of p1
Polynomial derivative(const Polynomial p);

// compute the value of the polynomial given a value for x
int evaluate(const Polynomial p,int x);

// return 1 if the value of p is constant, 0 otherwise
int isConstant(const Polynomial p);

// return 1 if the value of p is zero (0), 0 otherwise
int isZero(const Polynomial p);

// return 1 if there is coefficient for all exponents, 0 otherwise
int isComplete(const Polynomial p);

int main()
{
	Polynomial p1, p2;	//Pointer
	
	p1 = newPoly();
	addTerm(p1, -2, 2);
	addTerm(p1, 2, 3);
	addTerm(p1, 5, 6);
	
	p2 = newPoly();
	addTerm(p2, 2, 2);
	addTerm(p2, 3, 3);
	addTerm(p2, 4, 4);
	addTerm(p2, 5, 5);
	addTerm(p2, 6, 6);
	
	printf("Polynomial p1: ");
	display(p1);
	
	printf("\nPolynomial p2: ");
	display(p2);
	
	printf("\n\nSum: ");
	display(add(p1, p2));
	printf("\nDifference: ");
	display(subtract(p1, p2));
	printf("\nDerivative: ");
	display(derivative(p1));
	printf("\nEvaluate p1 when [x = 2]: %d", evaluate(p1, 2));
	printf("\nEvaluate p2 when [x = 2]: %d", evaluate(p2, 2));
	printf("\np1 constant: %d", isConstant(p1));
	printf("\np2 constant: %d", isConstant(p2));
	printf("\np1 zero: %d", isZero(p1));
	printf("\np2 zero: %d", isZero(p2));
	printf("\np1 complete: %d", isComplete(p1));
	printf("\np2 complete: %d", isComplete(p2));
}

Polynomial newPoly()
{
	Polynomial p = (Polynomial)calloc(MAX, sizeof(int));	//Automatically initialize each block to 0
	
	return p;
}

void destroyPoly(Polynomial *p)
{
	free(*p);
	*p = NULL;
}

void addTerm(Polynomial p, int coef, int exp)
{
	p[exp] = coef;
}

void display(const Polynomial p)
{
	int i, flag = 0;
	
	for(i = 0; i < MAX; i++)
	{
		if(p[i] != 0)
		{
			if(p[i] > 0 && flag == 1)
				printf(" + ");
			if(i == 0 || p[i] != 1)
				printf("%d", p[i]);	//coef
			if(i > 0)
				printf("x");
			if(i > 1)
				printf("^%d", i);	//exp
				
			flag = 1;
		}
	}
}

Polynomial add(const Polynomial p1, const Polynomial p2)
{
	int i;
	Polynomial sum = newPoly();
	
	for(i = 0; i < MAX; i++)
	{
		sum[i] = p1[i] + p2[i];
	}
	
	return sum;
}

Polynomial subtract(const Polynomial p1, const Polynomial p2)
{
	int i;
	Polynomial dif = newPoly();
	
	for(i = 0; i < MAX; i++)
	{
		dif[i] = p1[i] - p2[i];
	}
	
	return dif;
}

Polynomial derivative(const Polynomial p)
{
	int i;
	Polynomial derivative = newPoly();
	
	for(i = 0; i < MAX; i++)
	{
		if(p[i]!=0)
			derivative[i] = p[i] * i;
			derivative[i-1] = derivative[i];
	}
	
	return derivative;
}

int evaluate(const Polynomial p,int x)
{
	int exp, temp, eval = 0, i;
	
	for(i = 0; i < MAX; i++)
	{
		exp = 1;
		temp = 1;
		
		if(p[i] != 0)
		{
			while(exp <= i)
			{
				temp *= x;
				exp++;
			}
			eval = eval + p[i] * temp;
			
		}
	}
	
	return eval;
}

int isConstant(const Polynomial p)
{
	int i, flag = 1;
	
	for(i = 0; i < MAX; i++)
	{
		if(p[i] != 0 && i != 0)
		{
			flag = 0;
			break;
		}
	}
	
	return flag;
}

int isZero(const Polynomial p)
{
	int i, flag = 1;
	
	for(i = 0; i < MAX; i++)
	{
		if(p[i] != 0)
		{
			flag = 0;
			break;	
		}	
	}
	
	return flag;
}

int isComplete(const Polynomial p)
{
	int i, flag = 1;
	
	for(i = 0; i < MAX; i++)
	{
		if(p[i] == 0)
		{
			flag = 0;
			break;
		}
	}
	
	return flag;
}
