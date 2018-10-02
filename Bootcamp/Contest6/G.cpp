/*************************************************************************
    > File Name: G.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-02 19:39:23
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXV 3005
#define INF 1e12
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double db;
struct edge{int to; db exp,t;};
typedef pair<db,int> P;
int T,V,E,s,t;
vector<edge> G[MAXV];
db d[MAXV];
db dp[MAXV];
db solve(int v)
{
    if(v==t) return dp[v]=0;
    if(dp[v]!=-INF) return dp[v];
    dp[v]=-1e12;
    for(int i=0;i<(int)G[v].size();i++)
    {
        edge &e=G[v][i];
        if(d[e.to]<d[v]) dp[v]=max(dp[v],solve(e.to)+e.exp);
    }
    return dp[v];
}
void dijkstra(int s)
{
    priority_queue<P,vector<P>,greater<P> > que;
    for(int i=0;i<V;i++) d[i]=1e9;
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty())
    {
        P p=que.top(); que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for(int i=0;i<(int)G[v].size();i++)
        {
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.t)
            {
                d[e.to]=d[v]+e.t;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&V,&E);
        for(int i=0;i<V;i++) G[i].clear();
        scanf("%d%d",&s,&t);
        for(int i=0;i<E;i++)
        {
            int u,v;db exp,tt;
            scanf("%d%d%Lf%Lf",&u,&v,&exp,&tt);
            G[u].push_back((edge){v,exp,tt});
            G[v].push_back((edge){u,exp,tt});
        }
        dijkstra(t);
        db l=0,r=1e4+1;
        for(int i=0;i<200;i++)
        {
            db mid=(l+r)/2;
            for(int i=0;i<V;i++) dp[i]=-INF;
            for(int i=0;i<V;i++)
                for(int j=0;j<(int)G[i].size();j++)
                    G[i][j].exp-=mid*G[i][j].t;
            for(int i=0;i<V;i++) solve(i);
            if(dp[s]>0) l=mid; else r=mid;
            for(int i=0;i<V;i++)
                for(int j=0;j<(int)G[i].size();j++)
                    G[i][j].exp+=mid*G[i][j].t;
        }
        printf("%.4Lf\n",l);
    }
    return 0;
}

