/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-14 18:48:01
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
ll n,l,r,k;
int main()
{
    scanf("%lld%lld%lld%lld",&n,&l,&r,&k);
    if(r<l) r+=n;
    ll len=r-l+1;
    ll ans=-1;
    for(ll d=0;d*d<=k&&d<=n;d++)
    {
        ll rem=k%(n+d);
        ll dd=rem-len;
        if(dd>=0&&dd<=len&&dd<=d&&dd>=d-n+len) ans=max(ans,d);
        rem+=n+d;
        dd=rem-len;
        if(dd>=0&&dd<=len&&dd<=d&&dd>=d-n+len) ans=max(ans,d);
    }
    ll dd=k-len;
    if(dd<=len&&dd>=0) ans=max(ans,dd+n-len);
    for(ll round=1;round*round<=k&&round*n<=k;round++)
    {
        ll rem=k-n*round-len;
        if(rem<0) break;
        ll d=rem/round;
        ll dd=rem-round*d;
        if(d-n+len>dd)
        {
            ll need=(d-n+len-dd-1)/(round+1)+1;
            d-=need;
            dd+=round*need;
        }
        if(dd>=0&&dd<=len&&dd<=d&&d>=0&&d<=n&&dd>=d-n+len) ans=max(ans,d);
    }
    for(ll d=0;d*d<=k&&d<=n;d++)
    {
        ll rem=(k+1)%(n+d);
        ll dd=rem-len;
        if(dd>=1&&dd<=len&&dd<=d&&dd>=d-n+len) ans=max(ans,d);
        rem+=n+d;
        dd=rem-len;
        if(dd>=1&&dd<=len&&dd<=d&&dd>=d-n+len) ans=max(ans,d);
    }
    dd=(k+1)-len;
    if(dd<=len&&dd>=1) ans=max(ans,dd+n-len);
    for(ll round=1;round*round<=k&&round*n<=k;round++)
    {
        ll rem=k-n*round-len;
        if(rem<0) break;
        ll d=rem/round;
        ll dd=rem-round*d;
        if(d-n+len>dd)
        {
            ll need=(d-n+len-dd-1)/(round+1)+1;
            d-=need;
            dd+=round*need;
        }
        if(dd>=1&&dd<=len&&dd<=d&&d>=1&&d<=n&&dd>=d-n+len) ans=max(ans,d);
    }
    printf("%lld\n",ans);
    return 0;
}

