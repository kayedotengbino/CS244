#include <stdio.h>

//Checks if the first 2 digits of a three digit number is even or odd
int isEvenOrOdd(int digits)	
{
	int isOdd = 1;	//Make it a default
	
	int temp = digits * .100;
	
	if(temp % 2 == 0)
		isOdd = 0;
	
	return isOdd;
}

int main()
{
	int digits, choice = 1;
	
	while(choice == 1)
	{
		printf("Enter three digits number: "); scanf("%d", &digits);
	
		if(isEvenOrOdd(digits))
			printf("First 2 digits are odd");
		else
			printf("First 2 digits are even");
			
		printf("\nDo you still want to try other digits(1 = yes | 0 = no)? "); scanf("%d", &choice);
	}
	
	return 0;
}
