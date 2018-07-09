/*************************************************************************
    > File Name: COT.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-09 09:30:30
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 3000005
#define MAXLOGN 32
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,sz,tot,cnt,a[MAXN],pa[MAXN],edi[MAXN];
int lson[MAXM],rson[MAXM],sum[MAXM];
int st[MAXLOGN][MAXN];
vector<int> G[MAXN];
int rt=1;
int vs[MAXN*2-1];
int depth[MAXN*2-1];
int id[MAXN];
vector<int> pos;
void dfs(int v,int p,int d,int &k)
{
    id[v]=k;
    pa[v]=p;
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
    for(int i=1;(1<<i)<=n;++i)
        for(int j=1;j+(1<<i)-1<=n;++j)
            st[i][j]=getMin(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
void init(int V)
{
    int k=0;
    dfs(rt,0,0,k);
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
void merge(int k)
{
    sum[k]=sum[lson[k]]+sum[rson[k]];
}
void build(int &k,int l,int r)
{
    k=++tot;
    if(l==r) return;
    int mid=(l+r)/2;
    build(lson[k],l,mid);build(rson[k],mid+1,r);
    merge(k);
}
void insert(int &k,int last,int l,int r,int p)
{
    k=++tot;
    sum[k]=sum[last];
    if(l==r) {sum[k]++; return;}
    lson[k]=lson[last];rson[k]=rson[last];
    int mid=(l+r)/2;
    if(p<=mid) insert(lson[k],lson[last],l,mid,p);
    else insert(rson[k],rson[last],mid+1,r,p);
    merge(k);
}
int query(int k1,int k2,int k3,int k4,int l,int r,int num)
{   
    //printf("%d:%d %d:%d %d:%d %d:%d\n",k1,sum[k1],k2,sum[k2],k3,sum[k3],k4,sum[k4]);
    if(l==r) return l;
    int x=sum[lson[k1]]+sum[lson[k2]]-sum[lson[k3]]-sum[lson[k4]];
    //printf("num:%d x:%d\n",num,x);
    int mid=(l+r)/2;
    if(num>=x) return query(rson[k1],rson[k2],rson[k3],rson[k4],mid+1,r,num-x);
    else return query(lson[k1],lson[k2],lson[k3],lson[k4],l,mid,num);
}
void dfs_build(int v,int p)
{
    int x=lower_bound(pos.begin(),pos.end(),a[v])-pos.begin()+1;
    //printf("%d %d\n",v,x);
    insert(edi[v],edi[p],1,sz,x);
    for(int i=0;i<(int)G[v].size();i++)
    {
        if(G[v][i]==p) continue;
        dfs_build(G[v][i],v);
    }
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        pos.push_back(a[i]);
    }
    sort(pos.begin(),pos.end());
    pos.erase(unique(pos.begin(),pos.end()),pos.end());
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    init(n);
    sz=(int)pos.size();
    build(edi[0],1,sz);
    dfs_build(1,0);
    for(int i=1;i<=q;i++)
    {
        int u,v,k;
        scanf("%d%d%d",&u,&v,&k);
        int x=lca(u,v);
        int k1=edi[u],k2=edi[v],k3=edi[x],k4=edi[pa[x]];
        printf("%d\n",pos[query(k1,k2,k3,k4,1,sz,k-1)-1]);
    }
    return 0;
}

