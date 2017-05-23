def rstring(s):
	i = len(s)-1
	t = ''
	while(i > -1):
		t += s[i]
		i -= 1
	return t
def rnum(i):
	i=int(i)

	return str(1.0/i)
def rlist(l):
	l.reverse()
	return l
def rdict(d):
	e = {}
	for k in d.keys():
		e[d[k]] = k
	return e
"""
def multiply(a,b):
	a=int(a)
	b=int(b)
    print("Will compute", a, "times", b)
    c = 0
    for i in range(0, a):
        c = c + b
    return str(c)"""
