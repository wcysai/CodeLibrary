#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m;
ll dp[61][61];
int main()
{
    scanf("%lld%lld",&n,&m);
    if(n>60) {puts("0"); return 0;}
    for(int i=0;i<=60;i++) 
    {
        ll l=(1LL<<i),r=min((1LL<<(i+1))-1,m);
        if(l<=r) dp[1][i]=(r-l+1)%MOD; else dp[1][i]=0;
    }
    for(int i=1;i<n;i++)
        for(int j=0;j<=60;j++)
            for(int k=j+1;k<=60;k++)
                (dp[i+1][k]+=dp[i][j]*dp[1][k])%=MOD;
    ll ans=0;
    for(int i=0;i<=60;i++) (ans+=dp[n][i])%=MOD;
    printf("%lld\n",ans);
    return 0;
}

