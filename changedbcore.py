#addtodbcore.py
import pymysql
def connection():
	conn=pymysql.connect(host="localhost",user="root",passwd="dusty",db="supmarproj")
	c=conn.cursor()
	return c,conn
"""def addtodbcore(name,cp,sp,wt,dis):
	c,conn=connection()
	print("something")
	c.execute("INSERT INTO itemtable (name,cp,sp,wt,dis) VALUES (%s,%f,%f,%f,%f);",(name,cp,sp,wt,dis))#here variable name must be same as that in database
	conn.commit()
	c.close()
	conn.close()"""
def changename():
	
	conn=pymysql.connect(host="localhost",user="root",passwd="dusty",db="supmarproj")
	
	c=conn.cursor()
	print("anything");
	ids=input("reenter id\n")
	newname=input("enter new name\n");
	#i=int(ids)
	#print(type(i))
	c.execute("update itemtable set name='%s'  where id=%s"%( newname ,ids) )#here variable name must be same as that in database
	
	
	#print(datastr)
	conn.commit()
	c.close()
	conn.close()
changename()	
	
#retrieveitem("18")
