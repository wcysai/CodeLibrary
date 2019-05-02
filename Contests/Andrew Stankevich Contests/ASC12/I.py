import sys
sys.stdin=open('regular.in','r')
sys.stdout=open('regular.out','w')
n=int(input())
dp=[[[0] * 100 for _ in range(100)] for _ in range(100)]
for i in range(0,100):
    for j in range(0,100):
        for k in range(0,100):
            dp[i][j][k]=0
dp[0][0][0]=1
for i in range(0,61):
    for j in range(0,61):
        for k in range(0,61):
            dp[i+1][j][k]+=dp[i][j][k]
            if j<i:
                dp[i][j+1][k]+=dp[i][j][k]
            if k<j and k<i:
                dp[i][j][k+1]+=dp[i][j][k]
print(dp[n][n][n])
