//#include <Python.h>
#include <string.h>
#include <iostream>
#include "errands.h"
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>
using namespace std;
#include "item.h"
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
int main(){
	/*char ar[]="this_is_a_test_string";
	std::stringstream test(ar);
	std::string segment;
	std::vector <std::string> seglist;

	while(std::getline(test, segment, '_'))
	{
	   seglist.push_back(segment);
	}
	cout<<seglist.size()<<endl;
    // Iterate and print values of vector
    for(int i=0;i< seglist.size();i++) {
        std::cout << seglist[i] << '\n';
        
    }
    double db;
    string stri;
    stri="74";
    db=::atof(stri.c_str());
    cout<<db+1;*/
	char charar[]="18,item,34.0,32.0,12.0,23.0";
	Item tem=tomakeitemfromcharar(charar,18);
	cout<<tem.name<<endl;
    int i;
    line();
    cin>>i;
    system("clear");
    cout<<"here"<<endl;

}