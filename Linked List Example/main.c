#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "LinkedList.c"

int main()
{
	IntList list = newIntList();	//create the header node
	
	//reversed output if displayed
	addFront(list, 10);
	addFront(list, 10);
	addFront(list, 10);
	addFront(list, 10);
	display("list", list);
	removeFront(list);
	display("list", list);
	
	return 0;
}
