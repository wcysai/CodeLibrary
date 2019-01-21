/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-30 04:53:43
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
ll n,q,a[MAXN];
char ch[5];
struct segtree
{
    ll sum[4*MAXN];
    void update(ll k,ll l,ll r,ll p,ll v)
    {
        if(l==r) {sum[k]=v; return;}
        ll mid=(l+r)/2;
        if(p<=mid) update(k*2,l,mid,p,v); else update(k*2+1,mid+1,r,p,v);
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    ll query(ll k,ll l,ll r,ll x,ll y)
    {
        if(l>y||x>r) return 0;;
        if(l>=x&&r<=y) return sum[k];
        ll mid=(l+r)/2;
        return query(k*2,l,mid,x,y)+query(k*2+1,mid+1,r,x,y);
    }
}seg;
int main()
{
    scanf("%lld%lld",&n,&q);
    for(ll i=0;i<q;i++)
    {
        scanf("%s",ch);
        ll l,r;scanf("%lld%lld",&l,&r);
        if(ch[0]=='A') seg.update(1,1,n,l,r);
        else printf("%lld\n",seg.query(1,1,n,l,r));
    }
    return 0;
}

