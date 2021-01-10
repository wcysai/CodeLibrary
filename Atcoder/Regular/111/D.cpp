#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int ans[MAXN],a[MAXN],b[MAXN],c[MAXN];
int color[MAXN];
struct edge
{
    int to,id,dir;
};
vector<edge> G[MAXN];
void add_edge(int u,int v,int id)
{
    G[u].push_back((edge){v,id,0});
    G[v].push_back((edge){u,id,1});
}
void dfs(int v,int p)
{
    color[v]=1;
    for(auto e:G[v])
    {
        int to=e.to,id=e.id,dir=e.dir;
        if(to==p) continue;
        if(color[to]==0)
        {
            ans[id]=dir;
            dfs(to,v);
        }
        else if(color[to]==1) ans[id]=dir;
    }
    color[v]=2;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d%d",&a[i],&b[i]);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=m;i++)
    {
        if(c[a[i]]==c[b[i]]) add_edge(a[i],b[i],i);
        else if(c[a[i]]>c[b[i]]) ans[i]=0;
        else ans[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(!color[i]) dfs(i,0);
    }
    for(int i=1;i<=m;i++) if(ans[i]==0) puts("->"); else puts("<-");
    return 0;
}