import pymysql
def connection():
	conn=pymysql.connect(host="localhost",user="root",passwd="dusty",db="supmarproj")
	
	c=conn.cursor()
	return c,conn
def multiply(a,b):
	
    print(a,b)
    a=int(a);b=int(b)
    c = 0
    for i in range(0, a):
        c = c + b
    return str(c)
	
