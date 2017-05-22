#include <Python.h>
int main()
{
	PyObject *strret, *mymod, *strfunc, *strargs;
	char *cstrret;
	Py_Initialize();
	PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append(\".\")");
	mymod = PyImport_ImportModule("reverse");
	strfunc = PyObject_GetAttrString(mymod, "rstring");
	strargs = Py_BuildValue("(s)", "Hello World");
	strret = PyEval_CallObject(strfunc, strargs);
	PyArg_Parse(strret, "s", &cstrret);
	printf("Reversed string: %s\n", cstrret);
	Py_Finalize();
	return 0;
}
//CPLUS_INCLUDE_PATH=/usr/include/python3.5m
//export CPLUS_INCLUDE_PATH
//g++   embedfun.cpp -I/usr/include/python3.5m -lpython3.5m