#include <iostream>
#include <string.h>
#include <Python.h>
//#include <iostream>
//#include <string.h>
#include "item.h"
#include  "itemgroup.h"
#include "admin.h"
#include "list.h"
#include "cashier.h"
#include <stdlib.h>
#include <termios.h>
int passad(){
	Py_Initialize();
					PyRun_SimpleString("import sys");		
    			PyRun_SimpleString("sys.path.append(\".\")");
    			PyObject *strret, *mymod, *strfunc, *strargs;
				char *cstrret;
					string input;
							cout<<"enter admin's password"<<endl;
								system("stty -echo");
								cin>>input;
								
								system("stty echo");
						char cpstri[50];//this three line operation is requiered for each attribute because 
						strncpy(cpstri, input.c_str(), sizeof(cpstri));//stupid Buildvalue only takes char* as argument
						cpstri[sizeof(cpstri) - 1] = 0;
						
						
				//printf("%s %s %s %s \n",cpstri,spstri,wtstri,disstri);
				//std::cout<<typeid(cpstr).name()<<typeid(spstr).name()<<typeid(wtstr).name()<<typeid(disstr).name()<<endl;
				
    			
				mymod = PyImport_ImportModule("passpy");
				strfunc = PyObject_GetAttrString(mymod, "passfun");
				
				strargs = Py_BuildValue("(s)",cpstri);//here I was only able to pass strings as arguments
				//strargs = Py_BuildValue("sssss",par,"45","35","24","0");
				strret = PyEval_CallObject(strfunc, strargs);
				PyArg_Parse(strret, "s", &cstrret);
				
	Py_Finalize();
				if(cstrret[0]=='1')
				{	return 1;}
				else
					return 0;

	    			

};
int passall(){
	Py_Initialize();
					PyRun_SimpleString("import sys");		
    			PyRun_SimpleString("sys.path.append(\".\")");
    			PyObject *strret, *mymod, *strfunc, *strargs;
				char *cstrret;
					string input;
							cout<<"enter password"<<endl;
								system("stty -echo");
								cin>>input;
								
								system("stty echo");
						char cpstri[50];//this three line operation is requiered for each attribute because 
						strncpy(cpstri, input.c_str(), sizeof(cpstri));//stupid Buildvalue only takes char* as argument
						cpstri[sizeof(cpstri) - 1] = 0;
						
						
				//printf("%s %s %s %s \n",cpstri,spstri,wtstri,disstri);
				//std::cout<<typeid(cpstr).name()<<typeid(spstr).name()<<typeid(wtstr).name()<<typeid(disstr).name()<<endl;
				
    			
				mymod = PyImport_ImportModule("passpy");
				strfunc = PyObject_GetAttrString(mymod, "passfunny");
				
				strargs = Py_BuildValue("(s)",cpstri);//here I was only able to pass strings as arguments
				//strargs = Py_BuildValue("sssss",par,"45","35","24","0");
				strret = PyEval_CallObject(strfunc, strargs);
				PyArg_Parse(strret, "s", &cstrret);
				
	Py_Finalize();
				if(cstrret[0]=='1')
				{	return 1;}
				else
					return 0;

	    			

};
int main(){
	if(!passall()){
		cout<<"who are you?"<<endl;
		return 1;
	}
	ask://HERE I HAVE USED 'goto' just so that the program does not exit after cashier or admin 
	system("clear");
	cout<<"login as"<<endl;
	cout<<"\t1. cashier"<<endl<<"\t2. admin"<<endl<<"\t3. exit"<<endl;
	int i;
	cin>>i;
	system("clear");
	Py_Initialize();
					PyRun_SimpleString("import sys");		
    			PyRun_SimpleString("sys.path.append(\".\")");
    			PyRun_SimpleString("import pymysql");
    			//PyRun_SimpleString("import imp\nfrom imp import reload");


	switch(i){
		case 1:
		{	
			cashiermain();
			goto ask;//     HERE goto
			break;
		}
		case 2:
		{
			if(!passad())
			{
				cout<<"wrong password for admin"<<endl;
				break;
			}
			cout<<"welcome"<<endl;
			adminmain();
			goto ask;// HERE goto
			break;
		}
		default:{
			break;
		}
	}
	Py_Finalize();
	return 0;
	
}
