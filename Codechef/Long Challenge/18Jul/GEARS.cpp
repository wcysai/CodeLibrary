/*************************************************************************
    > File Name: GEARS.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-07 15:06:09
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,t,a[MAXN];
ll p[MAXN],sz[MAXN];
ll dir[MAXN];
bool blocked[MAXN];
vector<ll> G[MAXN];
void init(ll n)
{
    for(ll i=1;i<=n;i++)
    {
        p[i]=i;
        sz[i]=1;
        dir[i]=1.0;
        blocked[i]=false;
        G[i].push_back(i);
    }
}
ll find(ll x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(ll x,ll y)
{
    ll nx=find(x),ny=find(y);
    if(nx==ny) return;
    if(sz[nx]<sz[ny]) 
    {
        p[nx]=ny;
        sz[ny]+=sz[nx];
        if(blocked[nx]) blocked[ny]=true;
        else
        {
            ll ch=dir[y]/dir[x];
            for(ll i=0;i<(int)G[nx].size();i++)
                dir[G[nx][i]]*=-ch;
        }
        G[ny].insert(G[ny].end(),G[nx].begin(),G[nx].end());
    }
    else
    {
        p[ny]=nx;
        sz[nx]+=sz[ny];
        if(blocked[ny]) blocked[nx]=true;
        else
        {
            ll ch=dir[y]/dir[x];
            for(ll i=0;i<(int)G[ny].size();i++)
                dir[G[ny][i]]*=-ch;
        }
        G[nx].insert(G[nx].end(),G[ny].begin(),G[ny].end());
    }
}
bool same(ll x,ll y)
{
    return find(x)==find(y);
}
void block(ll x)
{
    blocked[find(x)]=true;
}
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    init(n);
    for(ll i=0;i<m;i++)
    {
        ll x,y,v;
        scanf("%lld",&t);
        if(t==1)
        {
            scanf("%lld%lld",&x,&y);
            a[x]=y;
        }
        else if(t==2)
        {
            scanf("%lld%lld",&x,&y);
            bool f=same(x,y);
            if(f)
            {
                if(dir[x]==dir[y]) block(x);
            }
            else unite(x,y);
        }
        else 
        {
            scanf("%lld%lld%lld",&x,&y,&v);
            bool f=same(x,y);
            if(!f) puts("0");
            else 
            {
                if(blocked[find(x)]||blocked[find(y)]) puts("0");
                else
                {
                    if(dir[x]!=dir[y]) printf("-");
                    ll p=max(a[x]*v,-a[x]*v),q=max(a[y],-a[y]);
                    ll g=gcd(p,q);
                    printf("%lld/%lld\n",p/g,q/g);
                }
            }
        }
    }
    return 0;
}

