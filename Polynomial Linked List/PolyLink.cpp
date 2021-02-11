#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node *nodeptr;

struct node 
{
	int coef;
	int exp;
	nodeptr next;
};

typedef nodeptr Polynomial;

// functions
Polynomial newPoly(); // allocate return the pointer to a header node

void destroyPoly(Polynomial *poly); // set to NULL after freeing

// there should be no multiple exponents
// when adding a new term, add the value to the coef for same exponents
void addTerm(Polynomial poly,int coef,int exp);

// display in decending order of exponents
void display(const Polynomial poly);

// return a new polynomial that represents the sum of poly1 and poly2
Polynomial add(const Polynomial poly1,const Polynomial poly2);

// return a new polynomial that represents the difference of p1 and p2
Polynomial subtract(const Polynomial poly1,const Polynomial poly2);

// return a new polynomial that represents the product of p1 and p2
Polynomial multiply(const Polynomial poly1,const Polynomial poly2);

// return a new polynomial that represents the derivative of p1
Polynomial derivative(const Polynomial poly);

// compute the value of the polynomial given a value for x
int evaluate(const Polynomial poly,int x);

// return 1 if the value of p is constant, 0 otherwise
int isConstant(const Polynomial poly);

// return 1 if the value of p is zero (0), 0 otherwise
int isZero(const Polynomial poly);

int main()
{
	Polynomial p1 = newPoly();
	Polynomial p2 = newPoly();
	Polynomial p3 = newPoly();
	Polynomial p4 = newPoly();
	Polynomial res; 
	
	addTerm(p1,8,0);
	addTerm(p1,9,1);
	addTerm(p1,10,2);
	addTerm(p1,11,3);
	addTerm(p1,12,4);
	addTerm(p1,13,5);
	addTerm(p1,14,6);
	addTerm(p1,15,7);
	addTerm(p1,16,8);
	
	addTerm(p2,7,0);
	addTerm(p2,6,1);
	addTerm(p2,5,2);
	addTerm(p2,4,3);
	addTerm(p2,3,4);
	addTerm(p2,2,5);
	addTerm(p2,1,6);
	addTerm(p2,-1,7);
	addTerm(p2,-2,8);
	addTerm(p2,-3,9);
	
	
	printf("P1: ");
	display(p1);
	
	printf("P2: ");
	display(p2);
	
	printf("Add [P1 + P2]: "); 
	res = add(p1,p2);
	display(res);    
	destroyPoly(&res);
	
	printf("Subtract [P1 - P2]: ");
	res = subtract(p1,p2);
	display(res);			
	destroyPoly(&res); 	
	
	printf("Multiply [P1 - P2]: ");
	res = multiply(p1,p2);  
	display(res);			
	destroyPoly(&res);	

	printf("Derivative of P1: ");
	res = derivative(p1);  
	display(res);			
	destroyPoly(&res);	
	
	printf("Derivative of P2: ");
	res = derivative(p2);  
	display(res);			
	destroyPoly(&res);		

	
	
	printf("Evaluate P2, x = 8: %d\n",evaluate(p2,8) );
	printf("Evaluate P1, x = 9: %d\n",evaluate(p1,9) );
	printf("Is P1 constant: %d\n",isConstant(p1));
	printf("Is P2 constant: %d\n",isConstant(p2));

	addTerm(p3,25,0);
	addTerm(p3,30,0);
	printf("New Poly P3: ");
	display(p3);
	printf("Is P3 constant: %d\n",isConstant(p3));

	printf("Is P2 Zero: %d\n",isZero(p2));
	printf("Is P1 Zero: %d\n",isZero(p1));
	printf("is P3 Zero: %d\n",isZero(p3));
	
	destroyPoly(&p1);
	destroyPoly(&p2);
	destroyPoly(&p3);
	
	if(p1==NULL && p2==NULL && p3==NULL && res == NULL)
		printf("\nP1 & P2 & P3 polylinks are destroyed\n");
	return 0;
}

Polynomial newPoly()
{
	nodeptr poly = (nodeptr) malloc(sizeof(struct node));
	poly->coef = 0;
	poly->exp = 0;
	poly->next = NULL;
	
	return poly;
}

void addTerm(Polynomial poly,int coef,int exp)
{
	if(coef != 0)
	{
		Polynomial x = newPoly();
		x->coef = coef;
		x->exp = exp;

		nodeptr p = poly->next;
		nodeptr temp = poly;
		
		int flag = 0;

		while(p!=NULL)
		{
			if(exp == p->exp)
			{
				p->coef += coef;

				if(p->coef == 0)
					temp->next = p->next;
				
				flag = 1;
				break;
			}
			else if(exp > p->exp)
			{
				temp->next = x;
				x->next = p;
				flag = 1;
				break;
			}
			
			temp = p;
			p=p->next;
		}

		if(flag == 0)
			temp->next = x;
	}
}

void destroyPoly(Polynomial *poly)
{
	nodeptr p = (*poly)->next;
	nodeptr temp;
	
	while(p!=NULL)
	{
		temp = p;
		free(temp);
		temp = NULL;
		p=p->next;
	}
	
	free(*poly);
	*poly = NULL;
}

void display(const Polynomial poly)
{
	nodeptr p = poly->next;
	
	int coef;
	
	while(p!= NULL)
	{
		coef= p->coef;
		
		if(coef >= 0 && poly->next != p)
			printf("+ ");
		else if(coef < 0 && poly->next != p)
		{
			coef = p->coef * - 1;
			printf("- ");
		}

		if( p->exp == 0 || (p->coef != 1 && p->coef != -1))
			printf("%d",coef);
			
		if(p->exp != 0)
		{
			if(p->exp == 1)
				printf("x ");
			else
				printf("x^%d ",p->exp);
		}
		else
			printf(" ");
		
		p = p->next;
	}
	
	if(poly->next == NULL)
		printf("0");
		
	printf("\n");
}

Polynomial add(const Polynomial poly1,const Polynomial poly2)
{
	Polynomial result = newPoly();
	nodeptr p1 = poly1->next;
	nodeptr p2 = poly2->next;
	
	while(p1!=NULL || p2 !=NULL)
	{
		if(p1 != NULL)
		{
			addTerm(result,p1->coef,p1->exp);
			p1=p1->next;
		}
		
		if(p2 != NULL)
		{
			addTerm(result,p2->coef,p2->exp);
			p2=p2->next;
		}
	}
	
	return result; 
}

Polynomial subtract(const Polynomial poly1,const Polynomial poly2)
{
	Polynomial result = newPoly();
	
	nodeptr p1 = poly1->next;
	nodeptr p2 = poly2->next;
	
	while(p1!=NULL || p2 !=NULL)
	{
		if(p1 != NULL)
		{
			addTerm(result,p1->coef,p1->exp);
			p1=p1->next;
		}
		if(p2 != NULL)
		{
			addTerm(result,p2->coef *-1,p2->exp);
			p2=p2->next;
		}
	}
	
	return result; 
}

Polynomial multiply(const Polynomial poly1,const Polynomial poly2)
{
	Polynomial result = newPoly();
	
	nodeptr p1 = poly1->next;
	nodeptr p2 = poly2->next;
	
	while(p1!=NULL)
	{
		p2=poly2->next;
		
		while(p2!=NULL)
		{
			addTerm(result,p1->coef * p2->coef, p1->exp + p2->exp);
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	
	return result; 
}

Polynomial derivative(const Polynomial poly)
{
	Polynomial result = newPoly();

	nodeptr ptr = poly;
	
	while(ptr != NULL)
	{
		addTerm(result, ptr->coef * (ptr->exp), ptr->exp - 1);
		ptr = ptr->next;
	}

	return result;
}

int evaluate(const Polynomial poly,int x)
{
	int eval = 0;
	
	nodeptr p = poly->next;
	
	while(p != NULL)
	{
		eval += (int)pow(x, p->exp)*p->coef;
		p = p->next;
	}
	
	return eval;
}

int isConstant(const Polynomial poly)
{
	return isZero(poly) || poly->next->exp == 0 && poly->next->next == NULL;
}

int isZero(const Polynomial poly)
{
	int flag = -1;
	
	nodeptr p = poly->next;
	
	if(p == NULL)
		flag = 1;
		
	if(p->exp == 0)
		flag = 1;
	
	return flag;
}
