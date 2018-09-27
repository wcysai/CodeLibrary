/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-27 19:57:18
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXV 1005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{ll to,need,cost;};
ll T,V,E,k;
vector<edge> G[MAXV];
ll d[MAXV],cnt[MAXV],num[MAXV];
bool inque[MAXV];
bool used[MAXV];
queue<ll> que;
bool f;
void spfa(ll s)
{
    memset(cnt,0,sizeof(cnt));
    fill(d+1,d+V+1,-INF);
    fill(inque+1,inque+V+1,false);
    d[s]=k;
    while(!que.empty()) que.pop();
    que.push(s);
    inque[s]=true;
    while(!que.empty())
    {
        ll u=que.front();
        que.pop();
        for(ll i=0;i<(int)G[u].size();i++)
        {
            if(d[u]>=G[u][i].need&&d[u]+G[u][i].cost>d[G[u][i].to])
            {
                d[G[u][i].to]=d[u]+G[u][i].cost;
                if(!inque[G[u][i].to]&&G[u][i].to!=V)
                {
                    inque[G[u][i].to]=true;
                    cnt[G[u][i].to]++;
                    if(cnt[G[u][i].to]>V) {f=false; return;}
                    que.push(G[u][i].to);
                }
            }
        }
        inque[u]=false;
    }
}
int main()
{
    scanf("%lld",&T);
    while(T--)
    {
        f=true;
        scanf("%lld%lld%lld",&V,&E,&k);
        for(ll i=1;i<=V;i++) G[i].clear();
        for(ll i=1;i<=V;i++) scanf("%lld",&num[i]);
        k+=num[1];
        for(ll i=0;i<E;i++)
        {
            ll u,v,w;
            scanf("%lld%lld%lld",&u,&v,&w);
            G[u].push_back((edge){v,w,num[v]-w});
            G[v].push_back((edge){u,w,num[u]-w});
        }
        memset(used,false,sizeof(used));
        used[1]=true;
        queue<int> q;
        q.push(1);
        while(!q.empty())
        {
            int v=q.front();q.pop();
            for(int i=0;i<(int)G[v].size();i++)
            {
                int to=G[v][i].to;
                if(!used[to]) {used[to]=true; q.push(to);}
            }
        }
        if(!used[V]) {puts("-2"); continue;}
        spfa(1);
        //for(ll i=1;i<=V;i++) printf("%lld\n",d[i]);
        if(!f) puts("-1");
        else if(d[V]==-INF) puts("-2");
        else printf("%lld\n",d[V]);
    }
    return 0;
}

