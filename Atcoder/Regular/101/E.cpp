#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
vector<int> G[MAXN];
int f[MAXN];
int dp[MAXN][MAXN][2],sz[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
//dp[i][j][0/1]
//in the subtree of i
//number of matchings if we the connected component with i is j
//such that the parity of removed edges is 0/1
void dfs(int v,int p)
{
    sz[v]=1;
    dp[v][1][0]=1;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        for(int i=sz[v];i>=1;i--)
        {
            int save[2]={0,0};
            for(int j=sz[to];j>=1;j--)
            {
                for(int k1=0;k1<2;k1++)
                {
                    if(!dp[v][i][k1]) continue;
                    for(int k2=0;k2<2;k2++)
                    {
                        if(!dp[to][j][k2]) continue;
                        add(dp[v][i+j][(k1+k2)&1],1LL*dp[v][i][k1]*dp[to][j][k2]%MOD);
                        add(save[(k1+k2+1)&1],1LL*dp[v][i][k1]*dp[to][j][k2]%MOD*f[j]%MOD);
                    }
                }
            }
            dp[v][i][0]=save[0];dp[v][i][1]=save[1];
        }
        add(sz[v],sz[to]);
    }
}
int main()
{
    f[0]=1;
    for(int i=2;i<=5000;i+=2) f[i]=1LL*(i-1)*f[i-2]%MOD;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    memset(dp,0,sizeof(dp));
    dfs(1,0);
    int ans=0;
    for(int i=1;i<=n;i++) add(ans,1LL*dp[1][i][0]*f[i]%MOD);
    for(int i=1;i<=n;i++) dec(ans,1LL*dp[1][i][1]*f[i]%MOD);
    printf("%d\n",ans);
    return 0;
}

