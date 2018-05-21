ans = 0
numer = 0
denom = 1
for i in range(1000):
	numer, denom = denom, denom * 2 + numer
	if len(str(numer + denom)) > len(str(denom)):
		ans+=1
print(str(ans))