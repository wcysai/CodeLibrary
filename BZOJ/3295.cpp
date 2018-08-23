/*************************************************************************
    > File Name: 3295.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-23 13:51:28
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
ll n,m,a[MAXN];
ll bit[MAXN+1];
struct node{ll t,pos,val;};
ll ans[MAXN];
bool cmp(node p,node q)
{
    if(p.t!=q.t) return p.t<q.t;
    if(p.pos!=q.pos) return p.pos>q.pos;
    return p.val<q.val;
}
bool cmp2(node p,node q)
{
    if(p.pos!=q.pos) return p.pos>q.pos;
    if(p.val!=q.val) return p.val<q.val;
    return p.t<q.t;
}
node c[MAXN],tmp[MAXN];
void add(ll i,ll x)
{
    while(i<=n)
    {
        bit[i]+=x;
        i+=(i&-i);
    }
}
ll query(ll i)
{
    ll s=0;
    while(i)
    {
        s+=bit[i];
        i-=(i&-i);
    }
    return s;
}
map<int,int> del;
void cdq(ll l,ll r)
{
    if(l>=r) return;
    ll mid=(l+r)/2;
    cdq(l,mid);cdq(mid+1,r);
    for(ll i=l;i<=r;i++) tmp[i]=c[i];
    sort(tmp+l,tmp+mid+1,cmp2);sort(tmp+mid+1,tmp+r+1,cmp2);
    ll j=l;
    for(ll i=mid+1;i<=r;i++)
    {
        while(j<=mid&&tmp[j].pos>=tmp[i].pos) add(tmp[j].val,1),j++;
        ans[tmp[i].t]+=query(tmp[i].val);
    }
    for(ll i=l;i<j;i++) add(tmp[i].val,-1);
    j=mid;
    for(ll i=r;i>=mid+1;i--)
    {
        while(j>=l&&tmp[j].pos<=tmp[i].pos) add(tmp[j].val,1),j--;
        ans[tmp[i].t]+=query(n)-query(tmp[i].val);
    }
    for(ll i=mid;i>j;i--) add(tmp[i].val,-1);
}
int main()
{
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    ll tot=0;
    for(ll i=1;i<=m;i++)
    {
        ll x;scanf("%lld",&x);
        del[x]=++tot;
    }
    tot=0;
    for(ll i=1;i<=n;i++)
    {
        if(!del[a[i]]) c[++tot]=(node){tot,i,a[i]};
        else c[n+1-del[a[i]]]=(node){n+1-del[a[i]],i,a[i]};
    }
    sort(c+1,c+n+1,cmp);
    cdq(1,n);
    for(ll i=1;i<=n;i++) ans[i]+=ans[i-1];
    for(ll i=n;i>n-m;i--) printf("%lld\n",ans[i]);
    return 0;
}

