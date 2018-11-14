/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-15 00:17:18
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXLOGN 20
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q;
int st[MAXLOGN][2*MAXN];
vector<int> G[MAXN];
int vs[MAXN*2-1];
int depth[MAXN*2-1],dfn[MAXN],dep[MAXN];
int id[MAXN],tot;
void dfs(int v,int p,int d,int &k)
{
    id[v]=k;
    vs[k]=v;
    dep[v]=d;
    dfn[v]=++tot;
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
struct node
{
    int num1,id1,num2,id2;
};
node merge1(node x,node y)
{
    P a[4];
    a[0]=P(x.num1,x.id1);a[1]=P(x.num2,x.id2);a[2]=P(y.num1,y.id1);a[3]=P(y.num2,y.id2);
    sort(a,a+4);
    node ret;
    ret.num1=a[0].F;ret.id1=a[0].S;ret.num2=a[1].F;ret.id2=a[1].S;
    return ret;
}
node merge2(node x,node y)
{
    P a[4];
    a[0]=P(x.num1,x.id1);a[1]=P(x.num2,x.id2);a[2]=P(y.num1,y.id1);a[3]=P(y.num2,y.id2);
    sort(a,a+4,greater<P>());
    node ret;
    ret.num1=a[0].F;ret.id1=a[0].S;ret.num2=a[1].F;ret.id2=a[1].S;
    return ret;
}
struct segtree
{
    node minv[4*MAXN],maxv[4*MAXN];
    void pushup(int k)
    {
        minv[k]=merge1(minv[k*2],minv[k*2+1]);
        maxv[k]=merge2(maxv[k*2],maxv[k*2+1]);
    }
    void build(int k,int l,int r)
    {
        if(l==r) {minv[k]=(node){dfn[l],l,INF,-1}; maxv[k]=(node){dfn[l],l,-INF,-1}; return;}
        int mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
        pushup(k);
    }
    node query1(int k,int l,int r,int x,int y)
    {
        if(x>r||l>y) return (node){INF,-1,INF,-1};
        if(l>=x&&r<=y) return minv[k];
        int mid=(l+r)/2;
        return merge1(query1(k*2,l,mid,x,y),query1(k*2+1,mid+1,r,x,y));
    }
    node query2(int k,int l,int r,int x,int y)
    {
        if(x>r||l>y) return (node){-INF,-1,-INF,-1};
        if(l>=x&&r<=y) return maxv[k];
        int mid=(l+r)/2;
        return merge2(query2(k*2,l,mid,x,y),query2(k*2+1,mid+1,r,x,y));
    }
}seg;
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;i++)
    {
        int p;scanf("%d",&p);
        G[p].push_back(i);G[i].push_back(p);
    }
    init(n);
    seg.build(1,1,n);
    for(int i=0;i<q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        if(r-l==1)
        {
            if(dep[l]<dep[r]) printf("%d %d\n",l,dep[r]);
            else printf("%d %d\n",r,dep[l]);
            continue;
        }
        node u=seg.query1(1,1,n,l,r); node v=seg.query2(1,1,n,l,r);
        int ans=dep[lca(u.id1,v.id1)],id;
        if(u.id1!=l&&v.id1!=l) id=l;
        else if(u.id1!=r&&v.id1!=r) id=r;
        else id=l+1;
        if(dep[lca(u.id2,v.id1)]>ans) {ans=dep[lca(u.id2,v.id1)]; id=u.id1;}
        if(dep[lca(u.id1,v.id2)]>ans) {ans=dep[lca(u.id1,v.id2)]; id=v.id1;}
        printf("%d %d\n",id,ans);
    }
    return 0;
}

