#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
ll n;
ll bit[MAXN+1];
ll ans[MAXN];
struct node
{
	ll F,S,id;
}a[MAXN];
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
    while(i<MAXN)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
bool cmp(node x,node y)
{
	return x.S*y.F<x.F*y.S;
}
int main()
{
	scanf("%lld",&n);
	for(ll i=0;i<n;i++)
	{
		scanf("%lld%lld",&a[i].F,&a[i].S);
		a[i].id=i;
	}
	sort(a,a+n,cmp);
	memset(bit,0,sizeof(bit));
	memset(ans,0,sizeof(ans));
	for(ll i=0;i<n;i++)
	{
		ans[a[i].id]=sum(a[i].F);
		add(a[i].F,1);
	}
	for(ll i=0;i<n;i++)
		printf("%lld\n",ans[i]);
	return 0;
}