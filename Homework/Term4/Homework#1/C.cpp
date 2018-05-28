#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<assert.h>
#include<set>
#include<deque>
#define MAXN 13
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,q;
vector<int> G[MAXN];
ll dp[(1<<MAXN)][MAXN][MAXN],num[(1<<MAXN)][MAXN][MAXN];
ll a[MAXN];
bool f[MAXN][MAXN];
ll find_ans(ll state,ll now,ll last)
{
	if(dp[state][now][last]!=-1) return dp[state][now][last];
	ll last_state=state-(1<<now);
	ll ans=-1;
	ll cnt=0;
	for(ll i=0;i<n;i++)
	{
		if(i==last) continue;
		if((last_state>>i)%2==0) continue;
		if(!f[last][i]) continue;
		ll res=find_ans(last_state,last,i);
		if(res==-1) continue;
		res+=a[now]+a[now]*a[last];
		if(f[now][i]) res+=a[now]*a[last]*a[i];
		if(res>ans)
		{
			ans=res;
			cnt=num[last_state][last][i];
		} 
		else if(res==ans) cnt+=num[last_state][last][i];
	}
	num[state][now][last]=cnt;
	return dp[state][now][last]=ans;
}
int main()
{
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld%lld",&n,&m);
		for(ll i=0;i<n;i++)
			scanf("%lld",&a[i]);
		memset(f,false,sizeof(f));
		for(ll i=0;i<m;i++)
		{
			ll x,y;
			scanf("%lld%lld",&x,&y);
			f[x-1][y-1]=f[y-1][x-1]=true;
		}
		if(n==1)
		{
			printf("%lld 1\n",a[0]);
			continue;
		}
		memset(dp,-1,sizeof(dp));
		memset(num,0,sizeof(num));
		for(ll i=0;i<n;i++)
			for(ll j=0;j<n;j++)
			{
				if(i==j||!f[i][j]) continue;
				dp[((1<<i)|(1<<j))][i][j]=a[i]+a[j]+a[i]*a[j];
				num[((1<<i)|(1<<j))][i][j]=1;
			}
		ll ans=-1;
		for(ll i=0;i<n;i++)
			for(ll j=0;j<n;j++)
			{
				if(i==j||!f[i][j]) continue;
				ans=max(ans,find_ans((1<<n)-1,i,j));
			}
		if(ans==-1)
		{
			printf("0 0\n");
			continue;
		}
		printf("%lld ",ans);
		ll cnt=0;
		for(ll i=0;i<n;i++)
			for(ll j=0;j<n;j++)
			{
				if(i==j||!f[i][j]) continue;
				if(dp[(1<<n)-1][i][j]==ans) cnt+=num[(1<<n)-1][i][j];
			}
		printf("%lld\n",cnt/2);
	}
	return 0;
}