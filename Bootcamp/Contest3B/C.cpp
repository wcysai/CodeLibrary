/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-02 04:32:32
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXV 300005
#define INF 1000000000000000000LL 
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{ll id,to,cap,flow,rev,type;};
ll V,E;
vector<edge> G[MAXV];
ll level[MAXV];
ll iter[MAXV];
void add_edge(ll id,ll from,ll to,ll cap)
{
    G[from].push_back((edge){id,to,cap,0,(int)G[to].size(),0});
    G[to].push_back((edge){id,from,0,0,(int)G[from].size()-1,1});
}
void bfs(ll s)
{
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty())
    {
        ll v=que.front(); que.pop();
        for(ll i=0;i<(int)G[v].size();i++)
        {
            edge &e=G[v][i];
            if(e.cap-e.flow>0&&level[e.to]<0)
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
    for(ll &i=iter[v];i<(int)G[v].size();i++)
    {
        edge &e=G[v][i];
        if(level[v]<level[e.to]&&e.cap>e.flow)
        {
            ll d=dfs(e.to,t,min(f,e.cap-e.flow));
            if(d>0)
            {
                e.flow+=d;
                G[e.to][e.rev].flow-=d;
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
bool vis[MAXV];
vector<ll> used;
ll dfs2(ll v,ll f=INT_MAX) 
{
    if(v==V) return f; 
    for(ll i=0;i<(int)G[v].size();i++)
    {
        edge &e=G[v][i];
        if(vis[e.id]) continue;
        if(e.flow>0)
        {
            vis[e.id]=true;
            used.push_back(e.id);
            ll flow=dfs2(e.to,min(f,e.flow));
            e.flow-=flow;
            G[e.to][e.rev].flow+=flow;
            return flow;
        }
    }
    return 0;//should not reach here
}
vector<ll> flow;
vector<ll> num;
vector<vector<ll> > ans;
int main()
{
    scanf("%lld%lld",&V,&E);
    for(ll i=1;i<=E;i++)
    {
        ll u,v,c;
        scanf("%lld%lld%lld",&u,&v,&c);
        add_edge(i,u,v,c);
    }
    max_flow(1,V);
    memset(vis,false,sizeof(vis));
    ll res=dfs2(1);
    while(res)
    {
        flow.push_back(res);
        num.push_back((ll)used.size());
        ans.push_back(used);
        for(auto it:used) vis[it]=false;
        used.clear();
        res=dfs2(1);
    }
    printf("%lld\n",(ll)ans.size());
    for(ll i=0;i<(ll)ans.size();i++)
    {
        printf("%lld ",flow[i]);
        printf("%lld",num[i]);
        for(ll j=0;j<(ll)ans[i].size();j++)
            printf(" %lld",ans[i][j]);
        puts("");
    }
    return 0;
}

