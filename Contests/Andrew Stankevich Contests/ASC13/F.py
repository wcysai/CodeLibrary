import sys
sys.stdin=open('puzzle.in','r')
sys.stdout=open('puzzle.out','w')
a,b,c=map(int,input().split())
ans=0
s=1
for i in range(1,5000):
    if s>=a:
        break
    s*=2
    ans+=1
s=1
for j in range(1,5000):
    if s>=b:
        break
    s*=2
    ans+=1
s=1
for k in range(1,5000):
    if s>=c:
        break
    s*=2
    ans+=1
print(ans)
