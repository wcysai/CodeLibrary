#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
vector<int> G[MAXN];
int f[MAXN],g[MAXN];//f/g: no/have chain upwards 
int dp[3][MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dfs(int v,int p)
{
    vector<P> vv;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        vv.push_back(P(f[to],g[to]));
    }
    int sz=(int)vv.size();
    for(int i=0;i<3;i++) 
        for(int j=0;j<=sz;j++) 
            dp[i][j]=0;
    dp[0][0]=1;
    for(int i=0;i<3;i++) 
    {
        for(int j=0;j<sz;j++)
        {
            if(!dp[i][j]) continue;
            add(dp[i][j+1],1LL*dp[i][j]*vv[j].F%MOD);
            if(i!=2) add(dp[i+1][j+1],1LL*dp[i][j]*vv[j].S%MOD);
        }
    }
    f[v]=g[v]=0;
    add(f[v],dp[1][sz]%MOD);
    add(f[v],dp[2][sz]%MOD);
    g[v]=dp[0][sz];
    add(g[v],dp[1][sz]);
    printf("v=%d p=%d f=%d g=%d dp0=%d dp1=%d dp2=%d\n",v,p,f[v],g[v],dp[0][sz],dp[1][sz],dp[2][sz]);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0);
    printf("%lld\n",2LL*f[1]%MOD);
    return 0;
}

