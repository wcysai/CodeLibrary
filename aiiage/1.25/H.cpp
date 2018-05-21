#include<bits/stdc++.h>
#define F first
#define S second
#define MAXN 100005
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,A,B;
P a[MAXN];
ll ans[MAXN];
bool cmp(P x,P y)
{
	return x.F>y.F;
}
int main()
{
	scanf("%lld%lld%lld",&n,&A,&B);
	for(ll i=0;i<n;i++)
	{
		scanf("%lld",&a[i].F);
		if(a[i].F<0) a[i].F=0;
	}
	for(ll i=0;i<n;i++)
	{
		scanf("%lld",&a[i].S);
		if(a[i].S<0) a[i].S=0;
	}
	sort(a,a+n,cmp);
	ll sum=0,res=0;
	priority_queue<ll> pque1,pque2;
	memset(ans,0,sizeof(ans));
	for(ll i=0;i<A;i++) {sum+=a[i].F; pque1.push(a[i].S-a[i].F); ans[i]=sum;}
	for(ll i=A;i<A+B;i++)
	{
		sum+=a[i].F+pque1.top();
		ans[i]=sum;
		pque1.pop();
		pque1.push(a[i].S-a[i].F);
	}
	for(ll i=n-1;i>=A+B-1;i--)
		pque2.push(a[i].S);
	for(ll i=A+B-2;i>=A-1;i--)
	{
		res+=pque2.top();
		pque2.pop();
		ans[i]+=res;
		pque2.push(a[i].S);
	}
	ll result=0;
	for(ll i=A-1;i<A+B;i++)
		result=max(result,ans[i]);
	printf("%lld\n",result);
	return 0;
}