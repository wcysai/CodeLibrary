#include<bits/stdc++.h>
#define MAXV 200005
#define MAXLOGV 32
using namespace std;
int N,M,Q;
int st[MAXLOGV][MAXV];
vector<int> G[MAXV];
int root;
int vs[MAXV*2-1];
int depth[MAXV*2-1];
int id[MAXV];
int sz[MAXV];
void dfs(int v,int p,int d,int &k)
{
    id[v]=k;
    vs[k]=v;
    depth[k++]=d;
    int cnt=1;
    for(int i=0;i<G[v].size();i++)
    {
        if(G[v][i]!=p)
        {
            dfs(G[v][i],v,d+1,k);
            vs[k]=v;
            depth[k++]=d;
            cnt+=sz[G[v][i]];
        }
    }
    sz[v]=cnt;
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
    for(int i=0;i<N-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--,y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    root=0;
    init(N);
    while(Q--)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        x--,y--,z--;
        if(lca(x,z)!=z&&lca(y,z)!=z)
        {
        	printf("0\n");
        	continue;
        }
        else if(lca(x,z)!=z)
        {
        	int ans=sz[z];
        	for(int i=0;i<G[z].size();i++)
        		if(sz[G[z][i]]<sz[z]&&lca(y,G[z][i])==G[z][i]) ans-=sz[G[z][i]];
        	printf("%d\n",ans);
        }
        else if(lca(y,z)!=z)
        {
        	int ans=sz[z];
        	for(int i=0;i<G[z].size();i++)
        		if(sz[G[z][i]]<sz[z]&&lca(x,G[z][i])==G[z][i]) ans-=sz[G[z][i]];
        	printf("%d\n",ans);
        }
        else
        {
        	bool f=true;
        	int ans=N;
        	for(int i=0;i<G[z].size();i++)
        	{
        		bool f1=false,f2=false;
        		if(sz[G[z][i]]<sz[z]&&lca(x,G[z][i])==G[z][i]) {ans-=sz[G[z][i]],f1=true;}
        		if(sz[G[z][i]]<sz[z]&&lca(y,G[z][i])==G[z][i]) {ans-=sz[G[z][i]],f2=true;}
        		if(f1&&f2)
        		{
        			printf("0\n");
        			f=false;
        			break;
        		}
        	}
        	if(f) printf("%d\n",ans);
        }
    }
    return 0;
}