#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll pow_mod(ll a,ll i)
{
	ll s=1;
	while(i)
	{
		if(i&1) s=1LL*s*a%MOD;
		a=1LL*a*a%MOD;
		i>>=1;
	}
	return s;
}
ll gcd(ll a,ll b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
struct node
{
	ll l,r,res;
}seg[4*MAXN];
ll n,a[MAXN],l[MAXN],dp[MAXN],sum[MAXN];
void build(ll k,ll l,ll r)
{
	seg[k].l=l;seg[k].r=r;
	if(l==r)
	{
		seg[k].res=a[l];
		return;
	}
	ll mid=(l+r)/2;
	build(k*2,l,mid);build(k*2+1,mid+1,r);
	seg[k].res=gcd(seg[k*2].res,seg[k*2+1].res);
}
ll query(ll k,ll l,ll r)
{
	if(seg[k].l>r||seg[k].r<l) return 0;
	if(seg[k].l>=l&&seg[k].r<=r) return seg[k].res;
	return gcd(query(k*2,l,r),query(k*2+1,l,r));
}
int main()
{
	scanf("%lld",&n);
	ll p=0;
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]),a[n+i]=a[i],p=gcd(p,a[i]);
	if(p!=1)
	{
		printf("%lld\n",(pow_mod(2,n)-n+MOD)%MOD);
		return 0;
	}
	build(1,1,2*n);
	ll t=n+1,x=a[n+1];
	while(t>2&&gcd(a[t-1],x)!=1)
	{
		t--;
		x=gcd(x,a[t]);
	}
	l[n+1]=t;
	for(ll i=n+2;i<=2*n;i++)
	{
		t=max(i-n+1,t);
		x=query(1,t,i);
		while(x==1)
		{
			t++;
			x=query(1,t,i);
		}
		l[i]=t;
	}
	ll ans=0,lastgcd=0;
	for(ll i=l[n+1];i<=n+1;i++)
	{
		ll x=query(1,i,n+1);
		if(x!=lastgcd)
		{
			lastgcd=x;
			dp[n]=sum[n]=1;
			dp[n+1]=1;sum[n+1]=2;
			for(ll j=n+2;j<=i+n-1;j++)
			{
				//printf("%lld %lld\n",j,l[j]);
				ll pos=l[j]<=i?n:max(n+1,l[j]-1);
				dp[j]=(sum[j-1]-sum[pos-1]+MOD)%MOD;
				sum[j]=(sum[j-1]+dp[j])%MOD;
			}
			ans=(ans+dp[i+n-1])%MOD;
		}
		else
		{
			ll j=i+n-1;
			ll pos=l[j]<=i?n:max(n+1,l[j]-1);
			dp[j]=(sum[j-1]-sum[pos-1]+MOD)%MOD;
			sum[j]=(sum[j-1]+dp[j])%MOD;
			ans=(ans+dp[j])%MOD;
		}
		//printf("%lld\n",ans);
	}
	printf("%lld\n",ans);
	return 0;
}