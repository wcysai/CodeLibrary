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
int n;
int pos[MAXN],val[MAXN];
ll dp[MAXN][5];
void upd(ll &a,ll b) {a=max(a,b);}
int main()
{
    scanf("%d",&n);
    memset(pos,-1,sizeof(pos));
    for(int i=1;i<=n;i++) 
    {
        int t,x,a;
        scanf("%d%d%d",&t,&x,&a);
        pos[t]=x; val[t]=a;
    }
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for(int i=0;i<100000;i++)
    {
        for(int j=0;j<=4;j++)
        {
            if(dp[i][j]==-1) continue;
            upd(dp[i+1][j],dp[i][j]+(pos[i+1]==j?val[i+1]:0));
            if(j) upd(dp[i+1][j-1],dp[i][j]+(pos[i+1]==j-1?val[i+1]:0));
            if(j!=4) upd(dp[i+1][j+1],dp[i][j]+(pos[i+1]==j+1?val[i+1]:0));
        }
    }
    ll ans=0;
    for(int i=0;i<=4;i++) upd(ans,dp[100000][i]);
    printf("%lld\n",ans);
    return 0;
}

