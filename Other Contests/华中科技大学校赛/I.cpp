#include<bits/stdc++.h>
#define MAXN 1000005
using namespace std;
typedef long long ll;
ll n;
ll h[MAXN];
ll L[MAXN],R[MAXN];
ll st[MAXN];
int main()
{
	while(scanf("%lld",&n)==1)
	{
		for(ll i=1;i<=n;i++)
			scanf("%lld",&h[i]);
		ll t=0;
		for(ll i=1;i<=n;i++)
		{
			while(t>0&&h[st[t-1]]>h[i]) t--;
			L[i]=t==0?0:st[t-1];
			st[t++]=i;
		}
		t=0;
		for(ll i=n;i>=1;i--)
		{
			while(t>0&&h[st[t-1]]>=h[i]) t--;
			R[i]=t==0?n+1:st[t-1];
			st[t++]=i;
		}
		ll mins=0;
		for(ll i=1;i<=n;i++)
		{
			//printf("%lld %lld\n",L[i],R[i]);
			mins+=h[i]*(i-L[i])*(R[i]-i);
		}
		//printf("%lld\n",mins);
		t=0;
		for(ll i=1;i<=n;i++)
		{
			while(t>0&&h[st[t-1]]<h[i]) t--;
			L[i]=t==0?0:st[t-1];
			st[t++]=i;
		}
		t=0;
		for(ll i=n;i>=1;i--)
		{
			while(t>0&&h[st[t-1]]<=h[i]) t--;
			R[i]=t==0?n+1:st[t-1];
			st[t++]=i;
		}
		ll maxs=0;
		for(ll i=1;i<=n;i++)
		{
			//printf("%lld %lld\n",L[i],R[i]);
			maxs+=h[i]*(i-L[i])*(R[i]-i);
		}
		//printf("%lld\n",maxs);
		printf("%lld\n",maxs-mins);
	}
	return 0;
}
