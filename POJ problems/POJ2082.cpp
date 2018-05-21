#include<cstdio>
#include<algorithm>
#define MAXN 100000
using namespace std;
typedef long long ll;
ll n;
ll h[MAXN],w[MAXN],sum[MAXN];
ll L[MAXN],R[MAXN];
ll st[MAXN];
void solve()
{
	ll t=0;
	for(ll i=0;i<n;i++)
	{
		while(t>0&&h[st[t-1]]>=h[i]) t--;
		L[i]=t==0?0:(st[t-1]+1);
		st[t++]=i;
	}
	t=0;
	for(ll i=n-1;i>=0;i--)
	{
		while(t>0&&h[st[t-1]]>=h[i]) t--;
		R[i]=t==0?n:st[t-1];
		st[t++]=i;
	}
	ll res=0;
	for(ll i=0;i<n;i++)
		res=max(res,h[i]*(sum[R[i]]-sum[L[i]]));
	printf("%lld\n",res);
}
int main()
{
    while(scanf("%lld",&n)==1)
    {
        if(n<0) break;
        for(ll i=0;i<n;i++)
            scanf("%lld%lld",&w[i+1],&h[i]);
        sum[0]=0;
        for(ll i=1;i<=n;i++)
            sum[i]=sum[i-1]+w[i];
        solve();
    }
    return 0;
}
