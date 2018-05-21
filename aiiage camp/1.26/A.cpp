#include<bits/stdc++.h>
#define MAXN 1000005
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll bit[MAXN+1];
ll sum(ll i)
{
    ll s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(ll i,ll x)
{
    while(i<=n)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
ll n;
ll h[MAXN];
ll L[MAXN],R[MAXN];
ll st[MAXN];
ll res=0;
P seg1[MAXN],seg2[MAXN];
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
		scanf("%lld",&h[i]);
	ll t=0;
	for(ll i=1;i<=n;i++)
	{
		while(t>0&&h[st[t-1]]<=h[i]) t--;
		L[i]=t==0?0:st[t-1];
		st[t++]=i;
	}
	for(ll i=n;i>=1;i--)
	{
		while(t>0&&h[st[t-1]]>=h[i]) t--;
		R[i]=t==0?n+1:st[t-1];
		st[t++]=i;
	}
	for(ll i=1;i<=n;i++)
		printf("%lld %lld\n",L[i],R[i]);
	for(ll i=1;i<=n;i++)
	{
		seg1[i].F=L[i];
		seg1[i].S=i;
		seg2[i].F=i;
		seg2[i].S=R[i];
	}
	ll ans=1;
	for(ll i=1;i<=n;i++)
	{
		ans+=L[i];
		res+=R[i]>n?0:n-R[i];
	}
	ll cnt=0;
	for(ll i=n;i>=1;i--)
	{
		add(seg1[i].F,1);
		add(seg1[i].S,-1);
		cnt+=sum(seg2[i].S-1)-sum(seg2[i].F);
	}
	printf("%lld\n",ans);
}
