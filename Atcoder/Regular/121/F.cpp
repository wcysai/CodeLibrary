#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],b[MAXN];
vector<int> G[MAXN];
int dp[MAXN][2];//dp[i][0/1]: subtree of i, number of ways s.t. the connected component of i has value 0/1
int tmp[2];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
void dfs(int v,int p)
{
    dp[v][0]=dp[v][1]=1;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        tmp[0]=tmp[1]=0;
        //add edge OR
        add(tmp[0],1LL*dp[v][0]*dp[to][0]%MOD);
        add(tmp[1],1LL*dp[v][1]*dp[to][0]%MOD);
        //add edge AND
        add(tmp[0],1LL*dp[v][0]*(dp[to][0]+dp[to][1])%MOD);
        add(tmp[0],1LL*dp[v][1]*dp[to][0]%MOD);
        add(tmp[1],1LL*dp[v][1]*dp[to][1]%MOD);
        dp[v][0]=tmp[0]; dp[v][1]=tmp[1];
    }
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
    int ans=pow_mod(2,2*n-1);
    dec(ans,dp[1][0]);
    printf("%d\n",ans);
    return 0;
}