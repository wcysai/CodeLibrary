#include<bits/stdc++.h>
#define MAXN 1500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll num[MAXN];
ll gcd(ll a,ll b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	memset(num,0,sizeof(num));
	for(ll i=2;;i++)
	{
		if(2*i*i>1500000LL) break;
		for(ll j=1;j<i;j++)
		{
			if(((i&1)&&(j&1))||gcd(i,j)!=1) continue;
			//printf("%lld %lld %lld\n",i*i-j*j,2*i*j,i*i+j*j);
			ll p=2*i*i+2*i*j;
			if(p>1500000LL) break;
			for(ll k=1;p*k<=1500000;k++)
				num[p*k]++;
		}
	}
	ll ans=0;
	for(ll i=1;i<=1500000;i++)
		if(num[i]==1) ans++;
	printf("%I64d %I64d\n",num[12],num[120]);
	printf("%I64d\n",ans);
	return 0;
}