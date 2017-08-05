
#include <queue>
#include <string>
#include <iostream>
#include "task.h"
#include <stdlib.h>
using namespace std;



void commitqueue(queue <Task*> que){

	while(!que.empty())
	{
		que.front()->committask();
		que.pop();
	}
	cout<<"emptied queue"<<endl;
}
void changename(string idstr){


	char *cstrret;PyObject *strret, *mymod, *strfunc, *strargs;
    			//string idstr= ttostring <int>(id);//this function is defined in errands.h
						char idstri[50];//this three line operation is requiered for each attribute because 
						strncpy(idstri, idstr.c_str(), sizeof(idstri));//stupid Buildvalue only takes char* as argument
						idstri[sizeof(idstri) - 1] = 0;
				//cout<<idstr<<endl;
			
				//printf("%s\n",idstri);
				string newname;
				//cin>>newname;
				char newnamestri[50];
						strncpy(newnamestri, newname.c_str(), sizeof(newnamestri));
						newnamestri[sizeof(newnamestri) - 1] = 0;
							cout<<"are we here"<<endl;
				//mymod = PyImport_ImportModule("changedbcore");
				//strfunc = PyObject_GetAttrString(mymod, "changename");
					Py_Initialize();
					PyRun_SimpleString("import sys");		
    			PyRun_SimpleString("sys.path.append(\".\")");
						PyRun_SimpleString("import changedbcore");
						cout<<"are we here"<<endl;
						PyRun_SimpleString("changedbcore.changename()");
				cout<<"are we here"<<endl;
				Py_Finalize();
				//strargs = Py_BuildValue("(ss)",idstri,newnamestri);//here I was only able to pass strings as arguments
				//strargs = Py_BuildValue("sssss",par,"45","35","24","0");
				//strret = PyEval_CallObject(strfunc, strargs);
				//PyArg_Parse(strret, "s", &cstrret);
				//cout<<cstrret<<endl;
				//Item tem=tomakeitemfromcharar(cstrret,id);
}
int adminmain(){
	int option;//options over different tasks
	queue <Task*> que;
	while(1){
		cout<<"enter option\n";
		cout<<"\t2. add item to database"<<endl;
		cout<<"\t3. see database"<<endl;
		cout<<"\t4. ask database"<<endl;
		cout<<"\t5. edit product's data"<<endl;
		cout<<"\t1. commit queue"<<endl;
		cout<<"\t0. exit"<<endl; 
		cin>>option;
		system("clear");
		switch(option){
			case 2:{
			 			int opt;//option over enque or commit
			 			int id;
						string name;
						double cp;
						double sp;
						double wt;
						double dis; 
			 			cout<<"enter all data in order:name,cp,sp,wt,dis"<<endl;
			 			cin>>name;cin>>cp;cin>>sp;cin>>wt;cin>>dis;
			 			guestunion guest;guest.id=-1;//guest id -1 for no guest
			 			Item tem (id,name,cp,sp,wt,dis);
			 			Task * newtask= new addtodb(tem,guest,option);
			 			//addtodb addtask (tem,guest,option);
			 			//newtask=&addtask;

			 			cout<<"do you want to immediately commit this change or enque it for final commit: enter 1 for enque and 2 for commit"<<endl;
			 			
			 			cin>>opt;
			 			if(opt==2){
			 				newtask->committask();
			 				cout<<"added"<<endl;
			 				break;
			 			}
			 			else if(opt==1){
			 				que.push(newtask);

			 				cout<<que.back()->name<<endl;
			 				break;
			 			}
			 			break;
			}
			 case 1:{
			 		commitqueue(que);
					break; 		
			}
			case 0:{
			 		commitqueue(que);
			 		return 1;
			}
			case 5:{
				//char *cstrret;PyObject *strret, *mymod, *strfunc, *strargs;
    			string id;
    			cout<<"welcome to update, enter the id where you want to change"<<endl;
    			cin>>id;
    			int i=0;
    			switch(i){
    				case 0:
    					{
    						char c;
    						cout<<"want to update name? y or n"<<endl;
    						cin>>c;
    						if(c=='y'){
    										//cout<<"here";
    										changename(id);
    										cout<<"below change"<<endl;
    								  }
    						break;
    					}
    				case 1:
    					{
    						char c;
    						cout<<"want to update cp? y or n"<<endl;
    						cin>>c;
    						if(c=='y'){
    										//changecp(id);
    								  }
    						else
    							break;
    					}
    				case 2:
    					{
    						char c;
    						cout<<"want to update sp? y or n"<<endl;
    						cin>>c;
    						if(c=='y'){
    										//changesp(id);
    								  }
    						else
    							break;
    					}
    				case 3:
    					{
    						char c;
    						cout<<"want to update wt? y or n"<<endl;
    						cin>>c;
    						if(c=='y'){
    										//changewt(id);
    								  }
    						else
    							break;
    					}
    				case 4:
    					{
    						char c;
    						cout<<"want to update dis? y or n"<<endl;
    						cin>>c;
    						if(c=='y'){
    										//changedis(id);
    								  }
    						else
    							break;
    					}
    			}

			}

			default:
			 	cout<<"default it is"<<endl;
		}
	}

	return 0;
}

