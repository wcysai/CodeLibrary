#include<bits/stdc++.h>
#define MAXN 50000005
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
ll prime[MAXN],sum[MAXN];
bool is_prime[MAXN];
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
bool find_res(int x)
{
	int cnt=0;
	for(int i=1;i*i<=x;i++)
	{
		if(x%i!=0) continue;
		int num1=i,num2=x/i;
		if((num1+num2)%4!=0) continue;
		int d=(num1+num2)/4;
		if(num2>d) cnt++;
		if(num1>d&&num1!=num2) cnt++;
		if(cnt>=2) return false;
	}
	return cnt==1;
}
int main()
{
	ll p=sieve(50000000);
	printf("done1!\n");
	ll ans=0;
	for(ll i=0;i<p;i++)
	{
		if(prime[i]%4==3)
		{
			//printf("%d\n",i);
			ans++;
		}
	}
	printf("done2!\n");
	for(ll i=1;i<p;i++)
	{
		for(ll t=2;prime[i]*t<50000000;t*=2)
			if(find_res(prime[i]*t)) ans++;
	}
	printf("done3!\n");
	for(ll t=1;t<50000000;t*=2)
		if(find_res(t)) ans++;
	printf("%I64d\n",ans);
	return 0;
}