import sys
sys.stdin=open('parallel.in','r')
sys.stdout=open('parallel.out','w')
n,m,k,p=map(int,input().split())
bs=[[0]*26 for i in range(26)]
str=input().split(' ')
for i in range(0,p):
    x=ord(str[i][0])-ord("A")
    y=ord(str[i][1])-ord("A")
    bs[x][y]=bs[y][x]=1

str=input()
d=[0]*105
dp1=[0]*105
dp2=[0]*105
fact=[0]*105
comb=[[0]*30 for i in range (30)]
comb[0][0]=1
for i in range (1,30):
    comb[i][0]=comb[i][i]=1
    for j in range (1,i):
        comb[i][j]=comb[i-1][j-1]+comb[i-1][j]
fact[0]=1
for i in range(1,30):
    fact[i]=fact[i-1]*i


rts=list(str)
rts.reverse()
rts="".join(rts)
for i in range (0,n):
    has=[0]*26
    for j in range (i+1,n+1):
        if j-i>k:
            break
        x=ord(rts[j-1])-ord("A")
        flag=True
        for l in range (0,26):
            if bs[x][l]==0 and has[l]==1:
                flag=False
        if flag==False:
            break
        has[x]=1
        if d[j]!=0:
            continue
        else:
            d[j]=d[i]+1
print(d[n])

dp1[0]=1
dp2[0]=1
for i in range (0,n):
    has=[0]*26
    cnt=0
    for j in range (i+1,n+1):
        if j-i>k:
            break
        if d[n-j]<d[n-i]-1:
            break
        x=ord(str[j-1])-ord("A")
        flag=True
        for l in range (0,26):
            if bs[x][l]==0 and has[l]==1:
                flag=False
        if flag==False:
            break
        has[x]=1
        cnt+=1
        if d[n-j]>d[n-i]-1:
            continue
        dp1[j]+=dp1[i]
        dp2[j]+=comb[k][cnt]*fact[cnt]*dp2[i]
print(dp1[n])
print(dp2[n])




