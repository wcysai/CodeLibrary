import sys
sys.stdin=open('lottery.in','r')
sys.stdout=open('lottery.out','w')
def gcd(a,b):
    if b==0:
        return a;
    return gcd(b,a%b)

n=int(input())
str=input()
x=len(str)
cnt=[0]*27
for i in range(0,x):
    cnt[ord(str[i])-ord('A')]+=1
dp=[[0] * 100 for _ in range(100)]
comb=[[0]*100 for _ in range(100)]
comb[0][0]=1
for i in range(1,100):
    comb[i][0]=comb[i][i]=1;
    for j in range(1,i):
        comb[i][j]=comb[i-1][j-1]+comb[i-1][j]
dp[0][0]=1
for i in range(0,26):
    for j in range(0,n+1):
        if dp[i][j]==0:
            continue;
        if cnt[i]==0:
            dp[i+1][j]=dp[i][j]
            continue;
        rest=n-j;
        for k in range (cnt[i],rest+1):
            dp[i+1][j+k]=max(dp[i+1][j+k],dp[i][j]*comb[k][cnt[i]])
p=dp[26][n]
q=comb[n][x]
g=gcd(p,q)
p=p//g
q=q//g
print("%d/%d"%(p,q))
for i in range(0,27):
    for j in range(0,n+1):
        dp[i][j]=100000000000000000000000000000
dp[0][0]=1
for i in range(0,26):
    for j in range(0,n+1):
        if dp[i][j]==0:
            continue;
        if cnt[i]==0:
            dp[i+1][j]=dp[i][j]
            continue;
        rest=n-j;
        for k in range (cnt[i],rest+1):
            dp[i+1][j+k]=min(dp[i+1][j+k],dp[i][j]*comb[k][cnt[i]])
p=dp[26][n]
q=comb[n][x]
g=gcd(p,q)
p=p//g
q=q//g
print("%d/%d"%(p,q))
