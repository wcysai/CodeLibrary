#include<bits/stdc++.h>
#define MAXV 100005
#define MAXE 100005
#define INF 100000000000005
using namespace std;
typedef long long ll;
struct edge{int to;ll cost;};
typedef pair<ll,int> P;
int n,m;
vector<edge> G[MAXV];
ll dist[MAXV],dist2[MAXV];
int sum[MAXV];
void dijkstra(int s)
{
    priority_queue<P,vector<P>,greater<P> > que;
    memset(sum,0,sizeof(sum));
    fill(dist,dist+m,INF);
    fill(dist2,dist2+m,INF);
    dist[s]=0;
    sum[s]=1;
    que.push(P(0,s));
    while(!que.empty())
    {
        P p=que.top(); que.pop();
        int v=p.second;ll d=p.first;
        if(dist2[v]<d) continue;
        for(int i=0;i<G[v].size();i++)
        {
            edge &e=G[v][i];
            ll d2=d+e.cost;
            if(dist[e.to]==d2)
            {
                sum[e.to]+=sum[v];
            }
            else if(dist[e.to]>d2)
            {
                sum[e.to]=sum[v];
                swap(dist[e.to],d2);
                que.push(P(dist[e.to],e.to));
            }
            if(dist2[e.to]>d2&&dist[e.to]<d2)
            {
                dist2[e.to]=d2;
                que.push(P(dist2[e.to],e.to));
            }
        }
    }
    if(sum[n-1]==1) printf("%I64d\n",dist2[n-1]); else printf("%I64d\n",dist[n-1]);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
            G[i].clear();
        for(int i=0;i<m;i++)
        {
            int x,y;
            ll len;
            scanf("%d %d %I64d",&x,&y,&len);
            G[x-1].push_back((edge){y-1,len});
            G[y-1].push_back((edge){x-1,len});
        }
        dijkstra(0);
    }
    return 0;
}
