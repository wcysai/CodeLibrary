/*************************************************************************
    > File Name: 4348.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-11 17:44:08
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
typedef pair<int,int> P;
ll n,q,tot,a[MAXN],root[MAXN];
ll lson[MAXM],rson[MAXM],sum[MAXM],add[MAXM];
void build(ll &k,ll l,ll r)
{
    k=++tot;
    add[k]=0;
    if(l==r) {sum[k]=a[l]; return;}
    ll mid=(l+r)/2;
    build(lson[k],l,mid);build(rson[k],mid+1,r);
    sum[k]=sum[lson[k]]+sum[rson[k]];
}
void update(ll &k,ll last,ll l,ll r,ll x,ll y,ll num)
{
    k=++tot;
    sum[k]=sum[last]+(y-x+1)*num;add[k]=add[last];
    lson[k]=lson[last];rson[k]=rson[last];
    if(l==x&&r==y) {add[k]+=num; return;}
    ll mid=(l+r)/2;
    if(y<=mid) update(lson[k],lson[last],l,mid,x,y,num);
    else if(x>mid) update(rson[k],rson[last],mid+1,r,x,y,num);
    else
    {
        update(lson[k],lson[last],l,mid,x,mid,num);
        update(rson[k],rson[last],mid+1,r,mid+1,y,num);
    }
}
ll query(ll k,ll l,ll r,ll x,ll y)
{
    ll ans=(y-x+1)*add[k];
    if(l==x&&r==y) return sum[k];
    ll mid=(l+r)/2;
    if(y<=mid) ans+=query(lson[k],l,mid,x,y);
    else if(x>mid) ans+=query(rson[k],mid+1,r,x,y);
    else
    {
        ans+=query(lson[k],l,mid,x,mid);
        ans+=query(rson[k],mid+1,r,mid+1,y);
    }
    return ans;
}
int main()
{
    while(scanf("%lld%lld",&n,&q)==2)
    {
        tot=0;
        for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
        build(root[0],1,n);
        ll now=0;
        string str;
        for(ll i=1;i<=q;i++)
        {
            cin>>str;
            ll l,r,d,t;
            if(str[0]=='C')
            {
                scanf("%lld%lld%lld",&l,&r,&d);
                now++;
                update(root[now],root[now-1],1,n,l,r,d);
            }
            else if(str[0]=='Q')
            {
                scanf("%lld%lld",&l,&r);
                printf("%lld\n",query(root[now],1,n,l,r));
            }
            else if(str[0]=='H')
            {
                scanf("%lld%lld%lld",&l,&r,&t);
                printf("%lld\n",query(root[t],1,n,l,r));
            }
            else
            {
                scanf("%lld",&t);
                now=t;tot=root[t+1]-1;
            }
        }
    }
    return 0;
}

