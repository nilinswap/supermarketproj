#include <Python.h>
#include <string.h>
#include <iostream>
#include "errands.h"
#include <vector>
#include <cstdlib>
using namespace std;
#include "item.h"
Item tomakeitemfromcharar(char * charar,int id){

	std::stringstream test(charar);
	std::string segment;
	std::vector <std::string> seglist;

	while(std::getline(test, segment, ','))
	{
	   seglist.push_back(segment);
	}
	double cp,sp,wt,dis,db;
    // Iterate and print values of vector
    string stri;
        
    	stri=seglist[2];
    	cp=::atof(stri.c_str());
    	stri=seglist[3];
    	sp=::atof(stri.c_str());
    	stri=seglist[4];
    	wt=::atof(stri.c_str());
    	stri=seglist[5];
    	dis=::atof(stri.c_str());      
    Item tem(id,seglist[1],cp,sp,wt,dis);
    return tem;
    
} 
int main()
{
	Py_Initialize();

				PyObject *strret, *mymod, *strfunc, *strargs;
				char *cstrret;
				PyRun_SimpleString("import sys");
    			PyRun_SimpleString("sys.path.append(\".\")");
    			PyRun_SimpleString("import pymysql");
    			int id=18;
    			//cout<<"hell"<<endl;
    			string idstr= ttostring <int>(id);//this function is defined in errands.h
						char idstri[50];//this three line operation is requiered for each attribute because 
						strncpy(idstri, idstr.c_str(), sizeof(idstri));//stupid Buildvalue only takes char* as argument
						idstri[sizeof(idstri) - 1] = 0;
				//cout<<idstr<<endl;
				mymod = PyImport_ImportModule("retrieveitem");
				strfunc = PyObject_GetAttrString(mymod, "retrieveitem");
				//printf("%s\n",idstri);
				strargs = Py_BuildValue("(s)",idstri);//here I was only able to pass strings as arguments
				//strargs = Py_BuildValue("sssss",par,"45","35","24","0");
				strret = PyEval_CallObject(strfunc, strargs);
				PyArg_Parse(strret, "s", &cstrret);
				cout<<cstrret<<endl;
				Item tem=tomakeitemfromcharar(cstrret,id);
				cout<<tem.name<<tem.cp<<endl;
				//printf("%s\n",cstrret);
		Py_Finalize();
				//cout<<"here after return from funtion"<<endl;
	return 0;
}

// g++   embedtest.cpp -L/usr/include/python3.5m -lpython2.7
// g++   embedtest.cpp -I/usr/include/python3.5m -lpython3.5m