/*************************************************************************
    > File Name: 55E(sqrt).cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-13 09:47:59
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 50005
#define MAXLOGN 16
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N,Q,c[MAXN];
int dp[2][MAXN],sz[2][MAXN],sum[2][MAXN];
int st[MAXLOGN+1][MAXN*2];
vector<int> G[MAXN];
int vs[MAXN*2-1];
int depth[MAXN*2-1];
int id[MAXN];
unordered_map<int,int> toggle;
void dfs(int v,int p,int d,int &k)
{
    id[v]=k;
    vs[k]=v;
    depth[k++]=d;
    for(int i=0;i<(int)G[v].size();i++)
    {
        if(G[v][i]!=p)
        {
            dfs(G[v][i],v,d+1,k);
            vs[k]=v;
            depth[k++]=d;
        }
    }
}
int getMin(int x, int y)
{
    return depth[x]<depth[y]?x:y;
}

void rmq_init(int n)
{
    for(int i=1;i<=n;++i) st[0][i]=i;
    for(int i=1;1<<i<n;++i)
        for(int j=1;j+(1<<i)-1<=n;++j)
            st[i][j]=getMin(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
void init(int V)
{
    int k=0;
    dfs(1,0,0,k);
    rmq_init(V*2-1);
}
int query(int l, int r)
{
    int k=31-__builtin_clz(r-l+1);
    return getMin(st[k][l],st[k][r-(1<<k)+1]);
}
int lca(int u,int v)
{
    if(u==v) return u;
    return vs[query(min(id[u],id[v]),max(id[u],id[v]))];
}
int dis(int u,int v)
{
    return depth[id[u]]+depth[id[v]]-2*depth[id[lca(u,v)]];
}
void dfs(int v,int p)
{
    dp[0][v]=dp[1][v]=0;
    if(c[v]==1) {sz[1][v]=1;sz[0][v]=0;}
    else {sz[0][v]=1;sz[1][v]=0;}
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        dfs(to,v);
        sz[0][v]+=sz[0][to];dp[0][v]+=sz[0][to]+dp[0][to];
        sz[1][v]+=sz[1][to];dp[1][v]+=sz[1][to]+dp[1][to];
    }
}
void dfs2(int v,int p)
{
    if(v==1) {sum[0][v]=dp[0][v]; sum[1][v]=dp[1][v];}
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        sum[0][to]=sum[0][v]-sz[0][to]+(sz[0][1]-sz[0][to]);
        sum[1][to]=sum[1][v]-sz[1][to]+(sz[1][1]-sz[1][to]);
        dfs2(to,v);
    }
}
void recal()
{
    dfs(1,0);dfs2(1,0);
}
vector<P> queries;
int main()
{
    scanf("%d%d",&N,&Q);
    for(int i=1;i<=N;i++) scanf("%d",&c[i]);
    for(int i=0;i<N-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    int blocks=(int)sqrt(Q);
    init(N);
    recal();
    //for(int i=1;i<=N;i++) printf("%d %d\n",sum[0][i],sum[1][i]);
    for(int i=1;i<=(Q-1)/blocks+1;i++)
    { 
        queries.clear();toggle.clear();
        for(int j=(i-1)*blocks+1;j<=min(i*blocks,Q);j++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            queries.push_back(P(u,v));
        }
        for(int j=0;j<(int)queries.size();j++)
        {
            P p=queries[j];
            if(p.F==1) {toggle[p.S]^=1; continue;}
            int v=p.S;
            int color=c[v]^toggle[v];
            int ans=sum[color][v];
            for(auto it:toggle) 
            {
                int u=it.F,cc=it.S^c[u];
                if(it.S==0) continue;
                if(cc!=color) ans-=dis(u,v); else ans+=dis(u,v);
            }
            printf("%d\n",ans);
        }  
        for(auto it:toggle) c[it.F]^=it.S;
        recal();
    }
    return 0;
}

