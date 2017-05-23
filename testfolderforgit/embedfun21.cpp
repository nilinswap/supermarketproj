#include <Python.h>
int main()
{
	PyObject *strret, *mymod, *strfunc, *strargs;
	char *cstrret;
	Py_Initialize();
	PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append(\".\")");
	mymod = PyImport_ImportModule("multiply");
	strfunc = PyObject_GetAttrString(mymod, "multiply");
	strargs = Py_BuildValue("(ss)","6","7" );
	strret = PyEval_CallObject(strfunc, strargs);
	PyArg_Parse(strret, "s", &cstrret);
	printf("Reversed string: %s\n", cstrret);
	Py_Finalize();
	return 0;
}
