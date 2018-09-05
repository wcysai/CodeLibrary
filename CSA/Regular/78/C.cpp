#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll banned[10];
ll n,ans,len;
ll powcnt[25];
ll digit[25];
ll find_ans(ll num,bool flag,bool flag2)
{
	ll s=0;
	if(num==len) 
	{
		if(flag) return 1; else return 0;
	}
	if(flag&&flag2) return powcnt[len-num];
	for(ll i=0;i<10;i++)
	{
		if(i==0&&!flag2)
		{
			s+=find_ans(num+1,true,false);
			continue;
		}
		if(banned[i]) continue;
		if(!flag&&i>digit[num]) break;
		if(!flag&&i==digit[num]) s+=find_ans(num+1,false,true);
		else s+=find_ans(num+1,true,true);
	}
	return s;
}
int main()
{
	ll cnt=0;
	for(ll i=0;i<10;i++)
	{
		scanf("%lld",&banned[i]);
		if(!banned[i]) cnt++;
	}
	powcnt[0]=1;
	for(ll i=1;i<=20;i++)
		powcnt[i]=powcnt[i-1]*cnt;
	scanf("%lld",&n);
	ll t=n;
	len=0;
	while(t) {t=t/10;len++;}
	t=n;
	for(ll i=len-1;i>=0;i--) {digit[i]=n%10; n=n/10;}
	if(banned[0]) printf("%lld\n",max(0LL,find_ans(0,false,false)-1)); else printf("%lld\n",find_ans(0,false,false));
	return 0;
}