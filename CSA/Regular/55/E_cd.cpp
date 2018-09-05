/*************************************************************************
    > File Name: 55E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-13 09:13:54
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
int n,q,c[MAXN];
vector<int> G[MAXN];
bool centroid[MAXN];
int sz[MAXN],fa[MAXN];
int dp[MAXN],sum[MAXN];
int res1[MAXN],res2[MAXN],cnt1[MAXN],cnt2[MAXN];
int root;
void dfs(int v,int p)
{
    dp[v]=0;sz[v]=1;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        dfs(to,v);
        sz[v]+=sz[to];dp[v]+=sz[to]+dp[to];
    }
}
void dfs2(int v,int p)
{
    if(v==1) sum[v]=dp[v];
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        sum[to]=sum[v]-sz[to]+(n-sz[to]);
        dfs2(to,v);
    }
}
int st[MAXLOGN+1][2*MAXN];
int vs[MAXN*2-1];
int depth[MAXN*2-1];
int id[MAXN];
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
void dfs3(int v,int p,int rt1,int rt2)//enumerate path
{
    if(!c[v])
    {
        res1[rt1]+=dis(v,rt1);cnt1[rt1]++;
        if(rt2) {res2[rt1]+=dis(v,rt2);cnt2[rt1]++;}
    }
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p||centroid[to]) continue;
        dfs3(to,v,rt1,rt2);
    }
}
void solve(int v,int p)
{
    fa[v]=p;
    centroid[v]=true;
    dfs3(v,p,v,p);
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(centroid[to]) continue;
        root=getroot(to,v,sz[to]).S;
        solve(root,v);
    }
    root=v;
}
void toggle(int v)
{
    c[v]=1-c[v];
    int t=v;
    if(c[v])
    {
        cnt1[v]--;;
        while(fa[v])
        {
            cnt1[fa[v]]--;cnt2[v]--;
            res1[fa[v]]-=dis(fa[v],t);res2[v]-=dis(fa[v],t);
            v=fa[v];
        }
    }
    else
    {
        cnt1[v]++;
        while(fa[v])
        {
            cnt1[fa[v]]++;cnt2[v]++;
            res1[fa[v]]+=dis(fa[v],t);res2[v]+=dis(fa[v],t);
            v=fa[v];
        }
    }
}
int query(int v)
{
    int t=v,ans=res1[v];
    while(fa[v])
    {
        ans+=res1[fa[v]]-res2[v]+(cnt1[fa[v]]-cnt2[v])*dis(fa[v],t);
        v=fa[v];
    }
    if(!c[t]) return ans; else return sum[t]-ans;
}
void pre()
{
    dfs(1,0);dfs2(1,0);init(n);
    root=getroot(1,0,n).S;
    solve(root,0);
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    memset(centroid,false,sizeof(centroid));
    pre();
    //for(int i=1;i<=n;i++) printf("%d\n",sum[i]);
    for(int i=0;i<q;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(u==1) toggle(v); else printf("%d\n",query(v));
    }
    return 0;
}

