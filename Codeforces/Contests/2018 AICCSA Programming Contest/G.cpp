/*************************************************************************
    > File Name: G.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-01 18:45:37
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge
{
    int to,cost;
};
int T,n,q;
ll ans;
vector<edge> G[MAXN];
int cnt[MAXN];
void dfs(int v,int p,int cost)
{
    for(auto e:G[v])
    {
        if(e.to==p) continue;
        dfs(e.to,v,e.cost);
        cnt[v]+=cnt[e.to];
    }
    ans+=1LL*abs(cnt[v])*cost;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);for(int i=1;i<=n;i++) G[i].clear();
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n-1;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            G[u].push_back((edge){v,w});G[v].push_back((edge){u,w});
        }
        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            cnt[u]--;cnt[v]++;
        }
        ans=0;
        dfs(1,0,0);
        printf("%lld\n",ans);
    }
    return 0;
}

