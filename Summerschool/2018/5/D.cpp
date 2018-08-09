/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-09 01:30:00
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXLOGN 22
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N,K,Q;
vector<int> G[MAXN];
bool centroid[MAXN];
int st[MAXLOGN][2*MAXN];
int sz[MAXN],fa[MAXN];
int root,ans;
int vs[MAXN*2-1];
int depth[MAXN*2-1];
int id[MAXN];
vector<int> dist1[MAXN],dist2[MAXN];
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
P getroot(int v,int p,int t)//search_centroid
{
    P res=P(INT_MAX,-1);
	int m=0;
    sz[v]=1;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p||centroid[to]) continue;
        res=min(res,getroot(to,v,t));
        m=max(m,sz[to]);
        sz[v]+=sz[to];
    }
    m=max(m,t-sz[v]);
    res=min(res,P(m,v));
    return res;
}
void getdeep(int v,int p,int rt1,int rt2)//enumerate path
{
    int x1=dis(v,rt1),x2=dis(v,rt2);
    if(x1>=(int)dist1[rt1].size()) dist1[rt1].resize(x1+1);
    dist1[rt1][x1]++;
    if(rt2)
    {
        if(x2>=(int)dist2[rt1].size()) dist2[rt1].resize(x2+1);
        dist2[rt1][x2]++;
    }
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p||centroid[to]) continue;
        getdeep(to,v,rt1,rt2);
    }
}
void solve(int v,int p)
{
    centroid[v]=true;fa[v]=p;
    getdeep(v,0,v,p);
    for(int i=1;i<(int)dist1[v].size();i++) dist1[v][i]+=dist1[v][i-1];
    for(int i=1;i<(int)dist2[v].size();i++) dist2[v][i]+=dist2[v][i-1];
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(centroid[to]) continue;
        root=getroot(to,v,sz[to]).S;
        solve(root,v);
    }
    root=v;
}
void pre()
{
    init(N);
    root=getroot(1,0,N).S;
    solve(root,0);
}
int Query(int v,int k)
{
    int ans;
    if(k<(int)dist1[v].size()) ans=dist1[v][k]; else ans=dist1[v].back();
    int t=v;
    while(fa[v])
    {
        int rem=k-dis(fa[v],t);
        if(rem>=0)
        {
            int cnt1,cnt2;
            if(rem<(int)dist1[fa[v]].size()) cnt1=dist1[fa[v]][rem]; else cnt1=dist1[v].back();
            if(rem<(int)dist2[v].size()) cnt2=dist2[v][rem]; else cnt2=dist2[v].back();
            ans+=cnt1-cnt2;
        }
        v=fa[v];
    }
    return ans;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&Q);
        for(int i=1;i<=N;i++)
            G[i].clear(),dist1[i].clear(),dist2[i].clear();
        for(int i=0;i<N-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);G[v].push_back(u);
        }
        memset(centroid,false,sizeof(centroid));
        pre();
        for(int i=0;i<Q;i++)
        {
            int v,k;
            scanf("%d%d",&v,&k);
            printf("%d\n",Query(v,k));
        }
    }
    return 0;
}
