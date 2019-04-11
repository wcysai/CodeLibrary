import sys
sys.stdin=open('toral.in','r')
sys.stdout=open('toral.out','w')
def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)

a,b=map(int,input().split())
print(gcd(a,b))

