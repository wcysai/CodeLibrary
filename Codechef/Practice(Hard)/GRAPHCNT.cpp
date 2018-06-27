#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<int> G[MAXN],rG[MAXN],dt[MAXN],bucket[MAXN];
ll sdom[MAXN],idom[MAXN],arr[MAXN],rev[MAXN],par[MAXN],dsu[MAXN],label[MAXN],sz[MAXN];
ll n,m,t,ans=0;
ll find(ll u,ll x=0)
{
	if(u==dsu[u]) return x?-1:u;
	ll v=find(dsu[u],x+1);
	if(v<0) return u;
	if(sdom[label[dsu[u]]]<sdom[label[u]])
		label[u]=label[dsu[u]];
	dsu[u]=v;
	return x?v:label[u];
}
void unite(ll u,ll v)
{
	dsu[v]=u;
}
void dfs(ll v)
{
	t++;arr[v]=t;rev[t]=v;
	for(ll i=0;i<G[v].size();i++)
	{
		ll to=G[v][i];
		if(!arr[to]) dfs(to),par[arr[to]]=arr[v];
		rG[arr[to]].push_back(arr[v]);
	}
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=m;i++)
	{
		ll u,v;
		scanf("%lld%lld",&u,&v);
		G[u].push_back(v);
	}
	for(ll i=1;i<=n;i++)
		sdom[i]=i,idom[i]=0,label[i]=i,dsu[i]=i; 
	memset(arr,0,sizeof(arr));
	memset(rev,0,sizeof(rev));
	dfs(1);
	n=t;
	for(ll i=n;i>=1;i--)
	{
		for(ll j=0;j<rG[i].size();j++)
			sdom[i]=min(sdom[i],sdom[find(rG[i][j])]);
		if(i>1) bucket[sdom[i]].push_back(i);
		for(ll j=0;j<bucket[i].size();j++)
		{
			ll w=bucket[i][j],v=find(w);
			if(sdom[v]==sdom[w]) idom[w]=sdom[w];
			else idom[w]=v;
		}
		if(i>1) unite(par[i],i);
	}
	for(ll i=2;i<=n;i++)
	{
		if(idom[i]!=sdom[i]) idom[i]=idom[idom[i]];
		dt[rev[idom[i]]].push_back(rev[i]);
	}
	for(int i=1;i<=n;i++)
		printf("%d %d\n",i,idom[i]);
	ans=1LL*n*(n-1);
    for(int i=n;i>=2;i--)
    {
        sz[i]++;
        if(idom[i]!=1)
            sz[idom[i]]+=sz[i];
        else
            ans-=1LL*sz[i]*(sz[i]-1);
    }
    ans>>=1;
    printf("%lld\n",ans);
	return 0;
}