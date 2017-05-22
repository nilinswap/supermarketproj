#include <stdio.h>
#include <conio.h>
#include <Python.h>

void func(){
	PyRun_SimpleString("print('Hello World from Embedded Python!!!')");
}
int main()
{
	PyObject* pInt;

	Py_Initialize();

	func();
	
	Py_Finalize();

	printf("\nPress any key to exit...\n");
	if(!getch()) getch();
	return 0;
}
// g++   embedtest.cpp -L/usr/include/python3.5m -lpython2.7
// g++   embedtest.cpp -I/usr/include/python3.5m -lpython3.5m