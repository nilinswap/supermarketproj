#addtodbcore.py
import pymysql
def connection():
	conn=pymysql.connect(host="localhost",user="root",passwd="dusty",db="supmarproj")
	#print("hello")
	c=conn.cursor()
	return c,conn
"""def addtodbcore(name,cp,sp,wt,dis):
	

	c,conn=connection()

	c.execute("INSERT INTO itemtable (name,cp,sp,wt,dis) VALUES (%s,%s,%s,%s,%s);",(name,cp,sp,wt,dis))#here variable name must be same as that in database
	datalis=c.fetchall()
	print(datalis)
	conn.commit()
	c.close()
	conn.close()
	
def multiply(a,b):
	
    print(a,b)
    a=int(a);b=int(b)
    c = 0
    for i in range(0, a):
        c = c + b
    return str(c)"""
def addtodbcore(name,cp,sp,wt,dis):
	conn=pymysql.connect(host="localhost",user="root",passwd="dusty",db="supmarproj")
	print("hello")
	c=conn.cursor()
	print(type(cp))
	c.execute("INSERT INTO itemtable (name,cp,sp,wt,dis) VALUES (%s,%s,%s,%s,%s)",(name,cp,sp,wt,dis))#here variable name must be same as that in database
	print("here below insert")
	conn.commit()
	c.close()
	conn.close()
#addtodbcore("helloitem","45","35","24","0")