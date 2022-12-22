#include<bits/stdc++.h>
#define MAXN 200005
#define MAXLOGN 20
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
vector<int> G[MAXN];
int pa[MAXLOGN][MAXN];
int low[MAXLOGN][MAXN],st[MAXN],ed[MAXN];
int depth[MAXN],ans[MAXN],cnt[MAXN];
int n,m,q,tot;
int u[MAXN],v[MAXN];
vector<pair<P,int> > query[MAXN];
vector<int> upd[MAXN];
int bit[MAXN];
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<MAXN)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
void dfs(int v,int p,int d)
{
    pa[0][v]=p; st[v]=++tot;
    depth[v]=d;
    for(int i=0;i<(int)G[v].size();i++)
        if(G[v][i]!=p) dfs(G[v][i],v,d+1);
    ed[v]=tot;
}
void init(int V)
{
    dfs(1,0,0);
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
int lca(int u,int v)
{
    if(depth[u]>depth[v]) swap(u,v);
    v=get(v,depth[v]-depth[u]);
    if(u==v) return u;
    for(int k=MAXLOGN-1;k>=0;k--)
    {
        if(pa[k][u]!=pa[k][v])
        {
            u=pa[k][u];
            v=pa[k][v];
        }
    }
    return pa[0][u];
}
int dis(int u,int v)
{
    return depth[u]+depth[v]-2*depth[lca(u,v)];
}
void dfs2(int v,int p)
{
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs2(to,v);
        if(depth[low[0][to]]<depth[low[0][v]]) low[0][v]=low[0][to];
    }
}
P get_res(int from,int to)
{
    int cnt=0,cur=from;
    for(int k=MAXLOGN-1;k>=0;k--)
    {
        if(depth[low[k][cur]]>depth[to])
        {
            cur=low[k][cur];
            cnt+=(1<<k);
        }
    }
    return P(cur,cnt);
}
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        int p;
        scanf("%d",&p);
        add_edge(i,p);
    }
    init(n);
    scanf("%d",&m);
    for(int i=1;i<=n;i++) low[0][i]=i;
    for(int i=1;i<=m;i++) 
    {
        scanf("%d%d",&u[i],&v[i]);
        int l=lca(u[i],v[i]);
        if(depth[low[0][u[i]]]>depth[l]) low[0][u[i]]=l;
        if(depth[low[0][v[i]]]>depth[l]) low[0][v[i]]=l;
    }
    dfs2(1,0);
    for(int k=0;k+1<MAXLOGN;k++)
        for(int v=1;v<=n;v++)
            low[k+1][v]=low[k][low[k][v]];
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        int l=lca(u,v);
        P p=get_res(u,l),q=get_res(v,l);
        if(depth[low[MAXLOGN-1][u]]>depth[l]||depth[low[MAXLOGN-1][v]]>depth[l]) {ans[i]=-1; continue;}
        if(l==u||l==v)
        {
            if(l==v) swap(u,v);
            ans[i]=get_res(v,l).S+1;
            continue;
        }
        ans[i]=p.S+q.S+2;
        int uu=p.F,vv=q.F; //count x in [ st[uu],ed[uu] ] y in [ st[vv], ed[vv] ]
        query[ed[uu]].push_back(make_pair(P(ed[vv],1),i));
        query[ed[uu]].push_back(make_pair(P(st[vv]-1,-1),i));
        query[st[uu]-1].push_back(make_pair(P(ed[vv],-1),i));
        query[st[uu]-1].push_back(make_pair(P(st[vv]-1,1),i));
    }
    for(int i=1;i<=m;i++)
    {
        upd[st[u[i]]].push_back(st[v[i]]);
        upd[st[v[i]]].push_back(st[u[i]]);
    }
    for(int i=1;i<=n;i++)
    {
        for(auto x:upd[i]) add(x,1);
        for(auto p:query[i])
            if(p.F.F>0) cnt[p.S]+=p.F.S*sum(p.F.F);
    }
    for(int i=1;i<=q;i++) if(cnt[i]&&ans[i]!=-1) ans[i]--;
    for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
    return 0;
}
