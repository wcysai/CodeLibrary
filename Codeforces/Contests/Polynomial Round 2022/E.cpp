#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXLOGN 19
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,d,a[MAXN];
vector<int> G[MAXN];
bool marka[MAXN],markb[MAXN];
int pa[MAXLOGN][MAXN];
int depth[MAXN];
int ans,m1,m2;
void dfs(int v,int p,int d)
{
    pa[0][v]=p;
    depth[v]=d;
    for(int i=0;i<(int)G[v].size();i++)
        if(G[v][i]!=p) dfs(G[v][i],v,d+1);
}
void init(int V)
{
    dfs(1,-1,0);
    for(int k=0;k+1<MAXLOGN;k++)
    {
        for(int v=1;v<=V;v++)
        {
            if(pa[k][v]<0) pa[k+1][v]=-1;
            else pa[k+1][v]=pa[k][pa[k][v]];
        }
    }
}
int get(int v,int x)
{
    for(int k=0;k<MAXLOGN;k++)
        if((x>>k)&1)
            v=pa[k][v];
    return v;
}
void dfs2(int v,int p)
{
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs2(to,v);
        marka[v]|=marka[to];
        markb[v]|=markb[to];
    }
    if(marka[v]&&v!=1) ans+=2;
    if(markb[v]&&v!=1) ans+=2;
}
int main()
{
    scanf("%d%d",&n,&d);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    memset(marka,false,sizeof(marka));
    memset(markb,false,sizeof(markb));
    init(n);
    scanf("%d",&m1);
    for(int i=1;i<=m1;i++) 
    {
        int x;
        scanf("%d",&x); marka[x]=true;
        if(depth[x]>=d) markb[get(x,d)]=true; 
    }
    scanf("%d",&m2);
    for(int i=1;i<=m2;i++) 
    {
        int x;
        scanf("%d",&x); markb[x]=true;
        if(depth[x]>=d) marka[get(x,d)]=true; 
    }
    ans=0;
    dfs2(1,0);
    printf("%d\n",ans);
    return 0;
}

