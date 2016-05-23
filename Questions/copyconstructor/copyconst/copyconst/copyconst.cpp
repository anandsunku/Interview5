// copyconst.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//http://geeksquiz.com/copy-constructor-in-cpp/

void appbehaviour();

int _tmain(int argc, _TCHAR* argv[])
{
	appbehaviour();
	return 0;
}

class thing
{
public:
	int value1;

	thing()
	{
		printf("\n im normal constructor");
	}

	thing(const thing& objThing)
	{
		printf("\n im copy constructor");
	}
};

thing checkReturn()
{
	thing v1;

	v1.value1 = 10;
	return v1;
}

void appbehaviour()
{
	printf("hello world\n");
	
	thing ob1;
	ob1.value1 = 100;

	thing ob2= ob1;

	thing ob3;
	printf("\n\nexpecting copy constructor call\n");
	ob3 = checkReturn();

	printf("\n\nexpecting copy constructor call\n");
	thing ob4 = checkReturn();


	printf("\n\n");
}