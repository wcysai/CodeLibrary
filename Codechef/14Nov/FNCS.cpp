/*************************************************************************
    > File Name: FNCS.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-29 20:28:33
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll B=320;
ll n,q,a[MAXN];
ll L[MAXN],R[MAXN],sum[MAXN],res[MAXN];
ll mod[MAXN/B+2],ans[MAXN],occ[MAXN/B+2][MAXN];
void update(ll x,ll c)
{
    while(x<=n&&x%B!=1)
    {
        sum[x]+=c;
        x++;
    }
    while(x<=n)
    {
        ll cur=(x-1)/B+1;
        mod[cur]+=c;
        x+=B;
    }
}
ll query(ll x)
{
    if(x<=0) return 0;
    ll cur=(x-1)/B+1;
    return sum[x]+mod[cur];
}
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    for(ll i=1;i<=n;i++) scanf("%lld%lld",&L[i],&R[i]);
    for(ll i=1;i<=n;i++)
    {
        ll cur=(i-1)/B+1;
        res[L[i]]++;res[R[i]+1]--;
        ans[cur]+=sum[R[i]]-sum[L[i]-1];
        if(i%B==0||i==n)
        {
            for(ll j=1;j<=n;j++)
                occ[cur][j]=occ[cur][j-1]+res[j];
            memset(res,0,sizeof(res));
        }
    }
    scanf("%lld",&q);
    ll type,l,r;
    for(ll i=0;i<q;i++)
    {
        scanf("%lld%lld%lld",&type,&l,&r);
        if(type==1)
        {
            ll c=r-a[l];a[l]=r;
            update(l,c);
            for(ll j=1;j<=(n-1)/B+1;j++)
                ans[j]+=occ[j][l]*c;
            for(ll j=1;j<=n;j++) printf("%lld %lld\n",sum[j],mod[(j-1)/B+1]);
            puts("");
        }
        else
        {
            ll now=0;
            while(l<=r&&l%B!=1)
            {
                now+=query(R[l])-query(L[l]-1);
                l++;
            }
            while(r>=l&&r%B!=0)
            {
                now+=query(R[r])-query(L[r]-1);
                r--;
            }
            while(l<=r)
            {
                ll cur=(l-1)/B+1;
                now+=ans[cur];
                l+=B;
            }
            printf("%lld\n",now);
        }
    }
    return 0;
}

