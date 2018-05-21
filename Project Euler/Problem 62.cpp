#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD1 998244353
#define MOD2 1000000009
#define BASE1 97
#define BASE2 107
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
P save[1000000];
P _hash(ll x)
{
	int num[10];
	memset(num,0,sizeof(num));
	while(x)
	{
		num[x%10]++;
		x/=10;
	}
	ll s1=0,s2=0;
	for(ll i=0;i<10;i++)
	{
		s1=(s1*BASE1+num[i])%MOD1;
		s2=(s2*BASE2+num[i])%MOD2;
	}
	return P(s1,s2);
}
map<P,ll> mp;
int main()
{
	P t=P(-1,-1);
	mp.clear();
	for(ll i=1;;i++)
	{
		ll res=i*i*i;
		P ans=_hash(res);
		if(mp.find(ans)==mp.end()) mp[ans]=1; else mp[ans]++;
		save[i]=ans;
		if(mp[ans]==5) {t=ans; break;}
	}
	printf("%I64d %I64d\n",t.F,t.S);
	ll cnt=0;
	for(ll i=1;i<=100000;i++)
	{
		if(save[i]==t) {printf("%I64d\n",i*i*i); cnt++;}
		if(cnt==5) break;
	}
	return 0;
}