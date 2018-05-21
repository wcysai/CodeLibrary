#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN];
ll prime[7]={2,3,5,7,11,13,17},cnt[7];
int main()
{
	for(ll i=5;i<=2*3*5*7*11*13*17;i++)
	{
		memset(cnt,0,sizeof(cnt));
		ll t=i;
		for(ll j=0;j<7;j++) while(t%prime[j]==0) {cnt[j]++; t=t/prime[j];}
		if(t!=1) continue;
		ll res=1;
		for(ll j=0;j<7;j++)
			res=res*(2*cnt[j]+1);
		if(res>2000) {printf("%I64d\n",i); return 0;}
	}
	return 0;
}