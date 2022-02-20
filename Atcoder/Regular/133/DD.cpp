#include<cstdio>
using namespace std;
#define ll long long
#define mod 998244353
//4k:4k 4k+1:1 4k+2:4k+3 4k+3:0
int tp[4]={0,1,3,0};
ll l,r,k,as;
int solve(ll x,ll y,ll k)
{
	x++;y++;if(y<=0||x<=0)return 0;
	ll as=0;
	for(int i=61;i>=0;i--)
	{
		if(((x^y)>>(i+1))!=(k>>(i+1)))continue;
		ll v1=x&((1ll<<i)-1),v2=y&((1ll<<i)-1),f1=(x>>i)&1,f2=(y>>i)&1,f3=(k>>i)&1;
		if(f3){if(f1&f2)as=(as+v1+v2)%mod;}
		else if(f1&&f2)
		as=(as+(1ll<<i))%mod;
		else if(f1)as=(as+v2)%mod;
		else if(f2)as=(as+v1)%mod;
	}
	return as;
}
int main()
{
	scanf("%lld%lld%lld",&l,&r,&k);l--;
	for(int s=0;s<4;s++)for(int t=0;t<4;t++)if((tp[s]^tp[t])==(k&3))
	{
		int f1=s&1,f2=t&1;
		ll l1=l>>2,r1=r>>2,l2=l1,r2=r1;
		if(l1*4+s<l)l1++;if(r1*4+s>r)r1--;
		if(l2*4+t<l)l2++;if(r2*4+t>r)r2--;
		if(l1>r1||l2>r2)continue;
		if(!f1&&!f2)
		as=(as+10ll*mod+solve(r1,r2,k>>2)-solve(r1,l2-1,k>>2)-solve(r2,l1-1,k>>2)+solve(l1-1,l2-1,k>>2))%mod;
		else if(f1&&f2)
		as=(as+1ll*(!(k>>2))*((r1-l1+1)%mod)*((r2-l2+1)%mod))%mod;
		else if(f1)
		{
			ll tp=k>>2;
			if(tp>=l2&&tp<=r2)as=(as+(r1-l1+1))%mod;
		}
		else
		{
			ll tp=k>>2;
			if(tp>=l1&&tp<=r1)as=(as+(r2-l2+1))%mod;
		}
	}
	if(!k)as=(as-r%mod+l-1+2ll*mod)%mod;
	as=1ll*as*(mod+1)/2%mod;
	printf("%d\n",as);
}