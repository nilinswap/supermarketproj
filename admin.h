
#include <queue>
#include <string>
#include <iostream>
#include "task.h"

using namespace std;


void commitqueue(queue <Task*> que){
}

int adminmain(){
	int option;//options over different tasks
	//queue <Task*> que;
	while(1){
		cin>>option;
		switch(option){
			case 2:{
			 			int option;//option over enque or commit
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
			 			//Task * newtask= new addtodb(tem,guest,option);
			 			//addtodb addtask (tem,guest,option);
			 			//newtask=&addtask;

			 			cout<<"do you want to immediately commit this change or enque it for final commit: enter 1 for enque and 2 for commit"<<endl;
			 			cin>>option;
			 			if(option==2){
			 				//newtask->committask();
			 				break;
			 			}
			 			else if(option==1){
			 				//que.push(newtask);
			 				break;
			 			}
			 			break;
			}
			 case 1:{
			 		//commitqueue(que);
					break; 		
			}
			case 0:{
			 		//commitqueue(que);
			 		return 1;
			}

			default:
			 	cout<<"default it is"<<endl;
		}
	}

	return 0;
}

