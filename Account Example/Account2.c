#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct account //Structure
{
	char name[20];
	int accountId;
	double balance;
};

typedef struct account *Account;	//Account becomes a pointer to a structure

/*
	:act is an input parameter
	:making it a pointer allocates less memory
	:no changes allowed for this parameter
*/
void display(const Account act);	

/*
	:act is an output parameter
	:returns the address of an account
*/
Account newAccount(const char *name, double balance);

//act is both (output and input) parameter
int withdraw(Account act, double amount);

int main()
{
	Account act1, act2, act3;
	act1 = newAccount("cherry", 100.00);
	act2 = newAccount("lyn", 200.00);
	act3 = newAccount("lennard", 200.00);
	display(act1);
	display(act2);
	display(act3);
	free(act1);
	free(act2);
	free(act3);
}

Account newAccount(const char *name, double balance)
{
	Account act = (Account)malloc(sizeof(struct account));
	static int actNo = 1;	//there's only one copy of this variable; value is retained
	strcpy(act->name, name);
	act->balance = balance;
	act->accountId = actNo++;
	
	return act;
}

void display(const Account act)	
{
	printf("\n%d", act->accountId);
	printf("\n%s", act->name);
	printf("\n%lf", act->balance);
}
