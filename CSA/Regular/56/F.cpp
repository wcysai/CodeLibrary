#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF (1<<20)
#define INFF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll N,K,a[MAXN];
ll fst[MAXN][20];
vector<int> pos[MAXN];
P dp[MAXN];
P C(ll cost)
{
    dp[0]=P(0,0);
    for(ll i=1;i<=N;i++)
    {
        dp[i]=P(-INFF,0);
        ll cur=a[i];
        for(ll j=0;j<(int)pos[i].size();j++)
        {
            if(pos[i][j]==0) break;
            cur=cur|a[pos[i][j]];
            dp[i]=max(dp[i],P(cur+dp[pos[i][j]-1].F-cost,dp[pos[i][j]-1].S-1));
        }
    }
    return dp[N];
}
int main()
{
    scanf("%lld%lld",&N,&K);
    for(ll i=1;i<=N;i++) scanf("%lld",&a[i]);
    for(ll i=1;i<=N;i++)
    {
        for(ll j=0;j<20;j++) fst[i][j]=fst[i-1][j];
        pos[i].push_back(1);pos[i].push_back(i);
        for(ll j=0;j<20;j++) if(a[i]&(1<<j)) fst[i][j]=i; else pos[i].push_back(fst[i][j]);
        sort(pos[i].begin(),pos[i].end(),greater<>());
        pos[i].erase(unique(pos[i].begin(),pos[i].end()),pos[i].end());
    }
    ll l=-1,r=(1<<21);
    while(r-l>1)
    {
        ll mid=(l+r)/2;
        if(-C(mid).S<=K) r=mid; else l=mid;
    }
    P ans=C(r);
    //printf("%lld %lld %lld\n",l,ans.F,ans.S);
    printf("%lld\n",ans.F+K*r);
    return 0;
}



