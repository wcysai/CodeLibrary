#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000000000000LL
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<int> G[MAXN];
int n,p[MAXN],dp[MAXN][MAXN],sz[MAXN],ndp[MAXN];
int fact[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
void dfs(int v)
{
    sz[v]=0;
    dp[v][0]=1;
    for(auto to:G[v])
    {
        dfs(to);
        for(int i=0;i<=sz[v]+sz[to];i++) ndp[i]=0;
        for(int i=0;i<=sz[v];i++)
            for(int j=0;j<=sz[to];j++)
                add(ndp[i+j],1LL*dp[v][i]*dp[to][j]%MOD);
        for(int i=0;i<=sz[v]+sz[to];i++) dp[v][i]=ndp[i];
        sz[v]+=sz[to];
    }
    for(int i=0;i<=sz[v]+1;i++) ndp[i]=0;
    for(int i=0;i<=sz[v];i++) {add(ndp[i],dp[v][i]); add(ndp[i+1],1LL*dp[v][i]*(sz[v]-i)%MOD);}
    for(int i=0;i<=sz[v]+1;i++) dp[v][i]=ndp[i];
    sz[v]++;
}
int main()
{
    fact[0]=1;
    for(int i=1;i<=2000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&p[i]);
        G[p[i]].push_back(i);
    }
    dfs(1);
    int ans=0;
    for(int i=0;i<=n;i++)
    {
        if(i&1) dec(ans,1LL*dp[1][i]*fact[n-i]%MOD);
        else add(ans,1LL*dp[1][i]*fact[n-i]%MOD);
    }
    printf("%d\n",ans);
    return 0;
}