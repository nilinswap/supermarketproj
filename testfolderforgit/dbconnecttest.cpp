#include <Python.h>
#include <string.h>
#include <iostream>
using namespace std;
int main()
{
	PyObject *strret, *mymod, *strfunc, *strargs;
	char *cstrret;
	Py_Initialize();
	PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append(\".\")");
	mymod = PyImport_ImportModule("addtodbcore");
	strfunc = PyObject_GetAttrString(mymod, "addtodbcore");
	//strfunc = PyObject_GetAttrString(mymod, "multiply");
	char name[]="itemtest";char cp[]="45",sp[]="35",wt[]="100",dis[]="0";
	//printf("%s %s %s %s %s\n",name,cp,sp,wt,dis);
	strargs = Py_BuildValue("(sssss)", name,cp,sp,wt,dis);
	//strargs = Py_BuildValue("(ss)","6","7" );
	//std::cout<<strargs<<std::endl;
	strret = PyEval_CallObject(strfunc, strargs);
	PyArg_Parse(strret, "s", &cstrret);
	//std::cout<<"here"<<std::endl;
	//printf("Reversed string: %s\n", cstrret);
	//std::cout<<strargs<<std::endl;
	Py_Finalize();
	return 0;
}

// g++   embedtest.cpp -L/usr/include/python3.5m -lpython2.7
// g++   embedtest.cpp -I/usr/include/python3.5m -lpython3.5m