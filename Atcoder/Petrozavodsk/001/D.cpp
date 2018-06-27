#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000009
using namespace std;
typedef long long ll;
ll n,m,a[MAXN],res;
priority_queue<ll, vector<ll>, greater<ll> > pque;
vector<ll> G[MAXN];
bool used[MAXN];
void dfs(ll v,ll p)
{
	used[v]=true;
	if(a[v]<res)
	{
		if(res!=INF) pque.push(res);
		res=a[v];
	}
	else pque.push(a[v]);
	for(ll i=0;i<G[v].size();i++)
	{
		ll to=G[v][i];
		if(to==p) continue;
		if(!used[to]) dfs(to,v);
	}
	return;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for(ll i=0;i<n;i++)
		scanf("%lld",&a[i]);
	ll num=n-1;
	for(ll i=0;i<m;i++)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
		num--;
	}
	num*=2;
	if(num>n)
	{
		printf("Impossible\n");
		return 0;
	}
	if(num==0)
	{
		printf("0\n");
		return 0;
	}
	ll ans=0;
	memset(used,false,sizeof(used));
	while(pque.size()) pque.pop();
	for(ll i=0;i<n;i++)
	{
		if(!used[i])
		{
			res=INF;
			dfs(i,-1);
			ans+=res;
			num--;
		}
	}
	for(ll i=0;i<num;i++)
	{
		ans+=pque.top();
		pque.pop();
	}
	printf("%lld\n",ans);
    return 0;
}
