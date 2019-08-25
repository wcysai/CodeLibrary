#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T;
ll dp[40];
ll n,a,b;
ll solve(ll n)
{
    if(n>=32) return (((18LL*((n/2)*(n/2)%MOD)%MOD*a%MOD))%MOD+7LL*solve(n/2)%MOD)%MOD;
    return dp[n]%MOD;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d%I64d%I64d",&n,&a,&b);
        memset(dp,0,sizeof(dp));
        dp[1]=b;
        for(int i=2;i<=31;i++) dp[i]=min(18*i*i*a/4+7*dp[i/2],i*i*i*b+i*i*(i-1)*a);
        cout<<solve(n)<<endl;
    }
    return 0;
}
