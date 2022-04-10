#include<bits/stdc++.h>
#define MAXV 505
#define INF 1000000000
#define INF2 1000000000000000000LL
#define int long long
using namespace std;
typedef pair<int,int> P;
struct edge{int to,cap,cost,rev;};
int dist[MAXV],h[MAXV],prevv[MAXV],preve[MAXV];
int n,V,a[MAXV][MAXV];
vector<edge> G[MAXV];
void add_edge(int from,int to,int cap,int cost)
{
    G[from].push_back((edge){to,cap,cost,(int)G[to].size()});
    G[to].push_back((edge){from,0,-cost,(int)G[from].size()-1});
}
int min_cost_flow(int s,int t,int f)
{
    int res=0;
    while(f>0)
    {
        priority_queue<P,vector<P>,greater<P> >que;
        fill(dist+1,dist+V+1,INF2);
        dist[s]=0;
        que.push(P(0,s));
        while(!que.empty())
        {
            P p=que.top(); que.pop();
            int v=p.second;
            if(dist[v]<p.first) continue;
            for(int i=0;i<G[v].size();i++)
            {
                edge &e=G[v][i];
                if(e.cap>0&&dist[e.to]>dist[v]+e.cost+h[v]-h[e.to])
                {
                    dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
                    prevv[e.to]=v;
                    preve[e.to]=i;
                    que.push(P(dist[e.to],e.to));
                }
            }
        }
        if(dist[t]==INF2)
        {
            return -1;
        }
        for(int v=1;v<=V;v++) h[v]+=dist[v];
        int d=f;
        for(int v=t;v!=s;v=prevv[v])
        {
            d=min(d,G[prevv[v]][preve[v]].cap);
        }
        f-=d;
        res+=d*h[t];
        for(int v=t;v!=s;v=prevv[v])
        {
            edge &e=G[prevv[v]][preve[v]];
            e.cap-=d;
            G[v][e.rev].cap+=d;
        }
    }
    return res;
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		int x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		a[x][y]=max(a[x][y],z);
	}
	V=302;
	int s=301,t=302;
	for(int i=1;i<=150;i++) add_edge(s,i,1,0);
	for(int i=151;i<=300;i++) add_edge(i,t,1,0);
	for(int i=1;i<=150;i++)
		for(int j=1;j<=150;j++)
		{
			if(a[i][j])
			{
				add_edge(i,150+j,1,INF-a[i][j]);
			}
		}
	vector<int> ans;
	int res=0;
	for(int i=1;;i++)
	{
		int ret=min_cost_flow(s,t,1);
		if(ret==-1) break; else {res+=ret; ans.push_back(res);}
	}
	printf("%lld\n",(int)ans.size());
	for(int i=0;i<(int)ans.size();i++) printf("%lld\n",(i+1)*INF-ans[i]);
	return 0;
}