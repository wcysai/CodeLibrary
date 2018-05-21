#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
ll n,k,a[MAXN];
ll prime[MAXN],digit[MAXN];
bool is_prime[MAXN];
ll pow10[]={1,10,100,1000,10000,100000,1000000,10000000};
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
ll find_ans(ll x)
{
	ll cnt=1,t=1;
	if(x==1) return 0;
	while(t!=0)
	{
		t=(t*10+1)%x;
		cnt++;
	}
	return cnt;
}
ll extgcd(ll a,ll b,ll &x,ll &y)
{
    ll d=a;
    if(b!=0)
    {
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else
    {
        x=1;
        y=0;
    }
    return d;
}
ll mod_inverse(ll a,ll m)
{
    ll x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}
int main()
{
	ll p=sieve(1000020);
	printf("%I64d\n",p);
	memset(digit,0,sizeof(digit));
	for(ll i=0;i<p;i++)
	{
		ll t=prime[i],cnt=0;
		while(t>0)
		{
			t=t/10;
			cnt++;
		}
		digit[prime[i]]=pow10[cnt];
	}
	ll sum=0;
	for(ll i=3;i<p;i++)
	{
		ll p2=prime[i],p1=prime[i-1];
		ll num=(mod_inverse(digit[p1]%p2,p2)*(p2-p1)%p2)*digit[p1]+p1;
		//printf("%I64d\n",num);
		sum+=num;
	}
	printf("%I64d\n",sum);
	return 0;
}