#include<bits/stdc++.h>
#define MAXN 105
#define MAXM 2505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cap,cost,rev;};
int n,m,V,p[MAXN];
int dist[MAXN],prevv[MAXN],preve[MAXN];
vector<edge> G[MAXN];
bool inque[MAXN];
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
        if(dist[t]>0) return res;
        int d=f;
        for(int v=t;v!=s;v=prevv[v]) d=min(d,G[prevv[v]][preve[v]].cap);
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
int main()
{
    freopen("beer.in","r",stdin);
    freopen("beer.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++) scanf("%d",&p[i]);
    V=n+1;
    for(int i=0;i<m;i++)
    {
        int u,v,cap,cost;
        scanf("%d%d%d%d",&u,&v,&cap,&cost);
        add_edge(u,v,cap,cost); add_edge(v,u,cap,cost);
    }
    for(int i=2;i<=n;i++) add_edge(i,n+1,INF,-p[i]);
    printf("%d\n",-min_cost_flow(1,n+1,INF));
    return 0;
}
