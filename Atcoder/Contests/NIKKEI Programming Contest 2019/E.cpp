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
int n,m,w[MAXN];
bool vise[MAXN],visv[MAXN],valid[MAXN];
struct edge
{
    int u,v,w,id;
}E[MAXN],E2[MAXN];
struct ee
{
    int to,w,id;
};
vector<ee> G[MAXN];
bool cmp(edge x,edge y)
{
    return x.w<=y.w;
}
int p[MAXN],r[MAXN];
ll sum[MAXN];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        r[i]=0;
        sum[i]=w[i];
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
    if(r[x]<r[y]) {p[x]=y; sum[y]+=sum[x];}
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
        sum[x]+=sum[y];
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
void dfs(int v,int w)
{
    if(visv[v]) return;
    for(auto e:G[v])
    {
        if(vise[e.id]) continue;
        if(visv[e.to]) continue;
        if(e.w>w) continue;
        vise[e.id]=true;
        dfs(e.to,w);
    }
    visv[v]=true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);
        E[i].id=i;
        int u=E[i].u,v=E[i].v,w=E[i].w;
        G[u].push_back((ee){v,w,i});G[v].push_back((ee){u,w,i});
    }
    memset(visv,false,sizeof(visv));
    memset(vise,false,sizeof(vise));
    memset(valid,true,sizeof(valid));
    sort(E,E+m,cmp);
    init(n);
    for(int i=0;i<m;i++)
    {
        unite(E[i].u,E[i].v);
        if(E[i].w>sum[find(E[i].u)]) valid[E[i].id]=false;
    }
    int ans=0;
    for(int i=m-1;i>=0;i--)
    {
        if(vise[E[i].id]) continue;
        if(!valid[E[i].id]) ans++; else dfs(E[i].u,E[i].w);
    }
    printf("%d\n",ans);
    return 0;
}

