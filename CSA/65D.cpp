#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,q;
P a[MAXN],p[MAXN];
ll bit[MAXN+1],dp[MAXN],l[MAXN];
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
    while(i<=MAXN)
    {
        bit[i]=(bit[i]+x)%MOD;
        i+=i&-i;
    }
}
int main()
{
	scanf("%lld%lld",&n,&q);
	for(ll i=0;i<q;i++)
		scanf("%lld %lld",&a[i].F,&a[i].S);
	sort(a,a+q);
	ll t=0;
	for(ll i=q-1;i>=0;i--)
		if(t==0||a[i].S<p[t-1].S)
			p[t++]=a[i];
	sort(p,p+t);
	memset(l,-1,sizeof(l));
	for(ll i=0;i<t;i++)
		l[p[i].S+1]=p[i].F+1;
	memset(bit,0,sizeof(bit));
	dp[1]=1;
	add(1,1);
	for(ll i=2;i<=n+1;i++)
	{
		if(l[i]==-1) dp[i]=(dp[i-1]*2)%MOD; 
		else 
		{
			//printf("%lld %lld %lld %lld\n",i,dp[i],sum(i-1),sum(l[i]-2));
			dp[i]=(sum(i-1)-sum(l[i]-2)+MOD)%MOD;
		}
		add(i,dp[i]);
	}
	printf("%lld\n",dp[n+1]);
	return 0;
}