#include<bits/stdc++.h>
#define MAXN 100000005
#define INF 1000000000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll prime[MAXN];
bool is_prime[MAXN];
ll mul_mod(ll a,ll i,ll n)
{
    if(i==0) return a%n;
    ll temp=mul_mod(a,i>>1,n);
      temp=(temp+temp)%n;
    if(i&1) temp=(long long) (temp+a)%n;
    return temp;
}
ll pow_mod(ll a,ll i,ll n)
{
    if(i==0) return 1%n;
    ll temp=pow_mod(a,i>>1,n);
      temp=mul_mod(temp,temp,n);
    if(i&1) temp=(long long) mul_mod(temp,a,n);
    return temp;
}
bool test(ll n,ll a,ll d)
{
    if(n==2) return true;
    if(n==a) return true;
    if((n&1)==0) return false;
    while(!(d&1)) d=d>>1;
    ll t=pow_mod(a,d,n);
    while((d!=n-1)&&(t!=1)&&(t!=n-1))
    {
        t=(long long)t*t%n;
        d=d<<1;
    }
    return(t==n-1||(d&1)==1);
}
bool isPrime(ll n)
{
    if(n<2) return false;
    ll a[]={2,3,61,97,541};
    for(ll i=0;i<=4;++i) if(!test(n,a[i],n-1)) return false;
    return true;
}
ll sieve(ll n)
{
    ll p=0;
    for(ll i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(ll j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
ll gcd(ll a,ll b)
{
	if(b==0) return a; 
	else return gcd(b,a%b);
}
int main()
{
	ll p=sieve(100000000);
	ll now=5,dif=8;
	while(now<1000000000000000)
	{
		ll t=dif,res=INF;
		if(isPrime(t))
		{
			res=(t-(now%t))%t;
		}
		else
		{
			for(ll i=0;i<p;i++)
			{
				if(t==1) break;
				if(t<=100000000&&is_prime[t])
				{
					res=min(res,(t-(now%t))%t);
					break;
				}
				if(t%prime[i]==0)
				{
					res=min(res,(prime[i]-now%prime[i])%prime[i]);
					while(t%prime[i]==0) t=t/prime[i];
				}
			}
		}
		if(res==INF) res=(t-(now%t))%t;
		if(now+res>1000000000000000) {printf("%I64d\n",1000000000000000+dif+1); break;}
		now+=res;
		dif+=gcd(now,dif)-1;
		now++;
		if(now==1000000000000000) {printf("%I64d\n",now+dif+1); break;}
		printf("%I64d %I64d\n",now,dif);
	}
	return 0;
}