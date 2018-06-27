#include<bits/stdc++.h>
#define MAXN 105
#define MAXM 10005
#define MAXK 15
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,k,dp[MAXK][MAXM];
struct item
{
	ll w,c;
};
vector<item> groups[MAXK];
int main()
{
	while(scanf("%lld%lld%lld",&n,&m,&k)!=EOF)
	{
		for(ll i=1;i<=k;i++) groups[i].clear();
		for(ll i=0;i<n;i++)
		{
			ll x,y,z;
			scanf("%lld%lld%lld",&x,&y,&z);
			groups[x].push_back((item){y,z});
		}
		memset(dp,-1,sizeof(dp));
		for(ll i=0;i<=m;i++) dp[0][i]=0;
		for(ll i=1;i<=k;i++)
		{
			for(ll j=0;j<groups[i].size();j++)
			{
				for(ll p=m;p>=groups[i][j].w;p--)
				{
					if(dp[i][p-groups[i][j].w]!=-1) dp[i][p]=max(dp[i][p],dp[i][p-groups[i][j].w]+groups[i][j].c);
					if(dp[i-1][p-groups[i][j].w]!=-1) dp[i][p]=max(dp[i][p],dp[i-1][p-groups[i][j].w]+groups[i][j].c);
				}
			}
		}
		if(dp[k][m]==-1) puts("Impossible"); else printf("%lld\n",dp[k][m]);
	}
	return 0;
}