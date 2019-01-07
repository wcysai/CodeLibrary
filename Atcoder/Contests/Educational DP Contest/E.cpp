#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define MAXV 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,W,w[MAXN],v[MAXN];
ll dp[MAXN][MAXV];
int main()
{
    scanf("%lld%lld",&n,&W);
    ll s=0;
    for(ll i=1;i<=n;i++) 
    {
        scanf("%lld%lld",&w[i],&v[i]);
        s+=v[i];
    }
    for(ll i=0;i<=n;i++)
        for(ll j=0;j<=s;j++)
            dp[i][j]=INF;
    dp[0][0]=0;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=0;j<=s;j++)
        {
            if(j<v[i]) dp[i][j]=dp[i-1][j];
            else dp[i][j]=min(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
        }
    }
    for(ll j=s;j>=0;j--) if(dp[n][j]<=W) {printf("%lld\n",j); return 0;}
    return 0;
}

