/*************************************************************************
    > File Name: City Attractions.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-09 17:13:54
 ************************************************************************/

#pragma GCC optimize(3)
#pragma comment(linker,"/STACK:102400000,102400000") 
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000001
#define MOD 1000000007
#define F first
#define S second
#define min __min
using namespace std;
typedef long long ll;
struct P
{
    ll x,y;
    P(){}
    P(int _x,int _y) {x=_x;y=_y;}
    const bool operator < (const P &v) const
    {
        if(x!=v.x) return x>v.x;
        return y<v.y;
    }
};
P min(P x,P y) {return x<y?x:y;}
int n;
ll k;
int a[MAXN];
P f[MAXN],g[MAXN];
vector<int> G[MAXN];
void dfs(ll v,ll p)
{
    f[v]=P(-INF,INF);
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p) continue; 
        dfs(to,v);
        f[v]=min(f[v],P(a[to]-1,to));
        f[v]=min(f[v],P(f[to].x-1,f[to].y));
    }
}
void dfs2(ll v,ll p)
{
    P p1(-INF,INF),p2(-INF,INF);
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p) continue;
        g[to]=P(g[v].x-1,g[v].y);g[to]=min(g[to],P(a[v]-1,v));
        P fi=min(f[to],P(a[to],to));
        if(fi<p1) {p2=p1; p1=fi;}
        else if(fi<p2) {p2=fi;}
    }
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p) continue;
        P fi=min(f[to],P(a[to],to));
        if(fi.y!=p1.y&&p1.x!=-INF) g[to]=min(g[to],P(p1.x-2,p1.y));
        if(fi.y!=p2.y&&p2.x!=-INF) g[to]=min(g[to],P(p2.x-2,p2.y));
    }
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p) continue;
        dfs2(to,v);
    }
}
int vis[MAXN];
int ord[MAXN],tot;
int main()
{
    scanf("%d%lld",&n,&k);k++;
    for(ll i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) G[i].clear();
    for(ll i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    dfs(1,0);g[1]=P(-INF,INF);dfs2(1,0);
    //for(ll i=1;i<=n;i++) printf("%lld %lld\n",f[i].x,f[i].y);
    //for(ll i=1;i<=n;i++) printf("%lld %lld\n",g[i].x,g[i].y);
    for(ll i=1;i<=n;i++) f[i]=min(f[i],g[i]);
    //for(ll i=1;i<=n;i++) printf("%lld %lld\n",f[i].x,f[i].y);
    int now=1;
    while(true)
    {
        ++tot;assert(tot<=300000);
        if(tot==k)
        {
            printf("%d\n",now);
            return 0;
        }
        if(vis[now])
        {
            int cyc=tot-vis[now];
            ll rem=(k-tot)%cyc;
            printf("%d\n",ord[vis[now]+rem]);
            return 0;
        }
        vis[now]=tot;
        ord[tot]=now;
        now=f[now].y;
    }
    return 0;
}

