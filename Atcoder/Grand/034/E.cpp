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
string str;
int n,k,a[MAXN];
vector<int> G[MAXN];
int cnt[MAXN],dp[MAXN],low[MAXN];
void dfs(int v,int p)
{
    dp[v]=low[v]=0;
    cnt[v]=(str[v]=='1'?1:0);
    P tmp=P(0,0);
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        dp[v]+=dp[to]+cnt[to];
        cnt[v]+=cnt[to];
        tmp=max(tmp,P(dp[to]+cnt[to],low[to]+cnt[to]));
    }
    if(tmp.S>dp[v]-tmp.F) low[v]=tmp.S-(dp[v]-tmp.F);
    else low[v]=dp[v]&1;
}
int main()
{
    scanf("%d",&n);
    cin>>str;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        u--; v--;
        G[u].push_back(v);G[v].push_back(u);
    }
    int ans=INF;
    for(int i=0;i<n;i++)
    {
        dfs(i,-1);
        if(low[i]==0) ans=min(ans,dp[i]);
    }
    if(ans==INF) puts("-1"); else printf("%d\n",ans/2);
    return 0;
}

