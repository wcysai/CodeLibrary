#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,c[MAXN],p[MAXN],fa[MAXN];
int num[MAXN];//number of -1 edges from fa[i] to i
vector<int> G[MAXN];
P dp[MAXN];
int ans;
void update_info(int v)
{
    if(c[v]) dp[v]=P(0,v); else dp[v]=P(INF,v); 
    for(auto to:G[v])
    {
        P p=dp[to];
        if(num[to]>0) p.F--; else p.F++;
        dp[v]=min(dp[v],p);
    }
}
void augment(int v)
{
    int u=v;
    P res=P(0,0); int cnt=0,dis=INF;
    while(u!=0)
    {
        if(dp[u].F+cnt<dis)
        {
            dis=dp[u].F+cnt;
            res=P(u,dp[u].S);
        }
        if(num[u]<0) cnt--; else cnt++;
        u=u/2;
    }
    ans+=dis;
    c[res.S]--; 
    u=v; while(u!=res.F) {num[u]++; u/=2;}
    u=res.S; while(u!=res.F) {num[u]--; u/=2;}
    u=v; while(u) {update_info(u); u/=2;}
    u=res.S; while(u) {update_info(u); u/=2;}
}
int main()
{
    freopen("mole.in","r",stdin);
    freopen("mole.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++) G[i/2].push_back(i);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=m;i++) scanf("%d",&p[i]);
    for(int i=n;i>=1;i--) update_info(i);
    for(int i=1;i<=m;i++) 
    {
        augment(p[i]);
        printf("%d%c",ans,i==m?'\n':' ');
    }
    return 0;
}

