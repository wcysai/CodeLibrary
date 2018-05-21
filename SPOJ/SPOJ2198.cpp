#include<bits/stdc++.h>
#define MAXK 20
#define MAXN 200300
#define INF 1e18
using namespace std;
typedef long long ll;
ll n,k,w[MAXN],dp[MAXK][MAXN],sum[MAXN],cost[MAXN];
ll cal(ll i,ll j)
{
    return cost[j]-cost[i-1]-(n-j+1)*(sum[j]-sum[i-1]);
}
void compute(ll i,ll jleft,ll jright,ll kleft,ll kright)
{
    ll jmid=(jleft+jright)/2;
    ll bestk=-1;
    dp[i][jmid]=INF;
    for(ll p=kleft;p<jmid;p++)
    {
        if(dp[i-1][p]+cal(p+1,jmid)<dp[i][jmid])
        {
            dp[i][jmid]=dp[i-1][p]+cal(p+1,jmid);
            bestk=p;
        }
    }
    if(jleft<=jmid-1) compute(i,jleft,jmid-1,kleft,bestk);
    if(jmid+1<=jright) compute(i,jmid+1,jright,bestk,kright);
}
int main()
{
    scanf("%I64d%I64d",&n,&k);
    for(ll i=1;i<=n;i++)
        scanf("%I64d",&w[n+1-i]);
    cost[0]=0;
    sum[0]=0;
    for(ll i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+w[i];
        cost[i]=cost[i-1]+w[i]*(n-i+1);
    }
    for(ll i=1;i<=n;i++)
        dp[1][i]=cal(1,i);
    for(ll i=2;i<=k;i++)
        compute(i,i,n,i-1,n-1);
    printf("%I64d\n",dp[k][n]);
    return 0;
}
