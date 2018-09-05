#include<bits/stdc++.h>
#define MAXN 200005
#define INF 100000000000
using namespace std;
typedef long long ll;
ll n,k;
ll a[MAXN],dif[MAXN];
ll b[MAXN];
ll deq[MAXN];
void solve()
{
	ll s=0,t=0;
	for(ll i=0;i<n-1;i++)
	{
		while(s<t&&dif[deq[t-1]]<=dif[i]) t--;
		deq[t++]=i;
		if(i-k+1>=0)
		{
			b[i-k+1]=dif[deq[s]];
			if(deq[s]==i-k+1)
			{
				s++;
			}
		}
	}
	ll ans=INF;
	for(ll i=0;i<n-k;i++)
        ans=min(ans,b[i]);
    printf("%lld\n",ans);
}
int main()
{
    scanf("%lld %lld",&n,&k);
    for(ll i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        if(i!=0) dif[i-1]=a[i]-a[i-1];
    }
    k=n-1-k;
    solve();
    return 0;
}
