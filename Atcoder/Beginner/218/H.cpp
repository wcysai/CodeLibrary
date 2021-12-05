#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 2000005
#define INF 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,r,a[MAXN];
pair<ll,int> dp[MAXN][2];
ll solve(ll lambda)
{
    dp[1][0]=make_pair(0,0); dp[1][1]=make_pair(-lambda,1);
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<2;j++)
        {
            dp[i][j]=make_pair(-INF,0);
            for(int k=0;k<2;k++)
            {
                auto p=dp[i-1][k];
                if(j!=k) p.F+=a[i-1];
                if(j==1) {p.F-=lambda; p.S++;}
                dp[i][j]=max(dp[i][j],p);
            }
        }
    }
    return max(dp[n][0],dp[n][1]).S;
}
int main()
{
    scanf("%d%d",&n,&r);
    for(int i=1;i<=n-1;i++) scanf("%d",&a[i]);
    r=min(r,n-r);
    ll lb=0,rb=1000000000LL*n;
    while(rb-lb>1)
    {
        ll mid=(lb+rb)/2;
        if(solve(mid)>=r) lb=mid; else rb=mid;
    }
    ll num=solve(lb);
    printf("%lld\n",max(dp[n][0],dp[n][1]).F+lb*r);
    return 0;
}