#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#define MAXN 200005
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n;
P a[MAXN+1];
vector<ll> row,col;
map<ll,ll> rowmp,colmp;
ll bit[MAXN+1];
ll l[MAXN+1],r[MAXN+1];
vector<ll> save[MAXN+1];
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
    while(i<MAXN)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
bool cmp(P x,P y)
{
    if(x.F!=y.F) return x.F<y.F;
    return x.S<y.S;
}
int main()
{
    scanf("%lld",&n);
    row.clear();
    col.clear();
    rowmp.clear();
    colmp.clear();
    for(ll i=0;i<n;i++)
    {
        scanf("%lld%lld",&a[i].F,&a[i].S);
        row.push_back(a[i].F);
        col.push_back(a[i].S);
    }
    sort(row.begin(),row.end());
    sort(col.begin(),col.end());
    ll cnt=0;
    for(ll i=0;i<row.size();i++)
    {
        if(rowmp.find(row[i])==rowmp.end())
        {
            cnt++;
            rowmp[row[i]]=cnt;
        }
    }
    ll t=cnt;
    cnt=0;
    for(ll i=0;i<col.size();i++)
    {
        if(colmp.find(col[i])==colmp.end())
        {
            cnt++;
            colmp[col[i]]=cnt;
        }
    }
    for(ll i=0;i<n;i++)
    {
        a[i].F=rowmp[a[i].F];
        a[i].S=colmp[a[i].S];
    }
    memset(l,-1,sizeof(l));
    memset(r,-1,sizeof(r));
    sort(a,a+n,cmp);
    for(ll i=0;i<n;i++)
        save[a[i].F].push_back(a[i].S);
    for(ll i=0;i<n;i++)
    {
        if(l[a[i].S]==-1) l[a[i].S]=a[i].F;
        r[a[i].S]=a[i].F;
    }
    memset(bit,0,sizeof(bit));
    ll ans=0;
    for(ll i=1;i<=t;i++)
    {
        ll lower=save[i][0],upper=save[i].back();
        for(ll j=0;j<save[i].size();j++)
            if(i==l[save[i][j]]) add(save[i][j],1);
        ans+=sum(upper)-sum(lower-1);
        for(ll j=0;j<save[i].size();j++)
            if(i==r[save[i][j]]) add(save[i][j],-1);
    }
    printf("%lld\n",ans);
    return 0;
}
