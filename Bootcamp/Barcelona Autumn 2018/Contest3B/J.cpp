/*************************************************************************
    > File Name: J.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-04 01:42:43
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXV 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> P;
struct edge{int to,cap; db cost; int rev;};
db dist[MAXV],h[MAXV];
int prevv[MAXV],preve[MAXV];
int V;
vector<edge> G[MAXV];
void add_edge(int from,int to,int cap,db cost)
{
    G[from].push_back((edge){to,cap,cost,(int)G[to].size()});
    G[to].push_back((edge){from,0,-cost,(int)G[from].size()-1});
}
db min_cost_flow(int s,int t,int f)
{
    db res=0;
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
    }
    return res;
}
int n,s,t;
P a[405];
db dis(int i,int j)
{
    return sqrt((db)(a[i].F-a[j].F)*(a[i].F-a[j].F)+(a[i].S-a[j].S)*(a[i].S-a[j].S));
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",&a[i].F,&a[i].S);
    V=n*2+2;s=n*2;t=n*2+1;
    for(int i=0;i<n;i++)
    {
        add_edge(s,i*2,2,0);
        add_edge(i*2+1,t,1,0);
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(a[i].S>a[j].S) add_edge(i*2,j*2+1,1,dis(i,j));
    db ans=min_cost_flow(s,t,n-1);
    if(ans==-1) puts("-1"); else printf("%.15Lf\n",ans);
    return 0;
}

