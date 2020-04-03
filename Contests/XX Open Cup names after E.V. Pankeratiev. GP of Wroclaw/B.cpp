#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,m;
int p[MAXN],r[MAXN];
bool vis[MAXN];
int mark[MAXN],u[MAXN],v[MAXN],x[MAXN];
vector<P> G[MAXN];
void add_edge(int u,int v,int id)
{
    G[u].push_back(P(v,id));
    G[v].push_back(P(u,id));
}
void init(int n)
{
    for(int i=0;i<n;i++)
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
void dfs(int v,int p,int faid)
{
    vis[v]=true;
    for(auto e:G[v])
    {
        int to=e.F,id=e.S;
        if(to==p) continue;
        dfs(to,v,id);
    }
    if(mark[v]&&faid) 
    {
        x[faid]=1;
        mark[v]^=1; mark[p]^=1;
    }
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) G[i].clear();
        init(n);
        for(int i=1;i<=n;i++) mark[i]=0,vis[i]=false;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&u[i],&v[i],&x[i]);
            if(x[i]) {mark[u[i]]^=1; mark[v[i]]^=1;}
            else
            {
                if(!same(u[i],v[i]))
                {
                    add_edge(u[i],v[i],i);
                    unite(u[i],v[i]);
                }
            }
        }
        for(int i=1;i<=n;i++) if(!vis[i]) dfs(i,0,0);
        bool f=true;
        for(int i=1;i<=n;i++) if(mark[i]) f=false;
        if(!f) puts("NIE");
        else
        {
            puts("TAK");
            for(int i=1;i<=m;i++) printf("%d\n",x[i]);
        }
    }
    return 0;
}