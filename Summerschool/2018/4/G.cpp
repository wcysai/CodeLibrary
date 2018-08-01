/*************************************************************************
    > File Name: G.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-01 13:44:07
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll T,n,sz[MAXN],B[MAXN],fa[MAXN];
vector<ll> G[MAXN];
ll fact[MAXN],invf[MAXN],inv[MAXN];
ll ans,cur,res;
bool used[MAXN];
struct sbsjjg
{
    ll v,siz;
    vector<ll> vi;
    vector<ll> bit;
    ll sum(ll i)
    {
        ll s=0;
        while(i>0)
        {
            s+=bit[i];
            i-=i&-i;
        }
        return s;
    }
    void add(ll i,ll x)
    {
        while(i<=siz)
        {
            bit[i]+=x;
            i+=i&-i;
        }
    }
    void init()
    {
        bit.clear();
        for(auto to:G[v]) if(to!=fa[v]) vi.push_back(to);
        sort(vi.begin(),vi.end());
        siz=vi.size();
        bit.resize(siz+1);
        for(ll i=1;i<=(ll)vi.size();i++) add(i,1);
    }
    ll query(ll x)
    {
        ll id=lower_bound(vi.begin(),vi.end(),x)-vi.begin();
        return sum(id);
    }
    bool has(ll x)
    {
        if(query(x)!=query(x+1)) return true; else return false;
    }
    void del(ll x)
    {
        ll id=lower_bound(vi.begin(),vi.end(),x)-vi.begin();
        add(id+1,-1);
    }
}tr[MAXN];
ll pow_mod(ll a,ll i)
{
    ll s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
void dfs(ll v,ll p)
{
    sz[v]=(int)G[v].size();
    if(p) sz[v]--;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
    }
}
void solve(ll v,ll p,ll now)
{
    if(v<B[1]) ans=(ans+now)%MOD;
    //printf("%lld %lld\n",v,now);
    for(auto to:G[v])
    {
        if(to==p) continue;
        ll res1=inv[sz[v]],res2=sz[to]+1;
        sz[to]+=1;sz[v]-=1;
        solve(to,v,1LL*now*res1%MOD*res2%MOD);
    }
}
void dfs2(ll v,ll p)
{
    sz[v]=(int)G[v].size();
    if(p) sz[v]--;
    fa[v]=p;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs2(to,v);
    }
}
int main()
{
    
    scanf("%lld",&T);
    fact[0]=invf[0]=inv[1]=1;
    for(ll i=1;i<=1000000;i++)
        fact[i]=1LL*fact[i-1]*i%MOD;
    invf[1000000]=pow_mod(fact[1000000],MOD-2);
    for(ll i=999999;i>=1;i--) 
    {
        invf[i]=1LL*invf[i+1]*(i+1)%MOD;
        inv[i+1]=1LL*invf[i+1]*fact[i]%MOD;
    }
    while(T--)
    {
        scanf("%lld",&n);
        for(ll i=1;i<=n;i++) G[i].clear();
        for(ll i=1;i<=n;i++) scanf("%lld",&B[i]);
        for(ll i=0;i<n-1;i++)
        {
            ll u,v;
            scanf("%lld%lld",&u,&v);
            G[u].push_back(v);G[v].push_back(u);
        }
        res=1;ans=0;
        dfs(1,0);
        for(ll i=1;i<=n;i++) res=1LL*res*fact[sz[i]]%MOD;
        solve(1,0,res);
        //printf("%lld\n",ans);
        dfs2(B[1],0);
        res=1;
        for(ll i=1;i<=n;i++) res=1LL*res*fact[sz[i]]%MOD;
        for(ll i=1;i<=n;i++) {tr[i].v=i; tr[i].init();}
        vector<ll> seq;seq.clear();
        //printf("res=%lld\n",res);
        for(ll i=1;i<n;i++)
        {
            if(seq.size()>0&&fa[B[i]]!=seq.back()) break;
            seq.push_back(B[i]);
            ll v=B[i];
            while(seq.size()&&sz[seq.back()]==0) {seq.pop_back(); v=fa[v];}
            res=1LL*res*invf[sz[v]]%MOD;sz[v]--;res=1LL*res*fact[sz[v]]%MOD;
            ll cnt=tr[v].query(B[i+1]);
            ans=(ans+1LL*cnt*res)%MOD;
            tr[v].del(B[i+1]); 
            //printf("%lld %lld %lld %lld\n",v,sz[v],cnt,res);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

