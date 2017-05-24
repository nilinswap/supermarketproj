#include <Python.h>
#include <string.h>
#include <iostream>
using namespace std;
int main()
{
	
	/*PyObject *strret, *mymod, *strfunc, *strargs;
	char *cstrret;
	Py_Initialize();
	PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append(\".\")");
	mymod = PyImport_ImportModule("addtodbcore");
	//strfunc = PyObject_GetAttrString(mymod, "addtodbcore");
	strfunc = PyObject_GetAttrString(mymod, "multiply");
	std::string name="itemtest";double cp=46,sp=36,wt=100,dis=0;
	//strargs = Py_BuildValue("(sdddd)", name,cp,sp,wt,dis);
	strargs = Py_BuildValue("(ss)","6","7" );
	std::cout<<strargs<<std::endl;
	strret = PyEval_CallObject(strfunc, strargs);
	PyArg_Parse(strret, "s", &cstrret);
	//std::cout<<"here"<<std::endl;
	//printf("Reversed string: %s\n", cstrret);
	Py_Finalize();*/
	PyObject *strret, *mymod, *strfunc, *strargs;
				/*string cpstr= ttostring <double>(cp);
				string spstr= ttostring <double>(sp);
				string wtstr= ttostring <double>(wt);
				string disstr= ttostring <double>(dis);*/
				Py_Initialize();
				char name[]="nameisname";
				char cpstr[]="45";
				char spstr[]="35";
				char wtstr[]="140";
				char disstr[]="0";
				//std::cout<<typeid(cpstr).name()<<typeid(spstr).name()<<typeid(wtstr).name()<<typeid(disstr).name()<<endl;
				PyRun_SimpleString("import sys");
    			PyRun_SimpleString("sys.path.append(\".\")");
    			PyRun_SimpleString("import pymysql");
    			//cout<<"here before importing module"<<endl;
				mymod = PyImport_ImportModule("addtodbcore");
				strfunc = PyObject_GetAttrString(mymod, "addtodbcore");
				//cout<<"here after fetching funtion"<<endl;
				strargs = Py_BuildValue("sssss",name,cpstr,spstr,wtstr,disstr);
				strret = PyEval_CallObject(strfunc, strargs);
				Py_Finalize();
				//cout<<"here after return from funtion"<<endl;
	return 0;
}

// g++   embedtest.cpp -L/usr/include/python3.5m -lpython2.7
// g++   embedtest.cpp -I/usr/include/python3.5m -lpython3.5m