#include <iostream>
#include <string.h>
#include "item.h"
#include  "itemgroup.h"
#include "admin.h"
#include "list.h"
#include "cashier.h"
int main(){
	Item firstitem (7,"nameisname",65,55,30);
	firstitem.printwhole();
	cout<<"lets take a break\n";
	Itemgroup firstgrp (firstitem,5);
	firstgrp.printwhole();
	cout<<"lets take another break\n";
	cout<<firstitem.find_id()<<" "<<firstitem.find_name()<<" "<<firstitem.find_cp()<<endl;
	cout<<firstgrp.find_id()<<" "<<firstgrp.find_name()<<" "<<firstgrp.find_cp()<<" "<<firstgrp.find_grpprice()<<" "<<firstgrp.find_grpwt()<<" "<<firstgrp.find_num()<<endl;
	Py_Initialize();
					PyRun_SimpleString("import sys");		
    			PyRun_SimpleString("sys.path.append(\".\")");
    			PyRun_SimpleString("import pymysql");
				
	cashiermain();
	//IT IS VERY IMPORTANT to see that I cannot import a py-module twice in a single instance of C++ program.
	// THE REASON WHY I had to write above in main.
	adminmain();

			
				Py_Finalize();

}
