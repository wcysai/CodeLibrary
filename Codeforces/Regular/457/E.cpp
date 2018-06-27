#include<bits/stdc++.h>
#define MAXV 100005
#define MAXLOGV 32
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
int N,Q;
int st[MAXLOGV][MAXV];
vector<int> G[MAXV];
int root;
int vs[MAXV*2-1];
int depth[MAXV*2-1];
int id[MAXV];
int a[MAXV],f[MAXV],d[MAXV],pa[MAXV];
bool used[MAXV];
int bit[2][MAXV+1];
int sum(int type,int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[type][i];
        i-=i&-i;
    }
    return s;
}
void add(int type,int i,int x)
{
    while(i<=N)
    {
        bit[type][i]+=x;
        i+=i&-i;
    }
}
void dfs_visit(int v)
{
	d[v]=++t;
	used[v]=true;
	for(int i=0;i<G[v].size();i++)
	{
		int to=G[v][i];
		if(!used[to]) dfs_visit(to);
	}
	f[v]=t;
}
void dfs(int v,int p,int d,int &k)
{
    id[v]=k;
    vs[k]=v;
    depth[k++]=d;
    pa[v]=p;
    for(int i=0;i<G[v].size();i++)
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
            st[i][j]=getMin(st[i-1][j],st[i-1][j+(1<<i-1)]);
}
void init(int V)
{
    int k=0;
    dfs(root,-1,0,k);
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
    return vs[query(min(id[u],id[v]),max(id[u],id[v])+1)];
}
int main()
{
    scanf("%d%d",&N,&Q);
    memset(bit,0,sizeof(bit));
    memset(bit1,0,sizeof(bit1));
    for(int i=0;i<N;i++)
    {
    	scanf("%d",&a[i]);
    	add(0,i,a[i]);
    }
    for(int i=0;i<N;i++)
    	G[i].clear();
    for(int i=0;i<N-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x-1].push_back(y-1);
        G[y-1].push_back(x-1);
    }
    root=0;
    init(N);
    memset(used,false,sizeof(used));
    dfs_visit(root);
    for(int i=0;i<Q;i++)
    {
    	int t,u,v,x;
    	scanf("%d",&t);
    	if(t==1)
    	{
    		scanf("%d",&u);
    		root=u-1;
    	}
    	else if(t==2)
    	{
    		scanf("%d%d%d",&u,&v,&x);
    		u--,v--;
    		int w=lca(u,v);
    		add(0,u,x*(depth[id[u]]+1));
    		add(0,v,x*(depth[id[v]]+1));
    		add(0,w,-x*(depth[id[w]]+1));
    		if(pa[w]!=-1) add(0,pa[w].-x*(depth[id[pa[w]]]+1));
    		add(1,u,x);
    		add(1,v,x);
    		add(1,w,-x);
    		if(pa[w]!=-1) 
    	}
    }
    return 0;
}
