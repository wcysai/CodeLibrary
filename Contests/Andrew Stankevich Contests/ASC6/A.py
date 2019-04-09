import sys
sys.stdin=open('brackets.in','r')
sys.stdout=open('brackets.out','w')
tot=0
dp=[[0]*100 for i in range (100)]
for i in range (0,51):
    dp[0][i]=1
for i in range (1,51):
    for j in range (1,51):
        for k in range (0,i):
            dp[i][j]+=dp[k][j-1]*dp[i-1-k][j]
while(True):
    tot+=1
    N,K=map(int,input().split())
    if not N:
        break
    print("Case %d: %d" % (tot,dp[N][K]-dp[N][K-1]))
    print()

