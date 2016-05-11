// funtionaddress.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "funtionaddress.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

void AppBehave();

class Foo{
public:
	void nv()
	{
		printf("Hello from a non-virtual method in Foo!\n");
	}

	virtual void v()
	{
		printf("Hello from a virtual method in a Foo!\n");
	}
};

class FooBar : public Foo {
public:
	void nv()
	{
		printf("Hello from a non-virtual method in FooBar ! \n");
	}

	virtual void v()
	{
		printf("Hello from a virtual method in FooBar! \n");
	}
};

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		_tprintf(_T("Fatal Error: MFC initialization failed\n"));
		nRetCode = 1;
	}
	else
	{
		AppBehave();
	}

	return nRetCode;
}


void AppBehave()
{
FooBar foobar;
	Foo foo;

	foobar.nv();
	foobar.v();

	Foo *fooPtr = (Foo*)&foobar;
	fooPtr->nv();
	fooPtr->v();

	printf("------------\n");

	printf("sizeof(foobar) = %d, sizeof(foo) = %d \n", sizeof(foobar), sizeof(foo) );

	long *foobarAsLong = (long*)&foobar;
	long *fooAsLong = (long*)&foo;

	printf("FooBar vtable pointer: %p\n", foobarAsLong[0]);
	printf("Foo vtable pointer : %p \n", fooAsLong[0]);


	//code to print the first entry of the vtable as down below.
	long **foobarVtable = (long **)&foobar;
	printf("foobar Vtable pointer using the long** : %p\n", foobarVtable[0]);
	printf("First entry of FooBar table : %p\n", foobarVtable[0][0]);

	long **fooVtable = (long**)&foo;
	printf("First entry of Foo vtable : %p\n", fooVtable[0][0]);
}