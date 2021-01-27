#include <stdio.h>
#include <string.h>

struct account //Structure
{
	char name[20];
	int accountId;
	double balance;
};

typedef struct account Account;	//We are performing abstraction

/*
	:act is an input parameter
	:making it a pointer allocates less memory
	:no changes allowed for this parameter
*/
void display(const Account *act);	

//act is an output parameter
void initialize(Account *act, const char *name, double balance);

//act is both (output and input) parameter
int withdraw(Account *act, double amount);

int main()
{
	Account act1, act2, act3;	//Account is located in Stack
	initialize(&act1, "cherry", 100.00);
	initialize(&act2, "lyn", 200.00);
	initialize(&act3, "lennard", 200.00);
	display(&act1);
	display(&act2);
	display(&act3);
}

void initialize(Account *act, const char *name, double balance)
{
	static int actNo = 1;	//there's only one copy of this variable; value is retained
	strcpy(act->name, name);
	act->balance = balance;
	act->accountId = actNo++;
}

void display(const Account *act)	
{
	printf("\n%d", act->accountId);
	printf("\n%s", act->name);
	printf("\n%lf", act->balance);
}
