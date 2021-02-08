#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main
{
	IntList list = 
	
	addFront(list, 10);
	addFront(list, 20);
	addFront(list, 30);
	addFront(list, 40);
	display("list", list);
	removeFront(list);
	display("list", list);
	addRear(list, 1);
	display("list", list);
	
	return 0;
}
