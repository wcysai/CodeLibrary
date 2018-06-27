#include<bits/stdc++.h>
#define MAXN 10000005
#define MAXP 664550
#define MOD 998244353
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll t,n;
ll prime[MAXN];
bool is_prime[MAXN];
ll prime_res[MAXP][25];
ll save[MAXN];
ll sieve(ll n)
{
    ll p=0;
    for(ll i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=n;i++)
    {
        if(is_prime[i])
        {
            prime[p++]=i;
            for(ll j=2*i;j<=n;j+=i) is_prime[j]=false;
        }
    }
    return p;
}
int main()
{
	ll p=sieve(10000000);
	memset(prime_res,0,sizeof(prime_res));
	for(ll i=1;i<p;i++)
	{
		ll cnt=0;
		for(ll now=prime[i];now<=10000000;now=now*prime[i])
		{
			ll l=(prime[i]-1)/2,r=prime[i]-1;
			if(cnt==0) prime_res[i][0]=1;
			else prime_res[i][cnt]=cnt&1?(prime_res[i][cnt-1]*prime[i]-l)%MOD:(prime_res[i][cnt-1]*prime[i]-r)%MOD;
			cnt++;
		}
	}
	for(ll i=1;i<p;i++)
	{
		ll cnt=0;
		for(ll now=prime[i];now<=10000000;now=now*prime[i])
		{
			prime_res[i][cnt]=prime_res[i][cnt]*prime_res[i][cnt]%MOD;
			cnt++;
		}
	}
	prime_res[0][0]=1;
	prime_res[0][1]=3;
	prime_res[0][2]=5;
	prime_res[0][3]=11;
	prime_res[0][4]=29;
	prime_res[0][5]=91;
	prime_res[0][6]=317;
	prime_res[0][7]=1211;
	prime_res[0][8]=4669;
	prime_res[0][9]=18491;
	prime_res[0][10]=73277;
	prime_res[0][11]=292411;
	prime_res[0][12]=1166909;
	prime_res[0][13]=4664891;
	scanf("%I64d",&t);
	while(t--)
	{
		scanf("%I64d",&n);
		ll ti=n;
		ll ans=1;
		for(ll i=0;i<p;i++)
		{
			ll cnt=0;
			while(ti%prime[i]==0)
			{
				ti=ti/prime[i];
				cnt++;
			}
			if(cnt) ans=ans*prime_res[i][cnt]%MOD;
			if(ti==1) break;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}