#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<assert.h>
#define MAXN 1005
#define MAXV 3005
#define INF 1000000000
using namespace std;
int s[MAXN],t[MAXN],v[MAXN];
typedef pair<int,int> P;
struct edge{int to,cap,cost,rev;};
int dist[MAXV],h[MAXV],prevv[MAXV],preve[MAXV];
int n,V;
vector<edge> G[MAXV];
inline void add_edge(int from,int to,int cap,int cost)
{
    G[from].push_back((edge){to,cap,cost,G[to].size()});
    G[to].push_back((edge){from,0,-cost,G[from].size()-1});
}
static int min_cost_flow(int s,int t,int f)
{
    int res=0;
    fill(h,h+V,0);
    while(f>0)
    {
        priority_queue<P,vector<P>,greater<P> >que;
        fill(dist,dist+V,INF);
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
        if(dist[t]==INF)
        {
            return -1;
        }
        for(int v=0;v<V;v++) h[v]+=dist[v];
        int d=f;
        for(int v=t;v!=s;v=prevv[v])
        {
            d=min(d,(int)G[prevv[v]][preve[v]].cap);
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
int main()
{
    scanf("%d",&n);
    int s,t,v;
    V=n+30003;
    int ans=1000*n;
    for(int i=0;i<n;i++)
    	add_edge(0,i+1,1,0);
    for(int i=0;i<n;i++)
    {
    	scanf("%d%d%d",&s,&t,&v);
    	for(int j=s;j<=t;j++)
    		add_edge(i+1,n+j,1,1000-v);
    }
    for(int i=0;i<n;i++)
    	add_edge(i+1,n+30001,n,1000);
    add_edge(n+30001,n+30002,n,0);
    for(int i=n+1;i<=n+30000;i++)
    	add_edge(i,n+30002,1,0);
    printf("%d\n",ans-min_cost_flow(0,n+30002,n));
    return 0;
}
