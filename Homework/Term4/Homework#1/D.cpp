#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define MAXV 5000
#define MAXE 100000
#define INF 100000000
using namespace std;
typedef pair<int,int> P;
struct edge
{
    int to;
    int cost;
};
vector<edge> G[MAXE];
int main()
{
    int V,E;
    scanf("%d %d",&V,&E);
    for(int i=0;i<E;i++)
    {
        int s;
        edge x;
        scanf("%d %d %d",&s,&x.to,&x.cost);
        s--;
        x.to--;
        G[s].push_back(x);
        swap(s,x.to);
        G[s].push_back(x);
    }
    int dist[MAXV];
    int dist2[MAXV];
    priority_queue<P,vector<P>,greater<P> >que;
    fill(dist,dist+V,INF);
    fill(dist2,dist2+V,INF);
    dist[0]=0;
    que.push(P(0,0));
    while(!que.empty())
    {
        P p=que.top();que.pop();
        int v=p.second,d=p.first;
        if(dist2[v]<d) continue;
        for(int i=0;i<G[v].size();i++)
        {
            edge &e=G[v][i];
        int d2=d+e.cost;
        if(dist[e.to]>d2)
        {
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
    printf("%d\n",dist2[V-1]);
    return 0;
}