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