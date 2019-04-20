#include<bits/stdc++.h>
#define MAXN 1005
#define MAXM 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
vector<int> G[MAXN],rG[MAXN];
map<P,int> mp;
deque<int> ord1,ord2;
bool vis[MAXN];
void dfs_visit(int v,vector<int> G[],deque<int> &order)
{
    vis[v]=true;
	for(int i=0;i<(int)G[v].size();i++)
	{
        int to=G[v][i];
		if(!vis[to]) dfs_visit(to,G,order);
	}
	order.push_front(v);
}
void toposort(vector<int> G[],deque<int> &order)
{
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		if(!vis[i]) dfs_visit(i,G,order);
}
vector<int> ans;
int main()
{
    freopen("electricity.in","r",stdin);
    freopen("electricity.out","w",stdout);
    scanf("%d%d",&n,&m);
    bool f=true;
    for(int i=1;i<=m;i++)
    {
        int u,v,type;
        scanf("%d%d%d",&u,&v,&type);
        if(type) 
        {
            if(mp[P(u,v)]) f=false;
            mp[P(u,v)]=i;
        }
        G[u].push_back(v);
        if(type) rG[v].push_back(u); else rG[u].push_back(v);
    }
    if(!f) {puts("-1"); return 0;}
    toposort(G,ord1); toposort(rG,ord2);
    for(int i=0;i<n;i++)
    {
        int id=-1;
        for(int j=i;j<n;j++)
        {
            if(ord1[j]==ord2[i])
            {
                id=j;
                break;
            }
        }
        assert(id!=-1);
        for(int j=id;j>i;j--)
        {
            if(mp[P(ord1[j-1],ord1[j])]) ans.push_back(mp[P(ord1[j-1],ord1[j])]);
            swap(ord1[j-1],ord1[j]);
        }
    }
    printf("%d\n",(int)ans.size());
    for(auto x:ans) printf("%d ",x);
    puts("");
    return 0;
}
