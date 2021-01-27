#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct int *Polynomial;

//functions
Polynomial newPoly();	//allocate return the pointer
void destroyPoly(Polynomial *p);	//set to NULL after freeing
void addTerm(Polynomial p, int coef, int exp);	
void display(const Polynomial p);

//return a new polynomial that represents the sum of p1 and p2
Polynomial add(const Polynomial p1, const Polynomial p2);

// return a new polynomial that represents the difference of p1 and p2
Polynomial subtract(const Polynomial p1,const Polynomial p1 );

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
