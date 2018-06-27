#include<cstdio>
#define MAXN 100000
using namespace std;
typedef long long ll;
ll n;
ll h[MAXN];
ll R[MAXN];
ll st[MAXN];
void solve()
{
	ll t=0,s=0;
	for(ll i=n-1;i>=0;i--)
	{
		while(t>0&&h[st[t-1]]<h[i]) t--;
		R[i]=t==0?n:st[t-1];
		s+=R[i]-1-i;
		st[t++]=i;
	}
	printf("%lld\n",s);
}
int main()
{
    scanf("%lld",&n);
    for(ll i=0;i<n;i++)
        scanf("%lld",&h[i]);
    solve();
    return 0;
}

