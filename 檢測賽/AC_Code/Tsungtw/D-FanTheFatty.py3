
ncase=int(input())
N=1
while ncase>0:
	ncase-=1
	buf=list()
	buf=input().split()
	a=1
	b=1
	print(N)
	if len(buf)==3:
		a=int(buf[1])
		b=int(buf[2])
		if buf[0]=='+':
			print(a+b)
		else:
			print(a-b)
	else:
		a=int(buf[0])
		b=int(buf[1])
		print(a+b)
	N+=1
