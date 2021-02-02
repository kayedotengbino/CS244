#include <stdio.h>
#include <stdlib.h>

//The class is like a struct
class SetArray	//Object
{
/*
	Data members
	Accessed directly
*/
private:
	int *items;	//pointer to an array, elements
	int count;
	int size;	//array size

/*
	Functions
	No more parameters because it becomes an object
*/
public:
	//Declare con/destructor
	SetArray();
	~SetArray();
	
	void add(int elem);
	//void remove(int elem);
	//int contains(int elem) const;
	void display() const;	//will not change the object
	//int cardinality() const;
};

SetArray newSetArray();
void destroy(SetArray *s);

int main()
{
	SetArray s;	
	s.add(2);
	s.add(3);
	s.add(3);
	s.display();
	//No need to call destroy because it will automatically be called
	
	return 0;
}

//Constructor
SetArray::SetArray()	//SetArray:: is the scope resolution
{
	printf("inside destructor");
	
	/*
		Object's name is the word 'this'
		If you have to disambiguate you need to use 'this'
	*/
	this->items = new int[10];
	this->count = 0;
	this->size = 10;
	
	//No return function since this is a constructor
}

//Destructor
SetArray::~SetArray()
{
	printf("\ninside destructor");
	delete [] items;
}

void SetArray::add(int elem)	
{
	if(count < size)
	{
		items[count++] = elem;
	}
}

void SetArray::display() const
{
	int i;
	
	printf("\n{ ");
	
	for(i = 0; i < count; i++)
	{
		printf("%d ", items[i]);
	}
	
	printf(" }");
}
