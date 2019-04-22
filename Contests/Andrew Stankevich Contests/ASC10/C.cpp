#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n;
ll dp[MAXN][MAXN],sum[MAXN];
int opt[MAXN][MAXN];
ll a[MAXN];
string ans[MAXN];
void solve(ll l,ll r)
{
    if(l>=r) return;
    ll pos=opt[l][r];
    assert(pos>=l&&pos<=r);
    for(ll i=l;i<=pos;i++) ans[i]+="0";
    for(ll i=pos+1;i<=r;i++) ans[i]+="1";
    solve(l,pos); solve(pos+1,r);
}
int main()
{
    freopen("codes.in","r",stdin);
    freopen("codes.out","w",stdout);
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(ll i=1;i<=n;i++) dp[i][i]=0,opt[i][i]=i;
    for(ll len=2;len<=n;len++)
    {
        for(ll l=1;l+len-1<=n;l++)
        {
            ll r=l+len-1;
            dp[l][r]=INF,opt[l][r]=-1;
            for(ll k=opt[l][r-1];k<=opt[l+1][r];k++)
            {
                if(dp[l][k]+dp[k+1][r]+sum[r]-sum[l-1]<dp[l][r])
                {
                    dp[l][r]=dp[l][k]+dp[k+1][r]+sum[r]-sum[l-1];
                    opt[l][r]=k;
                }
            }
        }
    }
    solve(1,n);
    for(ll i=1;i<=n;i++) cout<<ans[i]<<endl;
    return 0;
}
