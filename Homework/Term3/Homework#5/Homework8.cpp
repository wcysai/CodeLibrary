#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#define MAXV 2005
#define MAXE 200005
#define INF 1000000000000
using namespace std;
typedef long long ll;
struct edge{ll to,cap,rev;};
ll V,E,T;
struct mem{ll x,y,z,r;}save[MAXE];
vector<edge> G[MAXV];
ll level[MAXV];
ll iter[MAXV];
void add_edge(ll from,ll to,ll cap)
{
    G[from].push_back((edge){to,cap,G[to].size()});
    G[to].push_back((edge){from,0,G[from].size()-1});
}
void bfs(ll s)
{
    memset(level,-1,sizeof(level));
    queue<ll> que;
    level[s]=0;
    que.push(s);
    while(!que.empty())
    {
        ll v=que.front(); que.pop();
        for(ll i=0;i<G[v].size();i++)
        {
            edge &e=G[v][i];
            if(e.cap>0&&level[e.to]<0)
            {
                level[e.to]=level[v]+1;
                que.push(e.to);
            }
        }
    }
}

ll dfs(ll v,ll t,ll f)
{
    if(v==t) return f;
    for(ll &i=iter[v];i<G[v].size();i++)
    {
        edge &e=G[v][i];
        if(level[v]<level[e.to]&&e.cap>0)
        {
            ll d=dfs(e.to,t,min(f,e.cap));
            if(d>0)
            {
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
ll max_flow(ll s,ll t)
{
    ll flow=0;
    for(;;)
    {
        bfs(s);
        if(level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        ll f;
        while((f=dfs(s,t,INF))>0)
          flow+=f;
    }
}
int main()
{
    scanf("%I64d",&T);
    ll cnt=0;
    while(T--)
    {
        cnt++;
        scanf("%I64d %I64d",&V,&E);
        for(ll i=0;i<V;i++)
            G[i].clear();
        ll p=0;
        for(ll i=0;i<E;i++)
        {
            scanf("%I64d %I64d %I64d %I64d",&save[i].x,&save[i].y,&save[i].z,&save[i].r);
            if(save[i].r) p++;
        }
        E+=p;
        for(ll i=0;i<E;i++)
        {
            add_edge(save[i].x,save[i].y,save[i].z*(E+1)+1);
            if(save[i].r) add_edge(save[i].y,save[i].x,save[i].z*(E+1)+1);
        }
        printf("Case %I64d: %I64d\n",cnt, max_flow(0,V-1)%(E+1));
    }
    return 0;
}


