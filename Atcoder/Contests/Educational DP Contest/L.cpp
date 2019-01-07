#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN];
ll dp[MAXN][MAXN];
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(ll i=1;i<=n;i++) dp[i][i]=a[i];
    for(ll l=2;l<=n;l++)
    {
        for(ll i=1;i+l-1<=n;i++)
        {
            ll j=i+l-1;
            dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
        }
    }
    printf("%lld\n",dp[1][n]);
    return 0;
}

