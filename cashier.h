using namespace std;
//#include "errands.h"
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include <iomanip>
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
double displaylist(List listi){
	cout<<" list is\n"<<endl;
	int n=listi.numofgrps;
	double cpsum=0;
	int i;
	/*
	cout<<"  index\t"<<"id"<<"\t\t"<<"name"<<"\t\tnumber"<<"\tdiscount"<<"\tcp\n";
	cout<<"--------------------------------------------------------------\n";
	 
	for (i=0;i<n;i++)
	{	
		cpsum+=listi.grpar[i].cp*listi.grpar[i].num*(1-(listi.grpar[i].dis/100));
		cout<<" | "<<i+1<<"\t"<<listi.grpar[i].id<<"\t\t"<<listi.grpar[i].name<<"\t\t"<<listi.grpar[i].num<<"\t"<<listi.grpar[i].dis<<"\t"<<listi.grpar[i].cp<<"\n";
	}*/
	//line();
	cout<<setw(5)<<"index"<<setw(7)<<"id"<<setw(15)<<"name"
     <<setw(10)<<"number"<<setw(10)<<"discount"<<setw(10)<<"cp\n";
	cout<<"--------------------------------------------------------------\n";
	for(int i=0;i<n;i++)
	{
		cpsum+=listi.grpar[i].cp*listi.grpar[i].num*(1-(listi.grpar[i].dis/100));
	cout<<setw(5)<<i+1<<setw(7)<<listi.grpar[i].id<<setw(15)<<listi.grpar[i].name
     <<setw(10)<<listi.grpar[i].num<<setw(10)<<listi.grpar[i].dis<<setw(10)<<listi.grpar[i].cp<<endl;
	}
	
	cout<<"--------------------------------------------------------------\n";
	cout<<"Total\t"<<cpsum<<endl;
	return cpsum;
}

Itemgroup makeitemgroupfromid(int id,int num,PyObject*mymod,PyObject*strfunc){
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
		
    			//PyRun_SimpleString("import pymysql");
    			
    			//cout<<"hell"<<endl;
				char *cstrret;PyObject *strret;PyObject*strargs;
    			string idstr= ttostring <int>(id);//this function is defined in errands.h
						char idstri[50];//this three line operation is requiered for each attribute because 
						strncpy(idstri, idstr.c_str(), sizeof(idstri));//stupid Buildvalue only takes char* as argument
						idstri[sizeof(idstri) - 1] = 0;
				//cout<<idstr<<endl;
			
				//printf("%s\n",idstri);
				
				strargs = Py_BuildValue("(s)",idstri);//here I was only able to pass strings as arguments
				//strargs = Py_BuildValue("sssss",par,"45","35","24","0");
				strret = PyEval_CallObject(strfunc, strargs);
				PyArg_Parse(strret, "s", &cstrret);
				//cout<<cstrret<<endl;
				Item tem=tomakeitemfromcharar(cstrret,id);
				//cout<<tem.name<<tem.cp<<endl;
				//printf("%s\n",cstrret);
				
		Itemgroup temgrp(tem,num);
		return temgrp;
	}	
}
void cashiermain(){
	//cout<<"here";
	List newlist(0,NULL);
	int id,num;
	int count=0;
			//Py_Initialize();

				PyObject *strret, *mymod, *strfunc;
				
				//PyRun_SimpleString("import sys");
    			//PyRun_SimpleString("sys.path.append(\".\")");
				//PyRun_SimpleString("import pymysql");    			
    			mymod = PyImport_ImportModule("retrieveitem");
				strfunc = PyObject_GetAttrString(mymod, "retrieveitem");
	cout<< "enter id and number"<<endl;
	cin>>id>>num;
	system("clear");
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
				system("clear");
				newlist.listedit_at_index(ind-1,num);
			}
			else{
					cout<<"enter what index to remove"<<endl;
					int ind;
					cin>>ind;
					system("clear");
					newlist.listremove_at_index(ind-1);
			}
			cout<<"editting done"<<endl;
			displaylist(newlist);
			cout<< "enter id and number"<<endl;
			cin>>id>>num;
			system("clear");
			continue;
		}
		Itemgroup temgrp= makeitemgroupfromid(id,num,mymod,strfunc);
		newlist.listadd(temgrp);
		cout<<"added"<<endl;
		//cout<<newlist.grpar[count].id<<' '<<newlist.grpar[count].name<<' '<< newlist.grpar[count].num<<endl;
		displaylist(newlist);
		cout<< "enter id and number"<<endl;
		cin>>id>>num;
		if(id)
			system("clear");
		count++;

	}
	cout<<endl<<"so you say final bill is "<<endl;
	double total=displaylist(newlist);
	cout<<"out of cashiermain"<<endl;
			//	Py_Finalize();

}



