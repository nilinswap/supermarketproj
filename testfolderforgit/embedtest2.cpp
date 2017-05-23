#include <stdio.h>
#include <conio.h>
#include <Python.h>

int main()
{
	wchar_t filename[18] =L"pyemb7.py";
	FILE* fp;

	Py_Initialize();

	//fp = _Py_fopen(filename, "r");
	//PyRun_SimpleFile(fp, filename);
	Py_SetProgramName(filename);
Py_Initialize();
PyRun_SimpleString("execfile(\"pyemb7.py\")");
Py_Finalize();
	return 0;
}
