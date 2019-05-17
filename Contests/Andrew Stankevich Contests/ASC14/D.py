import sys
sys.stdin=open('merge.in','r')
n=int(input())
dp=[0]*250
cnt=[0]*250
dp[1]=0
cnt[1]=1
comb=[[0]*250 for i in range(250)]
opt=[[0]*250 for i in range(250)]
comb[0][0]=1
opt[1][1]=1
for i in range(2,205):
    lb=(i+1)//2
    rb=i//2
    for j in range(1,lb):
        opt[i][j]=opt[lb][j]
    opt[i][lb]=i-1
    for j in range(1,rb):
        opt[i][lb+j]=opt[rb][j]+lb-1
    opt[i][i]=i
for i in range(1,205):
    comb[i][0]=1
    comb[i][i]=1
    for j in range(1,i):
        comb[i][j]=comb[i-1][j-1]+comb[i-1][j]
for i in range(2,205):
    dp[i]=dp[i//2]+dp[(i+1)//2]+i-1
for i in range(2,205):
    cnt[i]=cnt[i//2]*cnt[(i+1)//2]*2*comb[i-2][(i+1)//2-1]
l=(n+1)//2
with  open("merge.out", "w") as fd:
    fd.write("%d\n" % dp[n])
    for i in range(1,n+1): fd.write("%d "%(opt[n][i]))
    fd.write("\n")
    fd.write("%d\n" %(cnt[n]))


