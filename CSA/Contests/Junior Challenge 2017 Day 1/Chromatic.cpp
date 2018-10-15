/*************************************************************************
    > File Name: Chromatic.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-10 00:22:49
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXV 305
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
struct edge{ll to,cost;};
typedef pair<int,int> P;
ll V,E,K;
vector<edge> G[MAXV];
vector<ll> GG[MAXV];
ll d[MAXV],dp[MAXV][MAXV],cnt[MAXV][MAXV],ways[MAXV][MAXV];
vector<ll> ord;
ll color[MAXV];
ll ans;
void dfs(ll v)
{
    color[v]=1;
    for(auto to:GG[v]) if(color[to]==0) dfs(to);
    color[v]=2;
    ord.push_back(v);
}
void dijkstra(ll s)
{
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d+1,d+V+1,INF);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty())
    {
        P p=que.top(); que.pop();
        ll v=p.second;
        if(d[v]<p.first) continue;
        for(ll i=0;i<(int)G[v].size();i++)
        {
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost)
            {
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
ll solve1(ll id,ll k)
{
    if(k==0) return dp[id][k]=cnt[ord[id]][V];
    if(id==(int)ord.size()-1) return dp[id][k]=0;
    if(dp[id][k]!=-1) return dp[id][k];
    ll cur=0;
    for(ll i=id+1;i<(int)ord.size();i++)
        cur=max(cur,solve1(i,k-1)*cnt[ord[id]][ord[i]]);
    return dp[id][k]=cur;
}
ll solve2(ll id,ll k)
{
    if(k==0) return ways[id][k]=1;
    if(id==(int)ord.size()-1) return ways[id][k]=0;
    if(ways[id][k]!=-1) return ways[id][k];
    ll cur=0;
    for(ll i=id+1;i<(int)ord.size();i++)
        if(dp[id][k]==dp[i][k-1]*cnt[ord[id]][ord[i]])
            cur=(cur+solve2(i,k-1))%MOD;
    return ways[id][k]=cur;
}
int main()
{
    scanf("%lld%lld%lld",&V,&E,&K);
    for(ll i=0;i<E;i++)
    {
        ll u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        G[u].push_back((edge){v,w});
        G[v].push_back((edge){u,w});
    }
    dijkstra(1);
    for(ll i=1;i<=V;i++)
        for(ll j=0;j<(int)G[i].size();j++)
        {
            edge &e=G[i][j];
            if(d[i]+e.cost==d[e.to]) 
            {
                GG[i].push_back(e.to);
                //printf("%lld %lld\n",i,e.to);
            }
        }
    memset(color,0,sizeof(color));
    dfs(1);reverse(ord.begin(),ord.end());
    for(ll i=(int)ord.size()-1;i>=0;i--)
    {
        ll v=ord[i];
        cnt[v][v]=1;
        for(ll j=i-1;j>=0;j--)
        {
            ll u=ord[j];
            for(ll k=0;k<(int)GG[u].size();k++)
            {
                ll to=GG[u][k];
                cnt[u][v]+=cnt[to][v];
            }
        }
    }
    /*for(ll i=1;i<=V;i++)
    {
        for(ll j=1;j<=V;j++)
            printf("%lld ",cnt[i][j]);
        printf("\n");
    }*/
    memset(dp,-1,sizeof(dp));
    for(ll i=0;i<(int)ord.size();i++) 
        for(ll j=0;j<=K-1;j++)
            solve1(i,j);
    ans=solve1(0,K-1);
    memset(ways,-1,sizeof(ways));
    for(ll i=0;i<(int)ord.size();i++)
        for(ll j=0;j<=K-1;j++)
            solve2(i,j);
    ll res=0;
    //for(auto it:ord) printf("%lld ",it);
    //puts("");
    /*for(int i=0;i<(int)ord.size();i++)
    {
        for(int j=0;j<=K-1;j++)
            printf("%lld ",dp[i][j]);
        printf("\n");
    }
    for(int i=0;i<(int)ord.size();i++)
    {
        for(int j=0;j<=K-1;j++)
            printf("%lld ",ways[i][j]);
        printf("\n");
    }*/
    for(ll i=0;i<(int)ord.size();i++) if(solve1(i,K-1)*cnt[1][ord[i]]==ans)res=(res+solve2(i,K-1))%MOD;
    printf("%lld %lld\n",ans,res);
    return 0;
}

