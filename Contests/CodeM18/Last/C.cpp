/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-07 20:00:32
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
int n,m,a[MAXN];
struct edge{int to,cost;};
vector<edge> G[MAXN];
vector<P> E;
int ans=1;
int color[MAXN],val[MAXN];
bool f=true;
int p[MAXN],r[MAXN];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
void dfs(int v,int now)
{
    color[v]=1;
    val[v]=now;
    if(!f) return;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].to,cost=G[v][i].cost;
        if(color[to]==1)
        {
            if((now+cost+val[to])&1)
            {
                f=false;
                return;
            }
        }
        else if(color[to]==0) dfs(to,(now+cost)&1);
    }
    color[v]=2;
}
int main()
{
    scanf("%d%d",&n,&m);
    init(n);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(w==-1) E.push_back(P(u,v));
        else
        {
            G[u].push_back((edge){v,w});
            G[v].push_back((edge){u,w});
            unite(u,v);
        }
    }
    memset(color,0,sizeof(color));
    for(int i=1;i<=n;i++)
    {
        if(color[i]==0)
        {
            dfs(i,0);
            if(!f)
            {
                puts("0");
                return 0;
            }
        }
    }
    for(int i=0;i<(int)E.size();i++)
    {
        int u=E[i].F,v=E[i].S;
        if(!same(u,v)) 
        {
            ans=ans*2%MOD;
            unite(u,v);
        }
    }
    printf("%d\n",ans);
    return 0;
}

