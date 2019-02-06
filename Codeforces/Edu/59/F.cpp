#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 505
#define MAXV 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cap,cost,rev;};
int dist[MAXV],h[MAXV],prevv[MAXV],preve[MAXV];
int n,V;
int a[MAXN],b[MAXN],k[MAXN];
vector<edge> G[MAXV];
void add_edge(int from,int to,int cap,int cost)
{
    G[from].push_back((edge){to,cap,cost,(int)G[to].size()});
    G[to].push_back((edge){from,0,-cost,(int)G[from].size()-1});
}
int min_cost_flow(int s,int t)
{
    int res=0;
    fill(h,h+V,0);
    int f=0,ans=0;
    for(int t=1;t<=n;t++)
    {
        f++;
        priority_queue<P,vector<P>,greater<P> >que;
        fill(dist,dist+V,INF);
        dist[s]=0;
        que.push(P(0,s));
        while(!que.empty())
        {
            P p=que.top(); que.pop();
            int v=p.second;
            if(dist[v]<p.first) continue;
            for(int i=0;i<(int)G[v].size();i++)
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
        if(f) break;
        ans=max(ans,res);
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i],&b[i],&k[i]);
    V=2*n+2;
    for(int i=1;i<=n;i++) add_edge(0,i,1,0);
    for(int i=n+1;i<=2*n;i++) add_edge(i,2*n+1,1,0);
    for(int i=1;i<=n;i++)
        for(int j=n+1;j<=2*n;j++)
        {
            int days=min(j-n-1,k[i]);
            add_edge(i,j,1,a[i]-days*b[i]);
        }
    printf("%d\n",min_cost_flow(0,2*n+1));
    return 0;
}

