/*************************************************************************
    > File Name: 4316.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-27 00:29:15
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
typedef pair<int,int> P;
int n,m;
bool vis[MAXN];
vector<int> G[MAXN];
int tot,t[MAXN],top[MAXN],bottom[MAXN],fa[MAXN];
int f0[MAXN],f1[MAXN],g0[MAXN],g1[MAXN];
void add(int &a,int b) {a+=b;}
void st(int u,int v)
{
    int vet=u;
    while(u!=v) {bottom[u]=vet; top[u]=v; u=fa[u];}
}
void dfs(int v,int p)
{
    t[v]=++tot;
    fa[v]=p;
    vis[v]=true;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        if(vis[to]) {if(t[v]>t[to]) st(v,to);} else dfs(to,v);
    }
}
//dp[v][0/1][0/1]:
//at subtree of v
//choose v or not
//choose the bottom vertex or not
void dfs2(int v,int p)
{
    vis[v]=true;
    f1[v]=1;
    if(v!=bottom[v]) g1[v]=1;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(vis[to]) continue;
        dfs2(to,v);
        if(bottom[to]!=bottom[v]&&top[to]!=v) {add(g0[v],f1[to]); add(g1[v],g0[to]);}
        else {add(g0[v],g1[to]); add(g1[v],g0[to]);}
        if(top[to]!=v) {add(f0[v],f1[to]); add(f1[v],f0[to]);}
        else {add(f0[v],f1[to]); add(f1[v],g0[to]);}
    }
    f1[v]=max(f1[v],f0[v]);
    g1[v]=max(g1[v],g0[v]);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++) top[i]=bottom[i]=-1;
    dfs(1,0);
    memset(vis,false,sizeof(vis));
    dfs2(1,0);
    printf("%d\n",n-f1[1]);
    return 0;
}
