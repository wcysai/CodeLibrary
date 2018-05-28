#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<assert.h>
#include<queue>
#include<stack>
#include<deque>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
ll n,a[MAXN],ans[MAXN];
bool used[MAXN];
int main()
{
	while(scanf("%lld",&n)!=EOF)
	{
		for(ll i=0;i<=n;i++)
			scanf("%lld",&a[i]);
		ll k=1;
		while(k<n) k=k*2+1;
		ll s=0;
		memset(ans,0,sizeof(ans));
		memset(used,false,sizeof(used));
		for(ll i=n;i>=0;i--)
		{
			if(used[i]) continue;
			ll t=k;
			while(t-i>n||used[t-i]) t=t/2;
			ans[i]=t-i;
			ans[t-i]=i;
			used[i]=used[t-i]=true;
			s+=2*t;
		}
		printf("%lld\n",s);
		for(ll i=0;i<=n;i++)
			printf("%lld ",ans[a[i]]);
		puts("");
	}
	return 0;
}