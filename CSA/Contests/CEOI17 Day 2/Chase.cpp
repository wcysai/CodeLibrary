/*************************************************************************
    > File Name: Chase.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-16 22:41:41
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,k,a[MAXN],ans,adj[MAXN];
vector<int> G[MAXN];
ll go[MAXN][105],arr[MAXN][105];
P barr[105][2],bgo[105][2];
void dfs(ll v,ll p)
{
    for(ll i=0;i<(int)G[v].size();i++)
    {
        if(G[v][i]==p) continue;
        dfs(G[v][i],v);
    }
    for(ll i=0;i<=k;i++) go[v][i]=0;
    for(ll i=0;i<=k;i++)
    {
        if(p==0) break;
        for(ll j=0;j<(int)G[v].size();j++)
        {
            ll to=G[v][j];
            if(to==p) continue;
            go[v][i]=max(go[v][i],go[to][i]);
            if(i>0) go[v][i]=max(go[v][i],go[to][i-1]+adj[v]-a[p]);
        }
    }
    for(ll i=0;i<=k;i++) arr[v][i]=(i==0)?0:adj[v];
    for(ll i=0;i<=k;i++)
    {
        for(ll j=0;j<(int)G[v].size();j++)
        {
            ll to=G[v][j];
            if(to==p) continue;
            arr[v][i]=max(arr[v][i],arr[to][i]);
            if(i>0) arr[v][i]=max(arr[v][i],arr[to][i-1]+adj[v]-a[to]);
        }
    }
    for(ll i=0;i<=k;i++) bgo[i][0]=bgo[i][1]=P(0,-1);
    for(ll i=0;i<=k;i++) barr[i][0]=barr[i][1]=P(i==0?0:adj[v],v);
    for(ll i=0;i<=k;i++)
    {
        for(ll j=0;j<(int)G[v].size();j++)
        {
            ll to=G[v][j];if(to==p) continue;
            ll adv=go[to][i];
            if(adv>=bgo[i][0].F) {bgo[i][1]=bgo[i][0]; bgo[i][0]=P(adv,to);}
            else if(adv>bgo[i][1].F) bgo[i][1]=P(adv,to);
            adv=arr[to][i];
            if(i>0) adv=max(adv,arr[to][i-1]+adj[v]-a[to]);
            if(adv>=barr[i][0].F) {barr[i][1]=barr[i][0]; barr[i][0]=P(adv,to);}
            else if(adv>barr[i][1].F) barr[i][1]=P(adv,to);
        }
    }
    for(ll i=0;i<=k;i++)
    {
        assert(barr[i][0].F>=barr[i][1].F);
        assert(bgo[i][0].F>=bgo[i][1].F);
        if(barr[i][0].S!=bgo[k-i][0].S) ans=max(ans,barr[i][0].F+bgo[k-i][0].F);
        else
        {
            ans=max(ans,barr[i][1].F+bgo[k-i][0].F);
            ans=max(ans,barr[i][0].F+bgo[k-i][1].F);
        }
    }
}
int main()
{
    scanf("%lld%lld",&n,&k);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(ll i=0;i<n-1;i++)
    {
        ll u,v;scanf("%lld%lld",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    for(ll i=1;i<=n;i++)
        for(ll j=0;j<(int)G[i].size();j++)
            adj[i]+=a[G[i][j]];
    ans=0;
    dfs(1,0);
    printf("%lld\n",ans);
    return 0;
}

