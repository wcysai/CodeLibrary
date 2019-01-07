#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 17
#define MAXM 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN][MAXN];
ll res[MAXM],dp[MAXM];
ll solve(ll mask)
{
    if(mask==0) return mask;
    if(dp[mask]!=-1) return dp[mask];
    ll ans=0;
    ll sup=mask;
    do
    {
        if(sup) ans=max(ans,solve(mask^sup)+res[sup]);
        sup=(sup-1)&mask;
    }while(sup!=mask);
    return dp[mask]=ans;
}
int main()
{
    scanf("%lld",&n);
    for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)
            scanf("%lld",&a[i][j]);
    for(ll mask=0;mask<(1<<n);mask++)
    {
        for(ll i=0;i<n;i++)
            for(ll j=i+1;j<n;j++)
                if((mask&(1<<i))&&(mask&(1<<j))) res[mask]+=a[i][j];
    }
    memset(dp,-1,sizeof(dp));
    printf("%lld\n",solve((1<<n)-1));
    return 0;
}

