#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<assert.h>
#define MAXN 30005
#define MAXV 5000005
#define INF 1000000000
using namespace std;
int s[MAXN],k[MAXN],sum[MAXN];
struct edge{int to,cost;};
typedef pair<int,int> P;
int V,n,m;
vector<edge> G[MAXV];
void add_edge(int from,int to,int cost)
{
	G[from].push_back((edge){to,cost});
	G[to].push_back((edge){from,cost});
}
int d[MAXV],block[MAXV];
void dijkstra()
{
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d,d+V,INF);
    d[0]=0;
    que.push(P(0,0));
    while(!que.empty())
    {
        P p=que.top(); que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for(int i=0;i<G[v].size();i++)
        {
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost)
            {
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
        int id=block[v];
        if(id==n-1) return;
        for(int i=sum[id];i<sum[id+1];i++)
        {
        	if(i==v) continue;
        	if(d[i]>d[v]+k[id])
        	{
        		d[i]=d[v]+k[id];
        		que.push(P(d[i],i));
        	}
        }
    }
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&s[i]);
	sum[0]=0;
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+s[i];
	V=sum[n];
	int cnt=0;
	for(int i=0;i<V;i++)
	{
		if(i>=sum[cnt+1]) cnt++;
		block[i]=cnt;
	}
	for(int i=0;i<n;i++)
		scanf("%d",&k[i]);
	for(int i=0;i<m;i++)
	{
		int u,a,v,b,c;
		scanf("%d%d%d%d%d",&u,&a,&v,&b,&c);
		add_edge(sum[u-1]+a-1,sum[v-1]+b-1,c);
	}
	dijkstra();
	int ans=INF;
	for(int i=0;i<s[n];i++)
		ans=min(ans,d[sum[n-1]+i]);
	printf("%d\n",ans);
	return 0;
}
