/*************************************************************************
    > File Name: H.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-27 18:56:17
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 50005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll T,N,p,q,K;
vector<int> G[MAXN];
bool centroid[MAXN];
ll sz[MAXN],deep[MAXN],d[MAXN];
ll ans;
P getroot(ll v,ll p,ll t)//search_centroid
{
    P res=P(INT_MAX,-1);
	ll m=0;
    sz[v]=1;
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p||centroid[to]) continue;
        res=min(res,getroot(to,v,t));
        m=max(m,sz[to]);
        sz[v]+=sz[to];
    }
    m=max(m,t-sz[v]);
    res=min(res,P(m,v));
    return res;
}
void getdeep(ll v,ll p)//enumerate path
{
    deep[++deep[0]]=d[v];
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p||centroid[to]) continue;
        d[to]=d[v]+1;
        getdeep(to,v);
    }
}
ll cal(ll v,ll cost)
{
    d[v]=cost;deep[0]=0;
    getdeep(v,0);
    sort(deep+1,deep+deep[0]+1);
    ll l=1,r=deep[0],sum=0;
    while(l<r)
    {
        if(deep[l]+deep[r]<=K)
        {
            sum+=r-l;
            l++;
        }
        else r--;
    }
    return sum;
}
void solve(ll v)
{
    ans+=cal(v,0);
    centroid[v]=true;
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i],cost=1;
        if(centroid[to]) continue;
        ans-=cal(to,cost);
        ll rt=getroot(to,v,sz[to]).S;
        solve(rt);
    }
}
ll ac()
{
    ans=0;
    memset(centroid,false,sizeof(centroid));
    ll rt=getroot(1,0,N).S;
    solve(rt);
    return ans;
}
ll ret;
int main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld%lld",&N,&p,&q);
        for(ll i=1;i<=N;i++) G[i].clear();
        for(ll i=0;i<N-1;i++)
        {
            ll u,v;
            scanf("%lld%lld",&u,&v);
            G[u].push_back(v);G[v].push_back(u);
        }
        K=p+q;
        ret=ac();
        K--;
        ret-=ac();
        ret*=2;
        ll denom=N*(N-1)*(N-2);
        ll g=__gcd(ret,denom);ret/=g;denom/=g;
        printf("%.17Lf\n",(long double)ret/denom);
    }
    return 0;
}

