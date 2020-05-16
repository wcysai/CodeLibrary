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
int pa[MAXLOGN][MAXN];
int depth[MAXN],dfn[MAXN],mdfn[MAXN];
int l[MAXN],r[MAXN];
int ord[MAXN];
int n,q,tot;
struct node
{
    int val;
    bool operator<(const node &c) const
    {
        return mdfn[val]<mdfn[c.val];
    }
};
multiset<node> ms;
void dfs(int v,int p,int d)
{
    dfn[v]=++tot;
    pa[0][v]=p;
    depth[v]=d;
    if(l[v]) dfs(l[v],v,d+1);
    if(r[v]) dfs(r[v],v,d+1);
}
void dfs2(int v)
{
    if(l[v]) dfs2(l[v]);
    mdfn[v]=++tot;
    ord[tot]=v;
    if(r[v]) dfs2(r[v]);
}
void init(int V)
{
    tot=0;
    dfs(1,0,0);
    for(int k=0;k+1<MAXLOGN;k++)
    {
        for(int v=1;v<=V;v++)
        {
            if(pa[k][v]<0) pa[k+1][v]=-1;
            else pa[k+1][v]=pa[k][pa[k][v]];
        }
    }
    tot=0;
    dfs2(1);
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
int v[MAXN];
int ans;
void add_node(int v)
{
    ms.insert((node){v});
    auto it=ms.lower_bound((node){v});
    auto id=it;
    if(it!=ms.begin())
    {
        it--;
        ans+=dis(it->val,v);
        it++;
    }
    it++;
    if(it!=ms.end())
    {
        ans+=dis(it->val,v);
    }
    it--;
    id++;
    if(it!=ms.begin()&&id!=ms.end())
    {
        it--;
        ans-=dis(it->val,id->val);
    }
}
void del_node(int v)
{
    auto it=ms.lower_bound((node){v});
    auto id=it;
    if(it!=ms.begin())
    {
        it--;
        ans-=dis(it->val,v);
        it++;
    }
    it++;
    if(it!=ms.end())
    {
        ans-=dis(it->val,v);
    }
    it--;
    id++;
    if(it!=ms.begin()&&id!=ms.end())
    {
        it--;
        ans+=dis(it->val,id->val);
    }
    ms.erase(ms.find((node){v}));
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
    init(n);
    for(int i=1;i<=n;i++) scanf("%d",&v[i]);
    ms.insert((node){1});
    for(int i=2;i<=n;i++)
        if(v[ord[i]]<v[ord[i-1]])
            add_node(lca(ord[i],ord[i-1]));
    for(int i=0;i<q;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int x=mdfn[a];
        if(x!=1)
        {
            if(v[ord[x]]<v[ord[x-1]]) del_node(lca(ord[x-1],ord[x]));
        }
        if(x!=n)
        {
            if(v[ord[x+1]]<v[ord[x]]) del_node(lca(ord[x],ord[x+1]));
        }
        v[a]=b;
        if(x!=1)
        {
            if(v[ord[x]]<v[ord[x-1]]) add_node(lca(ord[x-1],ord[x]));
        }
        if(x!=n)
        {
            if(v[ord[x+1]]<v[ord[x]]) add_node(lca(ord[x],ord[x+1]));
        }
        if(ms.size()==1) printf("%d\n",n);
        else
        {
            int res=ans;
            auto it=ms.begin();
            auto id=ms.end(); id--;
            res+=dis(it->val,id->val);
            printf("%d\n",n-res/2-1);
        }
        
    }
    return 0;
}