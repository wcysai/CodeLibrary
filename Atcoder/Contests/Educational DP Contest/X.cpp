#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define MAXW 20005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n;
ll dp[MAXN][MAXW];
struct block
{
    ll w,s,v;
}a[MAXN];
bool cmp(block p,block q)
{
    return q.s-p.w>p.s-q.w;
}
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i].w,&a[i].s,&a[i].v);
    sort(a+1,a+n+1,cmp);
    for(ll i=0;i<=n;i++) for(ll j=0;j<=20000;j++) dp[i][j]=-INF;
    dp[0][0]=0;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=0;j<=20000;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=a[i].w&&a[i].s>=j-a[i].w) dp[i][j]=max(dp[i][j],dp[i-1][j-a[i].w]+a[i].v);
        }
    }
    ll ans=0;
    for(ll j=0;j<=20000;j++) ans=max(ans,dp[n][j]);
    printf("%lld\n",ans);
    return 0;
}

