def passfun(input):
	fileo=open("impy/passad.txt","r");
	st=fileo.read()

	if st==input:
		return '1'
	else :
		return '0'
def passfunny(input):
	fileo=open("impy/passall.txt","r");
	st=fileo.read()
	
	if st==input:
		return '1'
	else :
		return '0'