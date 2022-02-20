#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cost;};
typedef pair<int,int> P;
int n,m;
vector<edge> G[MAXN];
int d[MAXN],h[MAXN];
void add_edge(int u,int v,int cost)
{
	G[u].push_back((edge){v,cost});
}
void dijkstra(int s)
{
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d+1,d+n+1,INF);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty())
    {
        P p=que.top(); que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for(int i=0;i<(int)G[v].size();i++)
        {
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost)
            {
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&h[i]);
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if(h[u]<=h[v]) add_edge(u,v,h[v]-h[u]); else add_edge(u,v,0);
		if(h[v]<=h[u]) add_edge(v,u,h[u]-h[v]); else add_edge(v,u,0);
	}
	dijkstra(1);
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,h[1]-h[i]-d[i]);
	printf("%d\n",ans);
	return 0;
}