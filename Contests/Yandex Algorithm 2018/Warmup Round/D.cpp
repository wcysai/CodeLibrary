#include<bits/stdc++.h>
#define MAXN 100000
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll phi(ll n)
{
    ll res=n;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            res=res/i*(i-1);
            for(;n%i==0;n/=i);
        }
    }
    if(n!=1) res=res/n*(n-1);
    return res;
}
int main()
{
	ll n;
	scanf("%I64d",&n);
	if(n==1)
	{
		puts("2");
		return 0;
	}
	else printf("%I64d\n",phi(n));
	return 0;
}