#include "Python.h"
#include "errands.h"
using namespace std;
#include <typeinfo>
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
		virtual void committask(){};
		

};
class addtodb:public Task{
	//this task would add new product to db
	public:
		addtodb(Item tem,guestunion guest,int operation):Task(tem,guest,operation){}
		
		void committask(){//this would do the main task after the database has been opened.
				PyObject *strret, *mymod, *strfunc, *strargs;

				string cpstr= ttostring <double>(cp);
				string spstr= ttostring <double>(sp);
				string wtstr= ttostring <double>(wt);
				string disstr= ttostring <double>(dis);//this function is defined in errands.h
						char cpstri[50];//this three line operation is requiered for each attribute because 
						strncpy(cpstri, cpstr.c_str(), sizeof(cpstri));//stupid Buildvalue only takes char* as argument
						cpstri[sizeof(cpstri) - 1] = 0;
						char spstri[50];
						strncpy(spstri, spstr.c_str(), sizeof(spstri));
						spstri[sizeof(spstri) - 1] = 0;
						char wtstri[50];
						strncpy(wtstri, wtstr.c_str(), sizeof(wtstri));
						wtstri[sizeof(wtstri) - 1] = 0;
						char disstri[50];
						strncpy(disstri, disstr.c_str(), sizeof(disstri));
						disstri[sizeof(disstri) - 1] = 0;
						char namestri[50];
						strncpy(namestri, name.c_str(), sizeof(namestri));
						namestri[sizeof(namestri) - 1] = 0;
				//printf("%s %s %s %s \n",cpstri,spstri,wtstri,disstri);
				//std::cout<<typeid(cpstr).name()<<typeid(spstr).name()<<typeid(wtstr).name()<<typeid(disstr).name()<<endl;
				
    			//cout<<"after this"<<endl;
				mymod = PyImport_ImportModule("addtodbcore");
				strfunc = PyObject_GetAttrString(mymod, "addtodbcore");
				
				strargs = Py_BuildValue("sssss",namestri,cpstri,spstri,wtstri,disstri);//here I was only able to pass strings as arguments
				//strargs = Py_BuildValue("sssss",par,"45","35","24","0");
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
