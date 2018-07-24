/*************************************************************************
    > File Name: 3730.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-24 06:56:09
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXLOGN 22
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<int> G[MAXN];
int n,q,root;
int st[MAXLOGN][MAXN],vs[MAXN*2-1],depth[MAXN*2-1],id[MAXN],val[MAXN],sz[MAXN],fa[MAXN];
bool centroid[MAXN];
inline int read()
{
    int f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
struct BIT
{
    vector<int> bit;
    int size;
    void init()
    {
        bit.resize(size+2);
    }
    void add(int i,int x)
    {
        i++;
        while(i<=size+1)
        {
            bit[i]+=x;
            i+=i&-i;
        }
    }
    int sum(int i)
    {
        i=min(i+1,size+1);
        int s=0;
        while(i>0)
        {
            s+=bit[i];
            i-=i&-i;
        }
        return s;
    }
}bit1[MAXN],bit2[MAXN];
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
    for(int i=1;1<<i<=n;++i)
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
int findsz(int v,int p,int x)
{
    int res=dis(v,x);
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p||centroid[to]) continue;
        res=max(res,findsz(to,v,x));
    }
    return res;
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
void solve(int v,int p)
{
    //printf("%d %d\n",v,p);
    fa[v]=p;
    bit1[v].size=findsz(v,0,v);
    if(p) bit2[v].size=findsz(v,0,p); 
    bit1[v].init();bit2[v].init();
    centroid[v]=true;
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
    init(n);
    root=getroot(1,0,n).S;
    solve(root,0);
}
void update(int v,int x)
{
    int inc=x-val[v],t=v;
    val[v]=x;
    bit1[v].add(0,inc);
    while(fa[v])
    {
        bit2[v].add(dis(fa[v],t),inc);
        bit1[fa[v]].add(dis(fa[v],t),inc);
        v=fa[v];
    }
}
int Query(int v,int k)
{
    int ans=bit1[v].sum(k),t=v;
    while(fa[v])
    {
        int res=bit1[fa[v]].sum(k-dis(fa[v],t))-bit2[v].sum(k-dis(fa[v],t));
        ans+=res;
        v=fa[v];
    }
    return ans;
}
int main()
{
    n=read();q=read();
    for(int i=1;i<=n;i++) val[i]=read();
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    pre();
    int type,x,y,ans=0;
    for(int i=1;i<=n;i++)
    {
        int r=val[i];
        val[i]=0;
        update(i,r);
    }
    for(int i=0;i<q;i++)
    {
        type=read();x=read();y=read();
        x^=ans;y^=ans;
        //printf("%d %d %d\n",type,x,y);
        if(type==0)
        {
            ans=Query(x,y);
            printf("%d\n",ans);
        }
        else update(x,y);
    }
    return 0;
}

