#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<assert.h>
#define MAXN 105
#define MAXM 2005
#define MAXV 80005
#define INF 1000000000
using namespace std;
typedef long long ll;
struct edge{ll to,cap,rev;};
ll V,n,m;
char grid[MAXN][MAXM];
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
    scanf("%lld%lld",&n,&m);
    V=n*m+2;
    for(ll i=0;i<V;i++)
        G[i].clear();
    for(ll i=0;i<n;i++)
    {
        scanf("%s",grid[i]);
        assert(strlen(grid[i])==m);
    }
    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
        {
            if(grid[i][j]=='H') add_edge(n*m,i*m+j,4);
            if(grid[i][j]=='X') add_edge(i*m+j,n*m+1,4);
            ll ni=i+1,nj=j;
            if(ni<n)
            {
                    add_edge(i*m+j,ni*m+nj,1);
                    add_edge(ni*m+nj,i*m+j,1);
            }
            ni=i,nj=j+1;
            if(nj<m)
            {
                    add_edge(i*m+j,ni*m+nj,1);
                    add_edge(ni*m+nj,i*m+j,1);
            }
        }
    printf("%lld\n",max_flow(n*m,n*m+1));
    return 0;
}
