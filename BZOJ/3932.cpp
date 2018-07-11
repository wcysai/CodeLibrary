/*************************************************************************
    > File Name: 3932.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-11 00:38:22
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,m,tot,cnt,root[MAXN],p[MAXN];
ll lson[MAXM],rson[MAXM],sum[MAXM],sz[MAXM];
vector<P> G[MAXN];
map<ll,ll> mp;
ll abx(ll x) {return max(-x,x);}
void merge(ll k)
{
    sum[k]=sum[lson[k]]+sum[rson[k]];
    sz[k]=sz[lson[k]]+sz[rson[k]];
}
void build(ll &k,ll l,ll r)
{
    k=++tot;
    if(l==r) return;
    ll mid=(l+r)/2;
    build(lson[k],l,mid);build(rson[k],mid+1,r);
}
void insert(ll &k,ll last,ll l,ll r,ll p,ll x,ll type)
{
    k=++tot;
    sz[k]=sz[last];sum[k]=sum[last];
    if(l==r)
    {
        sum[k]+=x;
        sz[k]+=type;
        return;
    }
    lson[k]=lson[last];rson[k]=rson[last];
    ll mid=(l+r)/2;
    if(p<=mid) insert(lson[k],lson[last],l,mid,p,x,type);
    else insert(rson[k],rson[last],mid+1,r,p,x,type);
    merge(k);
}
ll query(ll &k,ll l,ll r,ll x)
{
    if(x>=sz[k]) return sum[k];
    if(l==r) return sum[k]/sz[k]*x;
    ll mid=(l+r)/2,tmp=sz[lson[k]];
    if(x<tmp) return query(lson[k],l,mid,x);
    else return query(rson[k],mid+1,r,x-tmp)+sum[lson[k]];
}
int main()
{
    scanf("%lld%lld",&m,&n);
    ll maxt=0;
    for(ll i=1;i<=m;i++)
    {
        ll s,e,v;
        scanf("%lld%lld%lld",&s,&e,&v);
        p[i]=v;
        G[s].push_back(P(v,1));
        G[e+1].push_back(P(-v,-1));
        maxt=max(maxt,e+1);
    }
    sort(p+1,p+m+1);
    ll tt=0;
    for(ll i=1;i<=m;i++) if(!mp[p[i]]) mp[p[i]]=++tt;
    build(root[0],1,tt);
    for(ll i=1;i<=maxt;i++)
    {
        root[i]=root[i-1];
        for(ll j=0;j<(int)G[i].size();j++)
            insert(root[i],root[i],1,tt,mp[abx(G[i][j].F)],G[i][j].F,G[i][j].S);
    }
    ll a,b,c,x,k,pre;
    pre=1;
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld%lld%lld%lld",&x,&a,&b,&c);
        k=(a*pre+b)%c+1;
        printf("%lld\n",pre=query(root[x],1,tt,k));
    }
    return 0;
}

