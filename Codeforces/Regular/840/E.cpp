#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int p,n,k,a[MAXN];
int tri[1005];
int dp[MAXN];
int main()
{
    for(int i=2;i<=1000;i++) tri[i]=i*(i-1)/2;
    scanf("%d",&p);
    dp[0]=0;
    for(int i=1;i<=200000;i++)
    {
        dp[i]=INF;
        for(int j=2;tri[j]<=i;j++)
            dp[i]=min(dp[i],dp[i-tri[j]]+j);
    }
    printf("%d %d\n",dp[p],dp[p]*(dp[p]-1)/2-p);
    return 0;
}

