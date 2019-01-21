/*************************************************************************
    > File Name: J.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-26 20:29:13
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXV 100005
#define MAXE 100005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,int> P;
int V,E,S,T;
vector<int> G[MAXV];
int d[MAXV][2];
int prime[2*MAXV];
bool is_prime[2*MAXV];
void sieve(int n)
{
    int p=0;
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
}
void dijkstra(int s)
{
    priority_queue<P,vector<P>,greater<P> > que;
    for(int i=1;i<=V;i++) d[i][0]=d[i][1]=INF;
    d[s][0]=0;
    que.push(P(0,s));
    while(!que.empty())
    {
        P p=que.top(); que.pop();
        int v=p.S;
        if(d[v][p.F&1]<p.F) continue;
        int parity=(p.F+1)&1;
        for(int i=0;i<(int)G[v].size();i++)
        {
            int to=G[v][i];
            if(d[to][parity]>p.F+1)
            {
                d[to][parity]=p.F+1;
                que.push(P(d[to][parity],to));
            }
        }
    }
}
int main()
{
    sieve(200000);
    scanf("%d%d%d%d",&V,&E,&S,&T);
    for(int i=0;i<E;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    dijkstra(S);
    if(d[T][0]>2&&d[T][1]==INF) puts("-1");
    else if(d[T][0]==2) puts("2");
    else 
    {
        int now=d[T][1];
        while(!is_prime[now]) now+=2;
        printf("%d\n",now);
    }
    return 0;
}
