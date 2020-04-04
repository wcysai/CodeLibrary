#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,s,t;
struct edge{int to,cap,cost,rev,id;};
int dist[MAXN],h[MAXN],prevv[MAXN],preve[MAXN];
int V;
bool inque[MAXN];
vector<edge> G[MAXN];
void add_edge(int from,int to,int cap,int cost)
{
    G[from].push_back((edge){to,cap,cost,(int)G[to].size()});
    G[to].push_back((edge){from,0,-cost,(int)G[from].size()-1});
}
int min_cost_flow(int s,int t)
{
    int res=0;
    while(true)
    {
        queue<int>que;
        fill(dist+1,dist+V+1,INF);
        fill(inque+1,inque+V+1,false);
        dist[s]=0;
        que.push(s);
        while(!que.empty())
        {
            int u=que.front(); que.pop();
            for(int i=0;i<(int)G[u].size();i++)
            {
                if(G[u][i].cap>0&&dist[u]+G[u][i].cost<dist[G[u][i].to])
                {
                    dist[G[u][i].to]=dist[u]+G[u][i].cost;
                    prevv[G[u][i].to]=u;
                    preve[G[u][i].to]=i;
                    if(!inque[G[u][i].to])
                    {
                        inque[G[u][i].to]=true;
                        que.push(G[u][i].to);
                    }
                }
            }
            inque[u]=false;
        }
        if(dist[t]==INF) return res;
        int d=INF;
        for(int v=t;v!=s;v=prevv[v]) d=min(d,G[prevv[v]][preve[v]].cap);
        res+=d*dist[t];
        for(int v=t;v!=s;v=prevv[v])
        {
            edge &e=G[prevv[v]][preve[v]];
            e.cap-=d;
            G[v][e.rev].cap+=d;
        }
    }
    return res;
}
int cost[MAXN];
signed main()
{
    scanf("%lld",&n);
    int s=n+1,t=n+2;
    V=n+2;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%lld",&k);
        for(int j=0;j<k;j++)
        {
            int x,y;
            scanf("%lld%lld",&x,&y);
            add_edge(i,x,INF,y);
            cost[x]++; cost[i]--; ans+=y;
        }
        if(i!=1) add_edge(i,1,INF,0);
    }
    for(int i=1;i<=n;i++) 
    {
        if(cost[i]>0) add_edge(s,i,cost[i],0);
        if(cost[i]<0) add_edge(i,t,-cost[i],0);
    }
    printf("%lld\n",min_cost_flow(s,t)+ans);
    return 0;
}
