/*************************************************************************
    > File Name: 1509.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-27 23:10:55
 ************************************************************************/

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
struct edge{ll to,cost;};
vector<edge> G[MAXN];
ll n,m,d[2][MAXN],fa[MAXN],node,ans;
void dfs(ll type,ll v,ll p)
{
    fa[v]=p;
    if(d[type][v]>ans) {ans=d[type][v]; node=v;}
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i].to;
        if(to==p) continue;
        d[type][to]=d[type][v]+G[v][i].cost;dfs(type,to,v);
    }
}
int main()
{
    scanf("%lld%lld",&n,&m);
    for(ll i=0;i<m;i++)
    {
        ll u,v,c;
        scanf("%lld%lld%lld",&u,&v,&c);
        G[u].push_back((edge){v,c});G[v].push_back((edge){u,c});
    }
    d[0][1]=0;ans=0;
    dfs(0,1,0);ll root=node;
    d[0][root]=0;ans=0;
    dfs(0,root,0);ll len=d[0][node];
    d[1][node]=0;
    dfs(1,node,0);
    ans=0;
    for(ll i=1;i<=n;i++) ans=max(ans,min(d[0][i],d[1][i]));
    printf("%lld\n",ans+len);
    return 0;
}

