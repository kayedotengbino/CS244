#include <stdio.h>


/*
example 7 elements
0..6
first = 0;
last = 6
mid = 3;
*/

int binarySearch(int *array,int x,int first,int last){
	int mid;
	
	if (first <= last) { // at least one element
		mid = (first + last) / 2;
		if (x == array[mid] )
			return 1;
		else 
		if (x < array[mid])
			return binarySearch(array,x,first,mid-1);
		else
			return binarySearch(array,x,mid+1,last);
	}
	else
		return 0;	
}

int main() {
	
	int array[] = {1,3,8,14,15,28,39};
	printf("\nbinary search 15 = %d",binarySearch(array,15,0,6));
	printf("\nbinary search 10 = %d",binarySearch(array,10,0,6));
	printf("\nbinary search 28 = %d",binarySearch(array,28,0,6));
	printf("\nbinary search 100 = %d",binarySearch(array,100,0,6));
	
}


