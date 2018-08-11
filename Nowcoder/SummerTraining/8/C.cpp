/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-11 16:03:28
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,sz[MAXN],ans;
int f[MAXN][2];
int g[MAXN][2];
vector<int> G[MAXN];
int add(int x,int y) {x+=y; return x>=MOD?x-MOD:x;}
int pow_mod(int a,int i,int m)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%m;
        a=1LL*a*a%m;
        i>>=1;
    }
    return s;
}
void dfs(int v,int p)
{
    sz[v]=1;
    f[v][0]=0;f[v][1]=1;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        dfs(to,v);
        sz[v]+=sz[to];
        f[v][0]=add(f[v][0],add(f[to][0],f[to][1]));
        f[v][1]=1LL*f[v][1]*(f[to][1]+1)%MOD;
    }
}
void dfs2(int v,int p)
{
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        g[to][0]=(g[v][0]+g[v][1]+f[v][0]-(f[to][0]+f[to][1])+2LL*MOD)%MOD;
        g[to][1]=1LL*(g[v][1]+1)*f[v][1]%MOD*pow_mod(f[to][1]+1,MOD-2,MOD)%MOD;
        dfs2(to,v);
    }
}
void dfs3(int v,int p)
{
    int sum=0;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        sum=(sum+1LL*sz[to]*(sz[to]+1)/2)%(MOD-1);
    }
    sum=(sum+1LL*(n-sz[v])*(n-sz[v]+1)/2)%(MOD-1);
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        int SZ=n-sz[to];
        int path1=(1LL*SZ*(SZ+1)/2)%(MOD-1);
        int path2=((sum-1LL*sz[to]*(sz[to]+1)/2)%(MOD-1)+(MOD-1))%(MOD-1);
        int res=(pow_mod(2,path1,MOD)-pow_mod(2,path2,MOD)+MOD)%MOD;
        int scc=f[to][1];
        printf("%d %d %d\n",v,res,scc);
        ans=(ans+1LL*res*scc)%MOD;
    }
    if(v!=1)
    {
        int SZ=sz[v];
        int path1=(1LL*SZ*(SZ+1)/2)%(MOD-1);
        int path2=((sum-1LL*(n-sz[v])*(n-sz[v]+1)/2)%(MOD-1)+(MOD-1))%(MOD-1);
        int res=(pow_mod(2,path1,MOD)-pow_mod(2,path2,MOD)+MOD)%MOD;
        int scc=g[v][1];
        ans=(ans+1LL*res*scc)%MOD;
        printf("%d %d %d\n",v,res,scc);
    }
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        dfs3(to,v);
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
    dfs(1,0);dfs2(1,0);
    for(int i=1;i<=n;i++)
    {
        printf("%d: %d %d %d %d\n",i,f[i][0],f[i][1],g[i][0],g[i][1]);
    }
    ans=0;
    dfs3(1,0);
    printf("%d\n",ans);
    return 0;
}

