#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k;
bool used[100000000];
bool is_palindrome(ll x)
{
	ll d[10];
	ll t=0;
	while(x)
	{
		d[t++]=x%10;
		x=x/10;
	}
	for(ll i=0;i<t/2;i++)
		if(d[i]!=d[t-1-i]) return false;
	return true;
}
int main()
{
	ll ans=0,cnt=0;
	memset(used,false,sizeof(used));
	for(ll i=1;i*i+(i+1)*(i+1)<=99999999;i++)
	{
		ll res=i*i+(i+1)*(i+1),now=i+2;
		while(res<=99999999)
		{
			if(is_palindrome(res))
			{
				if(!used[res]) {ans+=res; cnt++;}
				used[res]=true;
			}
			res=res+now*now;
			now++;
		}
	}
	printf("%I64d %I64d\n",cnt,ans);
	return 0; 
}