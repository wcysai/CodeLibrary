from math import *
from decimal import Decimal, getcontext
import sys

getcontext().prec=150
iter=4000

def atan(x):
    s=x
    last=Decimal(-2.0)
    num=x
    i=0
    while s!=last:
        last=s
        i=i+1
        num*=x*x*-1
        s+=num/(2*i+1)
    return s

def BBP():
    pi=Decimal(0.0)
    num=Decimal(1.0)
    for i in range(iter):
        pi+=Decimal(4.0)/Decimal(8*i+1)/num
        pi-=Decimal(2.0)/Decimal(8*i+4)/num
        pi-=Decimal(1.0)/Decimal(8*i+5)/num
        pi-=Decimal(1.0)/Decimal(8*i+6)/num
        num=num*Decimal(16.0)
    return pi

PI=BBP() #PI/4=4arctan(1/5)-arctan(1/239)

sys.stdin=open('gsm.in','r')
sys.stdout=open('gsm.out','w')

H,R=list(map(int,input().split()))

H,R=Decimal(H),Decimal(R)
circle=PI*R*R
hexagon=H*H*Decimal(3).sqrt()*3/2
if R>=H:
    print(Decimal(1.0))
elif 4*R*R<=3*H*H:
    print(circle/hexagon)
else:
    sqrcosa=(H/R)**2*3/4
    B=2*atan((1/sqrcosa-1).sqrt())
    sinB=(1-(2*sqrcosa-1)**2).sqrt()
    print((circle-3*R*R*(B-sinB))/hexagon)

