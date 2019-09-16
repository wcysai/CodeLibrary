#include<bits/stdc++.h>
#define MAXN 200005
#define MAXLOGN 20
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,oldn,q,k,tot;
vector<int> G[MAXN];
int pa[MAXLOGN][MAXN],depth[MAXN];
bool centroid[MAXN];
int sz[MAXN],fa[MAXN];
vector<int> cnt[MAXN][2];
vector<P> query;
void add_edge(int u,int v)
{
    ++tot;
    G[v].push_back(tot); G[tot].push_back(v);
    G[u].push_back(tot); G[tot].push_back(u);
}
void dfs(int v,int p,int d)
{
    pa[0][v]=p;
    depth[v]=d;
    for(int i=0;i<(int)G[v].size();i++)
        if(G[v][i]!=p) dfs(G[v][i],v,d+1);
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
int get_vertex(int u,int v,int d)
{
    int l=lca(u,v);
    if(depth[u]-depth[l]>=d) return get(u,d);
    else return get(v,dis(u,v)-d);
}
void calculate_partial_sum(vector<int> &v)
{
    for(int i=1;i<(int)v.size();i++) v[i]+=v[i-1];
}
P intersect(P x,P y)
{
    if(x.F==-1||y.F==-1) return P(-1,-1);
    if(x.S>y.S) swap(x,y);
    int d=dis(x.F,y.F);
    if(d>x.S+y.S) return P(-1,-1);
    if(y.S-x.S>=d) return x;
    int dd=(d+x.S-y.S)/2;
    return P(get_vertex(x.F,y.F,dd),x.S-dd);
}
P getroot(int v,int p,int t)//search_centroid
{
    P res=P(INT_MAX,-1);
	int m=0;
    sz[v]=1;
    for(auto to:G[v])
    {
        if(to==p||centroid[to]) continue;
        res=min(res,getroot(to,v,t));
        m=max(m,sz[to]);
        sz[v]+=sz[to];
    }
    m=max(m,t-sz[v]);
    res=min(res,P(m,v));
    return res;
}
void dfs2(int v,int p,int id,int u,int rt)
{
    if(v<=oldn)
    {
        int d=dis(u,v);
        if(cnt[rt][id].size()<=d) cnt[rt][id].resize(d+1);
        cnt[rt][id][d]++;
    }
    for(auto to:G[v])
    {
        if(centroid[to]||to==p) continue;
        dfs2(to,v,id,u,rt);
    }
}
void solve(int v,int p)
{
    fa[v]=p;
    cnt[v][0].clear(); cnt[v][0].push_back(0); cnt[v][1].clear(); cnt[v][1].push_back(0);
    dfs2(v,0,0,v,v); calculate_partial_sum(cnt[v][0]);
    if(p)
    {
        dfs2(v,0,1,p,v);
        calculate_partial_sum(cnt[v][1]);
    }
    centroid[v]=true;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(centroid[to]||to==p) continue;
        int rt=getroot(to,v,sz[to]).S;
        solve(rt,v);
    }
}
void centroid_decomposition()
{
    int rt=getroot(1,0,n).S;
    solve(rt,0);
}
int get_ans(P p)
{
    int u=p.F,d=p.S;
    int tmp=u,ans=0;
    while(tmp)
    {
        int dd=d-dis(u,tmp);
        if(dd>=0) ans+=(cnt[tmp][0].size()>dd?cnt[tmp][0][dd]:cnt[tmp][0].back());
        if(fa[tmp])
        {
            dd=d-dis(u,fa[tmp]);
            if(dd>=0) ans-=(cnt[tmp][1].size()>dd?cnt[tmp][1][dd]:cnt[tmp][1].back());
        }
        tmp=fa[tmp];
    }
    return ans;
}
ll solve_case(vector<P> &v)
{
    int sz=(int)v.size();
    vector<P> pre(sz+1),suf(sz+1);
    pre[0]=suf[sz]=P(1,n);
    for(int i=1;i<=sz;i++) pre[i]=intersect(pre[i-1],v[i-1]);
    for(int i=sz-1;i>=0;i--) suf[i]=intersect(suf[i+1],v[i]);
    ll ans=0;
    for(int i=0;i<sz;i++)
    {
        P p=intersect(pre[i],suf[i+1]);
        if(p.F!=-1) ans+=get_ans(p);
    }
    if(pre[sz].F!=-1) ans-=1LL*(sz-1)*get_ans(pre[sz]);
    return ans;
}
int main()
{
    scanf("%d",&n); tot=n;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
    }
    oldn=n; n=tot;
    init(n);
    centroid_decomposition();
    int x,y;
    //while(scanf("%d%d",&x,&y)==2) printf("%d\n",get_ans(P(x,y)));
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%d",&k);
        query.clear();
        for(int j=0;j<k;j++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            query.push_back(P(x,2*y));
        }
        printf("%lld\n",solve_case(query));
    }
    return 0;
}
