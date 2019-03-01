#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k;
int u[MAXM],v[MAXM];
int f[MAXN],g[MAXN];
int dep[MAXN],fa[MAXN];
bool vis[MAXN];
vector<int> G[MAXN];
int ans=0;
void init(int n,int *p)
{
    for(int i=1;i<=n;i++) p[i]=i;
}
int find(int x,int *p)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x],p);
}
void unite(int x,int y,int *p)
{
    x=find(x,p);
    y=find(y,p);
    if(x==y) return;
    p[x]=y;
}
bool same(int x,int y,int *p)
{
    x=find(x,p);
    y=find(y,p);
    if(x==y) return true; else return false;
}
void dfs(int v,int p,int d)
{
    dep[v]=d;fa[v]=p;vis[v]=true;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v,d+1);
    }
}
int main()
{
    freopen("bridges.in","r",stdin);
    freopen("bridges.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d%d",&u[i],&v[i]);
    scanf("%d",&k);
    for(int i=m+1;i<=m+k;i++) scanf("%d%d",&u[i],&v[i]);
    init(n,f);init(n,g);
    for(int i=1;i<=m+k;i++)
    {
        if(same(u[i],v[i],f)) continue;
        else 
        {
            unite(u[i],v[i],f);
            G[u[i]].push_back(v[i]);
            G[v[i]].push_back(u[i]);
        }
    }
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i,0,0);
    init(n,f);
    for(int i=1;i<=m+k;i++)
    {
        if(!same(u[i],v[i],f)) {ans++; unite(u[i],v[i],f);}
        else
        {
            u[i]=find(u[i],g);v[i]=find(v[i],g);
            while(u[i]!=v[i])
            {
                if(dep[u[i]]<dep[v[i]]) swap(u[i],v[i]);
                unite(u[i],fa[u[i]],g); u[i]=find(u[i],g); ans--;
            }
        }
        if(i>m) printf("%d\n",ans);
    }
    return 0;
}

