#include<iostream>
using namespace std;
#include "testchild.h"
int main(){
	hello();
	cout<<testo.i<<" "<<testo.j;
	testclass obj(3,4);
	cout<<endl<<obj.i<<" "<<obj.j<<endl;
	return 0;
	}
