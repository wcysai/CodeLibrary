import sys
sys.stdin=open('hex.in','r')
sys.stdout=open('hex.out','w')
n=int(input())
ans=1
for i in range (1,n+1):
    for j in range (1,n+1):
        for k in range (1,n+1):
            ans*=(i+j+k-1)
for i in range (1,n+1):
    for j in range (1,n+1):
        for k in range (1,n+1):
            ans//=(i+j+k-2)
print(ans)
