#include "Python.h"
#include "errands.h"
using namespace std;
union guestunion{
		int id;
		char name[50];//earlier I had kept here 'string name' instead of char [50] so union was not getting an idea of how large it has to take space therefore it was throwing an error.
		double cp;
		double sp;
		double wt;
		double dis;
	};						//here guest is the key as per which a task is asked. e.g. if we want to query a name then 'name' is guest
class Task:public Item{//Task is a virtual base class here, to be extended by other particular task
	public:
		guestunion guest;
		int operation;
		
		Task(Item tem,guestunion guest,int operation):Item(tem){this->guest=guest;this->operation=operation;}
		virtual void committask();
		virtual void coretask();

};
class addtodb:public Task{
	//this task would add new product to db
	public:
		addtodb(Item tem,guestunion guest,int operation):Task(tem,guest,operation){}
		void committask(){//this would immediately add product to db.
				
				
				Py_Initialize();

				coretask();
			
				Py_Finalize();

		}
		void coretask(){//this would do the main task after the database has been opened.
				PyObject *strret, *mymod, *strfunc, *strargs;
				string cpstr= ttostring <double>(cp);
				string spstr= ttostring <double>(sp);
				string wtstr= ttostring <double>(wt);
				string disstr= ttostring <double>(dis);
				PyRun_SimpleString("import sys");
    			PyRun_SimpleString("sys.path.append(\".\")");
    			PyRun_SimpleString("import pymysql");
				mymod = PyImport_ImportModule("addtodbcore");
				strfunc = PyObject_GetAttrString(mymod, "addtodbcore");
				strargs = Py_BuildValue("sssss",name,cpstr,spstr,wtstr,disstr);
				strret = PyEval_CallObject(strfunc, strargs);
		}
};
class displaydb:public Task{
	public:
		void committask(){
		}
};
class askdb: public Task{
	public:
		void committask(){
		}
};
class editprodindb: public Task{
	public:
		void committask(){
		}
};
class deldb: public Task{
	public:
		void committask(){
		}
};
