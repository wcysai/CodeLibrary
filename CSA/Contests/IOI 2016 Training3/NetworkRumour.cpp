#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 13
#define MOD 1000000007
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N,a[MAXN][MAXN],dp[MAXN][(1<<MAXN)];
int solve(int root,int mask)
{
    if(mask==(1<<root)) return 0;
    if(dp[root][mask]!=-1) return dp[root][mask];
    dp[root][mask]=INF;
    int submask=mask;
    do
    {
        if(submask&(1<<root)) {submask=(submask-1)&mask; continue;}
        if(submask==0) break;
        for(int i=0;i<N;i++)
            if(submask&(1<<i))
                dp[root][mask]=min(dp[root][mask],a[root][i]+max(solve(i,submask),solve(root,mask^submask)));
        submask=(submask-1)&mask;
    }while(submask!=mask);
    return dp[root][mask];
}
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d",&a[i][j]);
    memset(dp,-1,sizeof(dp));
    printf("%d\n",solve(0,(1<<N)-1));
    return 0;
}
