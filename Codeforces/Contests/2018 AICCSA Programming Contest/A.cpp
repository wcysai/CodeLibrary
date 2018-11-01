/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-01 22:13:34
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll T,n,root,u;
bool f;
ll sz[MAXN],cnt[MAXN],cnt2[MAXN];
vector<ll> G[MAXN];
P getroot(ll v,ll p,ll t)//search_centroid
{
    P res=P(INT_MAX,-1);
	ll m=0;
    sz[v]=1;
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p) continue;
        res=min(res,getroot(to,v,t));
        m=max(m,sz[to]);
        sz[v]+=sz[to];
    }
    m=max(m,t-sz[v]);
    res=min(res,P(m,v));
    return res;
}
void dfs(ll v,ll p,ll dep)
{
    sz[v]=1,cnt[dep]++;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v,dep+1);sz[v]+=sz[to];
    }
    if(v!=root&&sz[v]>=n/2) {f=true; u=v;}
}
void dfs2(ll v,ll p,ll dep)
{
    cnt2[dep]++;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs2(to,v,dep+1);
    }
}
int main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        for(ll i=1;i<=n;i++) G[i].clear();
        for(ll i=0;i<=n;i++) cnt[i]=cnt2[i]=0;
        for(ll i=2;i<=n;i++)
        {
            ll x;scanf("%lld",&x);
            G[i].push_back(x);G[x].push_back(i);
        }
        root=getroot(1,0,n).S;
        f=false;
        dfs(root,0,0);
        ll ans=0,cur=0;
        for(ll i=0;i<=n;i++)
        {
            ans+=cnt[i]*(n-cur-1);
            cur+=cnt[i];
        }
        if(n%2==0&&f)
        {
            dfs2(u,root,1);
            for(ll i=1;i<=n;i++) ans-=cnt2[i]*(cnt[i]-cnt2[i]+cnt[i-1]-cnt2[i-1]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

