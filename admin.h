
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

			default:
			 	cout<<"default it is"<<endl;
		}
	}

	return 0;
}

