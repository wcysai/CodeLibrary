/*************************************************************************
    > File Name: KCOMPRES.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-06 09:24:20
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll T,N,S;
P a[MAXN];
vector<P> save;
struct segtree
{
    ll val[4*MAXN];
    void build(ll k,ll l,ll r)
    {
        val[k]=0;
        if(l==r) return;
        ll mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
    }
    void update(ll k,ll l,ll r,ll pos,ll v)
    {
        if(l==r) {val[k]=v; return;}
        ll mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,v); else update(k*2+1,mid+1,r,pos,v);
        val[k]=max(val[k*2],val[k*2+1]);
    }
    ll query(ll k,ll l,ll r,ll x,ll y)
    {
        if(l>y||r<x) return 0;
        if(l>=x&&r<=y) return val[k];
        ll mid=(l+r)/2;
        return max(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
bool C(ll x)
{
    seg.build(1,1,N);
    ll ans=0;
    save.clear();
    for(ll i=1;i<=N;i++)
    {
        if(a[i].x!=a[i-1].x)
        {
            ll last=0,mx=0;
            for(ll j=0;j<(int)save.size();j++) 
            {
                if(j!=0&&save[j].x-save[j-1].x>x)
                {
                    for(ll k=last;k<j;k++)
                    {
                        ans+=mx;
                        seg.update(1,1,N,save[k].x,mx);
                    }
                    last=j;
                    mx=0;
                }
                mx=max(mx,save[j].y);
            }
            for(ll k=last;k<(int)save.size();k++)
            {
                ans+=mx;
                seg.update(1,1,N,save[k].x,mx);
            }
            save.clear();
        }
        ll l=max(1LL,a[i].y-x),r=min(N,a[i].y+x);
        ll val=max(seg.query(1,1,N,l,a[i].y-1),seg.query(1,1,N,a[i].y+1,r))+1;
        save.push_back(P(a[i].y,val));
    }
    ll last=0,mx=0;
    for(ll j=0;j<(int)save.size();j++) 
    {
        if(j!=0&&save[j].x-save[j-1].x>x)
        {
            for(ll k=last;k<j;k++)
            {
                ans+=mx;
                seg.update(1,1,N,save[k].x,mx);
            }
            last=j;
            mx=0;
        }
        mx=max(mx,save[j].y);
    }
    for(ll k=last;k<(int)save.size();k++)
    {
        ans+=mx;
        seg.update(1,1,N,save[k].x,mx);
    }
    return ans<=S;
}
int main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&N,&S);
        for(ll i=1;i<=N;i++) 
        {
            scanf("%lld",&a[i].x);
            a[i].y=i;
        }
        sort(a+1,a+N+1);
        ll l=-1,r=N+1;
        while(r-l>1)
        {
            ll mid=(l+r)/2;
            if(C(mid)) l=mid; else r=mid;
        }
        printf("%lld\n",l+1);
    }
    return 0;
}

