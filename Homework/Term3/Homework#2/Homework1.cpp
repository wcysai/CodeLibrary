#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#define MAXV 1005
#define MAXE 100005
#define INF 1000000000
using namespace std;
struct edge{int to,len,cost;};
typedef pair<int,int> P;
int V,E;
vector<edge> G[MAXV];
int d[MAXV],c[MAXV];
void dijkstra(int s)
{
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d,d+V,INF);
    fill(c,c+V,INF);
    d[s]=0;
    c[s]=0;
    que.push(P(0,s));
    while(!que.empty())
    {
        P p=que.top(); que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for(int i=0;i<G[v].size();i++)
        {
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.len)
            {
                d[e.to]=d[v]+e.len;
                c[e.to]=c[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
            else if(d[e.to]==d[v]+e.len&&c[e.to]>c[v]+e.cost)
            {
                c[e.to]=c[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
    return;
}
int main()
{
    while(scanf("%d %d",&V,&E)==2)
    {
        if(V==0&&E==0) break;
        for(int i=0;i<V;i++)
            G[i].clear();
        int a,b,q,p,s,t;
        for(int i=0;i<E;i++)
        {
            scanf("%d %d %d %d",&a,&b,&q,&p);
            a--;
            b--;
            G[a].push_back((edge){b,q,p});
            G[b].push_back((edge){a,q,p});
        }
        scanf("%d %d",&s,&t);
        dijkstra(s-1);
        printf("%d %d\n",d[t-1],c[t-1]);
    }
    return 0;
}


