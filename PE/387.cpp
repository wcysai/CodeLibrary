#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
ll mul_mod(ll a,ll i,ll n)
{
	if(i==0) return 0LL;
    ll temp=mul_mod(a,i>>1,n);
      temp=(temp+temp)%n;
    if(i&1) temp=(long long) (temp+a)%n;
    return temp;
}
ll pow_mod(ll a,ll i,ll n)
{
    if(i==0) return 1LL%n;
    ll temp=pow_mod(a,i>>1,n);
      temp=mul_mod(temp,temp,n);
    if(i&1) temp=mul_mod(temp,a,n);
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
        t=mul_mod(t,t,n);
        d=d<<1;
    }
    return(t==n-1||(d&1)==1);
}
bool isPrime(ll n)
{
    if(n<2) return false;
    ll a[]={2,3,5,7,11,13,17,19};
    for(ll i=0;i<=7;++i) if(!test(n,a[i],n-1)) return false;
    return true;
}
bool is_harshad(ll x)
{
	ll t=x,s=0;
	while(x)
	{
		s+=x%10;
		x=x/10;
	}
	return t%s==0;
}
bool is_strong_harshad(ll x)
{
	ll t=x,s=0;
	while(x)
	{
		s+=x%10;
		x=x/10;
	}
	if(t%s==0&&isPrime(t/s)) return true;
	return false;
}
int main()
{
	queue<ll> que;
	for(ll i=1;i<=9;i++)
		que.push(i);
	ll ans=0;
	while(que.size())
	{
		ll p=que.front();
		if(p>=100000000000000) break;
		//printf("%I64d\n",p);
		que.pop();
		bool f=is_strong_harshad(p);
		for(ll i=0;i<=9;i++)
		{
			ll new_num=p*10+i;
			if(is_harshad(new_num)) que.push(new_num);
			if(f&&new_num<100000000000000&&isPrime(new_num)) ans+=new_num;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}