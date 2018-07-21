/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-19 01:36:16
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
int n,tot,cnt[MAXN],sz[MAXN],st[MAXN],ed[MAXN],rev[MAXN],dep[MAXN],ans[MAXN],maxi[MAXN],save[MAXN];
vector<int> G[MAXN];
void dfs(int v,int p,int d)
{
    st[v]=++tot;rev[tot]=v;dep[v]=d;
    sz[v]=1;
    for(int i=0;i<(int)G[v].size();i++)
    {
        if(G[v][i]==p) continue;
        dfs(G[v][i],v,d+1);
        sz[v]+=sz[G[v][i]];
    }
    ed[v]=tot;
}
void dfs2(int v,int p,bool keep)
{
    int mx=-1,wson=-1,t=-INF,id=-1;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        if(sz[to]>mx) {mx=sz[to]; wson=to;}
    }
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p||to==wson) continue;
        dfs2(to,v,0);
    }
    if(wson!=-1) {dfs2(wson,v,1);t=maxi[wson];id=save[wson];}
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p||to==wson) continue;
        for(int j=st[to];j<=ed[to];j++)
        {
            int q=dep[rev[j]];
            cnt[q]++;
            if(cnt[q]>t||(cnt[q]==t&&q<id)) {t=cnt[q]; id=q;}
        }
    }
    int q=dep[v];
    cnt[q]++;
    if(cnt[q]>t||(cnt[q]==t&&q<id)) {t=cnt[q];id=q;}
    ans[v]=id-dep[v];
    maxi[v]=t;save[v]=id;
    if(!keep)
    {
        for(int j=st[v];j<=ed[v];j++)
        {
            int q=dep[rev[j]];
            cnt[q]--;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    dfs(1,0,0);
    dfs2(1,0,1);
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}

