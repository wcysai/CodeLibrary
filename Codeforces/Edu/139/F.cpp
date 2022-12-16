#include<bits/stdc++.h>
#define MAXV 105
#define MAXN 105
#define MAXM 205
#define INF 1000000000000000000LL
#define INF2 10000000000LL
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
struct edge{int to,cap; ll cost; int rev,id;};
int n,m,V,s[MAXV],e[MAXV];
ll w[MAXV];
ll h[MAXV],dist[MAXV];
int prevv[MAXV],preve[MAXV];
vector<edge> G[MAXV];
bool inque[MAXV];
void add_edge(int from,int to,int cap,ll cost,int id)
{
    G[from].push_back((edge){to,cap,cost,(int)G[to].size(),id});
    G[to].push_back((edge){from,0,-cost,(int)G[from].size()-1,-1});
}
void dijkstra(int s)
{
    priority_queue<P,vector<P>,greater<P> >que;
    fill(dist+1,dist+V+1,INF);
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
}
void spfa(int s)
{
    queue<int>que;
    fill(h+1,h+V+1,INF);
    fill(inque+1,inque+V+1,false);
    h[s]=0;
    que.push(s);
    while(!que.empty())
    {
        int u=que.front(); que.pop();
        for(int i=0;i<(int)G[u].size();i++)
        {
            if(G[u][i].cap>0&&h[u]+G[u][i].cost<h[G[u][i].to])
            {
                h[G[u][i].to]=h[u]+G[u][i].cost;
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
}
ll min_cost_flow(int s,int t)
{
    ll res=0;
    spfa(s);
    while(true)
    {
        dijkstra(s);
        if(dist[t]==INF) return res;
        if(h[t]+dist[t]>=0) return res;
        for(int v=1;v<=V;v++) h[v]+=dist[v];
        int d=V;
        for(int v=t;v!=s;v=prevv[v])
        {
            d=min(d,G[prevv[v]][preve[v]].cap);
        }
        res+=d*h[t];
        for(int v=t;v!=s;v=prevv[v])
        {
            edge &e=G[prevv[v]][preve[v]];
            e.cap-=d;
            G[v][e.rev].cap+=d;
        }
    }
}
int x[MAXM],y[MAXM],c[MAXM],ww[MAXM];
int flow[MAXM];
int need[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    ll ans=0;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d%d",&x[i],&y[i],&c[i],&ww[i]);
        if(c[i]&1)
        {
            c[i]--; flow[i]++;
            ans+=w[i];
            if(x[i]!=1) need[x[i]]++;
            if(y[i]!=n) need[y[i]]--;
        }
        c[i]/=2;
    }
    for(int i=1;i<=n;i++) if(need[i]&1) {puts("Impossible"); return 0;}
    for(int i=0;i<m;i++)
    {
        add_edge(x[i],y[i],c[i],ww[i]*2,i);
    }
    int sum=0;
    for(int i=2;i<=n-1;i++)
    {
        if(need[i]>0) {add_edge(i,n,need[i]/2,-INF2,-1); sum+=need[i]/2;}
        if(need[i]<0) {add_edge(1,i,-need[i]/2,-INF2,-1); sum-=need[i]/2;}
    }
    ll res=INF2*sum;
    V=n;
    res+=min_cost_flow(1,n);
    if(res>=100000000) {puts("Impossible"); return 0;}
    ans+=res;
    puts("Possible");
    for(int i=1;i<=n;i++)
        for(auto e:G[i])
        {
            if(e.id==-1) continue;
            flow[e.id]+=(c[e.id]-e.cap)*2;
        }
    for(int i=0;i<m;i++) printf("%d%c",flow[i],i==m-1?'\n':' ');
    return 0;
}

