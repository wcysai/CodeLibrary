#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
ll n,a[MAXN],perm[MAXN],p[MAXN],r[MAXN],sum[MAXN];
bool used[MAXN];
vector<ll> ans;
void init(ll n)
{
    for(ll i=0;i<n;i++)
    {
        p[i]=i;
        r[i]=0;
        sum[i]=a[i];
    }
}
ll find(ll x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(ll x,ll y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) {p[x]=y; sum[y]+=sum[x];}
    else
    {
        p[y]=x;
        sum[x]+=sum[y];
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(ll x,ll y)
{
    return find(x)==find(y);
}
int main()
{
    scanf("%lld",&n);
    for(ll i=0;i<n;i++)
        scanf("%lld",&a[i]);
    for(ll i=0;i<n;i++)
        scanf("%lld",&perm[i]);
    init(n);
    ll res=0;
    memset(used,false,sizeof(used));
    for(ll i=n-1;i>=0;i--)
    {
        ll x=perm[i]-1;
        used[x]=true;
        if(x>0&&used[x-1]) unite(x,x-1);
        if(x<n-1&&used[x+1]) unite(x,x+1);
        res=max(res,sum[find(x)]);
        ans.push_back(res);
    }
    for(ll i=n-1;i>=0;i--)
        printf("%lld ",ans[i]);
    return 0;
}
