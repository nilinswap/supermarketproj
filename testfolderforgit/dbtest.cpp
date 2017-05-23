#include <stdio.h>
#include <conio.h>
#include <Python.h>

void func(){
	PyRun_SimpleString("import pymysql\nconn=pymysql.connect(host=\"localhost\",user=\"root\",passwd=\"dusty\",db=\"supmarproj\")\nc=conn.cursor()\nc.execute(\"INSERT INTO itemtable (name,cp,sp,wt,dis) VALUES (%s,%s,%s,%s,%s)\",(\"dummyitem2\",\"55\",\"35\",\"100\",\"0\"))\nconn.commit()\nc.close()\nconn.close()");
}
int main()
{
	PyObject* pInt;

	Py_Initialize();

	func();
	
	Py_Finalize();

	printf("\nPress any key to exit...\n");
	if(!getch()) getch();
	return 0;
}
// g++   embedtest.cpp -L/usr/include/python3.5m -lpython2.7
// g++   embedtest.cpp -I/usr/include/python3.5m -lpython3.5m