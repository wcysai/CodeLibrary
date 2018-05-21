#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
ll digit_sum(ll x)
{
	ll s=0;
	while(x>0)
	{
		s+=x%10;
		x=x/10;
	}
	return s;
}
int main()
{
	set<ll> ans;
	for(ll i=2;i<=500;i++)
	{
		ll s=i;
		for(ll j=1;j<=500;j++)
		{
			s=s*i;
			if(s<0) break;
			if(s<10) continue;
			if(digit_sum(s)==i) ans.insert(s);
		}
	}
	printf("%d\n",ans.size());
	ll cnt=1;
	for(auto it=ans.begin();it!=ans.end();it++)
	{
		if(cnt==30) printf("%lld\n",*it);
		cnt++;
	}
	return 0;
}