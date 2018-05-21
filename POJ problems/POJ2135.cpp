#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>
#define MAX_V 2000
#define MAX_M 40000
#define INF 100000000
using namespace std;
struct edge{int to,cap,cost,rev;};
int V;
vector<edge> G[MAX_V];
int dist[MAX_V];
int prevv[MAX_V],preve[MAX_V];
void add_edge(int from,int to,int cap,int cost)
{
    G[from].push_back((edge){to,cap,cost,G[to].size()});
    G[to].push_back((edge){from,0,-cost,G[from].size()-1});
}
int min_cost_flow(int s,int t,int f)
{
    int res=0;
    while(f>0)
    {
        fill(dist,dist+V,INF);
        dist[s]=0;
        bool update=true;
        while(update)
        {
            update=false;
            for(int v=0;v<V;v++)
            {
                if(dist[v]==INF) continue;
                for(int i=0;i<G[v].size();i++)
                {
                    edge &e=G[v][i];
                    if(e.cap>0&&dist[e.to]>dist[v]+e.cost)
                    {
                        dist[e.to]=dist[v]+e.cost;
                        prevv[e.to]=v;
                        preve[e.to]=i;
                        update=true;
                    }
                }
            }
        }
        if(dist[t]==INF)
        {
            return -1;
        }
        int d=f;
        for(int v=t;v!=s;v=prevv[v])
        {
            d=min(d,G[prevv[v]][preve[v]].cap);
        }
        f-=d;
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
int N,M;
int a[MAX_M],b[MAX_M],c[MAX_M];
void solve()
{
    int s=0,t=N-1;
    V=N;
    for(int i=0;i<M;i++)
    {
        add_edge(a[i]-1,b[i]-1,1,c[i]);
        add_edge(b[i]-1,a[i]-1,1,c[i]);
    }
    printf("%d\n",min_cost_flow(s,t,2));
}
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    }
    solve();
    return 0;
}
