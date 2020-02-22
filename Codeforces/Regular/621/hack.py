#!/bin/python3
from random import*
seed(279120700205466888)
n=5000
m=5000
print(n,m)
[*x]=range(1,n+1)
shuffle(x)
print(*x)
shuffle(x)
for a in x: print(a, 1)