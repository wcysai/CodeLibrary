#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN];
int main()
{
	scanf("%lld%lld",&n,&k);
	ll sum1=k+(k/2),sum2=(k+(k+1)/2);
	if(sum1!=sum2&&n>=sum2&&(n-sum2)%k==0)
	{
		for(ll i=1;i<=k;i++)
			a[i]=i&1?2:1;
		ll res=(n-sum2)/k;
		n=(n-sum2)%k;
		for(ll i=1;i<=k;i++)
			a[i]+=res;
		for(ll i=1;i<=k;i++)
			printf("%lld ",a[i]);
		return 0;
	}
	ll sum=0;
	for(ll i=1;i<=k;i++)
	{
		a[i]=i&1?1:2;
		sum+=a[i];
	}
	if(sum>n)
	{
		puts("-1\n");
		return 0;
	}
	ll res=(n-sum)/k;
	n=(n-sum)%k;
	for(ll i=1;i<=k;i++)
		a[i]+=res;
	ll t=2;
	while(n>0&&t<=k)
	{
		a[t]++;
		n--;
		t+=2;
	}
	t=1;
	while(n>0&&t<=k)
	{
		a[t]++;
		n--;
		t+=2;
	}
	for(ll i=1;i<=k;i++)
		printf("%lld ",a[i]);
	return 0;
}