import re

validformat = "[1-9][0-9]*[\+\-\*\/][1-9][0-9]*=[1-9][0-9]*$"

symbol = "[\+\-\*\/\=]"

character = "+-*/=0123456789"

def check(x):
	if re.match(validformat,x) is None:
		return False
	a,b,c=re.split(symbol,S)
	return (int(a)<=10 ** 9) and (int(b)<=10 ** 9) and (int(c)<=10 ** 9)  

def get(S):
	for a in character:
		for b in character:
			for i in range(len(S)):
				for j in range(i):
					if check(S[0:j]+a+S[j+1:i]+b+S[i+1:]):
						ret=S[0:j]+a+S[j+1:i]+b+S[i+1:]
						a,b=ret.split('=')
						if eval(a)==eval(b):
							return ret
	return ""

S=input()
if check(S):
	a,b=S.split('=')
	if eval(a)==eval(b):
		print("Correct")
	else:
		ret=get(S)
		if ret=="":
			print("Math Error")
		else:
			print("Typo: {} instead of {}".format(S, ret))
else:
	print("Format Error")