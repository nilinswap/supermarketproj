using namespace std;
//#include "errands.h"
#include <vector>
#include <cstdlib>
using namespace std;
//#include "item.h"
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
Itemgroup makeitemgroupfromid(int id,int num){
	if(id>0)
	{
		/*Py_Initialize();

				PyObject *strret, *mymod, *strfunc, *strargs;
				char *cstrret;
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
				PyRun_SimpleString("import sys");
    			PyRun_SimpleString("sys.path.append(\".\")");
    			PyRun_SimpleString("import pymysql");
    			
				mymod = PyImport_ImportModule("addtodbcore");
				strfunc = PyObject_GetAttrString(mymod, "addtodbcore");
				
				strargs = Py_BuildValue("sssss",namestri,cpstri,spstri,wtstri,disstri);//here I was only able to pass strings as arguments
				//strargs = Py_BuildValue("sssss",par,"45","35","24","0");
				strret = PyEval_CallObject(strfunc, strargs);
				PyArg_Parse(strret, "s", &cstrret);
		Py_Finalize();*/
		Py_Initialize();

				PyObject *strret, *mymod, *strfunc, *strargs;
				char *cstrret;
				PyRun_SimpleString("import sys");
    			PyRun_SimpleString("sys.path.append(\".\")");
    			cout<<"error"<<endl;
    			//PyRun_SimpleString("import pymysql");
    			
    			//cout<<"hell"<<endl;
    			string idstr= ttostring <int>(id);//this function is defined in errands.h
						char idstri[50];//this three line operation is requiered for each attribute because 
						strncpy(idstri, idstr.c_str(), sizeof(idstri));//stupid Buildvalue only takes char* as argument
						idstri[sizeof(idstri) - 1] = 0;
				//cout<<idstr<<endl;
				mymod = PyImport_ImportModule("retrieveitem");
				strfunc = PyObject_GetAttrString(mymod, "retrieveitem");
				//printf("%s\n",idstri);
				cout<<"errorhere"<<endl;
				strargs = Py_BuildValue("(s)",idstri);//here I was only able to pass strings as arguments
				//strargs = Py_BuildValue("sssss",par,"45","35","24","0");
				strret = PyEval_CallObject(strfunc, strargs);
				PyArg_Parse(strret, "s", &cstrret);
				//cout<<cstrret<<endl;
				Item tem=tomakeitemfromcharar(cstrret,id);
				//cout<<tem.name<<tem.cp<<endl;
				//printf("%s\n",cstrret);
		Py_Finalize();
		Itemgroup temgrp(tem,num);
		return temgrp;
	}	
}
void cashiermain(){

	List newlist(0,NULL);
	int id,num;
	int count=0;
	cout<< "enter id and number"<<endl;
	cin>>id>>num;
	while(id>-1){

		if(id==0){
			int opt;
			cout<<"press 0 to remove else 1"<<endl;
			cin>>opt;
			if(opt)
			{
				cout<<"enter index and reenter new number"<<endl;
				int ind;
				cin>>ind>>num;
				newlist.listedit_at_index(ind,num);
			}
			else{
					cout<<"enter what index to remove"<<endl;
					int ind;
					cin>>ind;
					newlist.listremove_at_index(ind);
			}
			cout<<"editting done"<<endl;
			cin>>id>>num;
			continue;
		}
		Itemgroup temgrp= makeitemgroupfromid(id,num);
		newlist.listadd(temgrp);
		cout<<"added"<<endl;
		cout<<newlist.grpar[count].id<<' '<<newlist.grpar[count].name<<' '<< newlist.grpar[count].num<<endl;
		cout<< "enter id and number"<<endl;
		cin>>id>>num;
		count++;

	}

}


