#include <Python.h>
int main()
{
	PyObject *strret, *mymod, *strfunc, *strargs;
	char *cstrret;
	Py_Initialize();
	PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append(\".\")");
    PyRun_SimpleString("import pymysql");
	mymod = PyImport_ImportModule("addtodbcore");
	strfunc = PyObject_GetAttrString(mymod, "addtodbcore");
	strargs = Py_BuildValue("sssss","item","34","32","12","23");
	strret = PyEval_CallObject(strfunc, strargs);
	//PyArg_Parse(strret, "s", &cstrret);
	//printf("Reversed string: %s\n", cstrret);
	Py_Finalize();
	return 0;
}
