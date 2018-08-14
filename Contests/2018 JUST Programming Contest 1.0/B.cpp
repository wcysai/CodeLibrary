#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll t,n,a;
bool C(ll x)
{
	return x*(x+1)/2+(n-x)<=n*a;
}
int main()
{
	scanf("%I64d",&t);
	while(t--)
	{
		scanf("%I64d%I64d",&n,&a);
		ll lb=1,rb=n+1;
		while(rb-lb>1)
		{
			ll mid=(lb+rb)/2;
			if(C(mid)) lb=mid; else rb=mid;
		}
		printf("%I64d\n",lb);
	}
	return 0;
}