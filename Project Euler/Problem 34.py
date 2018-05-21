def factorial(x):  
    result = 1  
    for i in range(2, x + 1):  
        result *= i  
    return result  
sum=0
for i in range(10,2500001):
	x=0
	t=i
	while(t>0):
		s=t%10
		x+=factorial(s)
		t=t//10
	if x==i:
		print(x)
		sum+=x
print(sum)
