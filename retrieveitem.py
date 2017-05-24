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
def retrieveitem(id):
	
	conn=pymysql.connect(host="localhost",user="root",passwd="dusty",db="supmarproj")
	
	c=conn.cursor()
	
	c.execute("select * from itemtable where id=%s",id)#here variable name must be same as that in database
	
	datalis=c.fetchall()

	datastrtup=[str(itm) for itm in datalis[0]]
	datastr=','.join(datastrtup)
	#print(datastr)
	conn.commit()
	c.close()
	conn.close()
	
	return datastr
#retrieveitem("18")