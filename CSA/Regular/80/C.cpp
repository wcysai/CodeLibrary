/*************************************************************************
    > File Name: 80C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-25 01:17:25
 ************************************************************************/

#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,x,k,a[MAXN];
int main()
{
    scanf("%lld%lld",&n,&x);
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    sort(a,a+n);
    ll ans=(sum-1)/x+1;
    printf("%lld ",ans);
    ll s=0;
    for(ll i=0;i<n-ans;i++) s+=a[i];
    ll lb=-1,rb=x;
    while(rb-lb>1)
    {
        ll mid=(lb+rb)/2;
        ll p=0;
        for(ll i=n-ans;i<n;i++) p+=min(x-a[i],mid);
        if(p>=s) rb=mid; else lb=mid;
    }
    printf("%lld\n",max(a[n-ans-1],rb));
    return 0;
}

