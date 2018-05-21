def fac(x):
	if(x==0):
		return 1
	else:
		return x*fac(x-1)

def gcd(a,b):
	if(b==0):
		return a
	else:
		return gcd(b,a%b)

def solve(m,n):
	ret=0
	for i in range(1,n+1):
		x=gcd(i,n)
		ret+=fac(x*m)/(fac(x)**m)
	return ret/(n*m)

ans=0
for i in range(2,10000000):
	if(solve(i,1)>1000000000000000):
		break
	for j in range(1,100000):
		if(solve(i,j)>1000000000000000):
			break
		ans+=solve(i,j)

print(ans)
