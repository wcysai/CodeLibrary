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
int n,m,tot=0;
vector<int> G[MAXN];
bool vis[MAXN];
int ord[MAXN],ans[MAXN];
P E[MAXN];
void dfs(int v)
{
    vis[v]=true;
    for(auto to:G[v]) if(!vis[to]) dfs(to);
    ord[v]=++tot;
}
int main()
{
    scanf("%d%d",&n,&m);
    m=n-1+m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        E[i]=P(u,v);
        G[u].push_back(v);
    }
    memset(ans,0,sizeof(ans));
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
    ord[0]=INF;
    for(int i=0;i<m;i++) 
    {
        int u=E[i].F,v=E[i].S;
        if(ord[u]<=ord[ans[v]]) ans[v]=u;
    }
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}

