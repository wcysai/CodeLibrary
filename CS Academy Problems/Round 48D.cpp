#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll bit[MAXN+1],n;
P a[MAXN];
ll dp[MAXN];
vector<ll> save[MAXN];
vector<P> res[MAXN];
ll sum(ll i)
{
    ll s=0;
    while(i>0)
    {
        s=(s+bit[i])%MOD;
        i-=i&-i;
    }
    return s;
}
void add(ll i,ll x)
{
    while(i<MAXN)
    {
        bit[i]=(bit[i]+x)%MOD;
        i+=i&-i;
    }
}
int main()
{
    scanf("%lld",&n);
    memset(bit,0,sizeof(bit));
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
        scanf("%lld%lld",&a[i].F,&a[i].S);
    sort(a,a+n);
    for(int i=0;i<MAXN;i++)
    {
        save[i].clear();
        res[i].clear();
    }
    for(int i=0;i<n;i++)
        save[a[i].F].push_back(a[i].S);
    ll ans=0;
    for(int i=1;i<MAXN;i++)
    {
        for(int j=0;j<save[i].size();j++)
        {
            ll x=sum(MAXN-1)-sum(save[i][j])+1;
            if(x<0) x+=MOD;
            dp[i]=(dp[i]+x)%MOD;
            res[i].push_back(P(save[i][j],x));
        }
        for(int j=0;j<res[i].size();j++)
            add(res[i][j].F,res[i][j].S);
    }
    for(int i=1;i<MAXN;i++)
        ans=(ans+dp[i])%MOD;
    printf("%lld\n",ans);
    return 0;
}

