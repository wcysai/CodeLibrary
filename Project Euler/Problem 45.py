from math import sqrt
def isTriangle(t):
	if((sqrt(8*t+1)-1)/2)%1==0:
		return True
def isPentagon(p):
	if((sqrt(24*p+1)+1)/6)%1==0:
		return True
h=144
while h:
	m=h*(2*h-1)
	if isTriangle(m) and isPentagon(m):
		print(m)
	else:
		h+=1