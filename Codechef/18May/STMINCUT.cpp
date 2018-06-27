#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN][MAXN];
int p[MAXN],r[MAXN];
vector<int> mem[MAXN];
ll ans;
struct edge
{
	int cost,u,v;
};
edge E[MAXN*MAXN];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        r[i]=0;
        mem[i].clear();
        mem[i].push_back(i);
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y,int cost)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) 
    {
    	p[x]=y;
    	for(int i=0;i<mem[x].size();i++)
    		for(int j=0;j<mem[y].size();j++)
    			ans+=2*cost-a[mem[x][i]][mem[y][j]]-a[mem[y][j]][mem[x][i]];
    	mem[y].insert(mem[y].end(),mem[x].begin(),mem[x].end());
    	mem[x].clear();
    }
    else
    {
        p[y]=x;
        for(int i=0;i<mem[x].size();i++)
    		for(int j=0;j<mem[y].size();j++)
    			ans+=2*cost-a[mem[x][i]][mem[y][j]]-a[mem[y][j]][mem[x][i]];
        mem[x].insert(mem[x].end(),mem[y].begin(),mem[y].end());
    	mem[y].clear();
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
bool cmp(edge x,edge y)
{
	return x.cost>y.cost;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		init(n);
		int tot=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&a[i][j]);
				E[tot++]=(edge){a[i][j],i,j};
			}
		sort(E,E+tot,cmp);
		ans=0;
		for(int i=0;i<tot;i++)
		{
			int u=E[i].u,v=E[i].v;
			//printf("%d %d %d\n",u,v,E[i].cost);
			if(same(u,v))  continue; else unite(u,v,E[i].cost);
		}
		printf("%lld\n",ans);
	}
	return 0;
}