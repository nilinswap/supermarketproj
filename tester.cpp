#include <iostream>
#include <string.h>
#include "item.h"
#include "itemgroup.h"
#include "list.h"

int main(){
	Item firstitem (7,"nameisname",65,55,30);
	firstitem.printwhole();
	cout<<"lets take a break\n";
	Itemgroup firstgrp (firstitem,5);
	firstgrp.printwhole();
	cout<<"lets take another break\n";
	cout<<firstitem.find_id()<<" "<<firstitem.find_name()<<" "<<firstitem.find_cp()<<endl;
	cout<<firstgrp.find_id()<<" "<<firstgrp.find_name()<<" "<<firstgrp.find_cp()<<" "<<firstgrp.find_grpprice()<<" "<<firstgrp.find_grpwt()<<" "<<firstgrp.find_num()<<endl;


}
