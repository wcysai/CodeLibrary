/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-12 14:14:31
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll T,N,a[MAXN];
bool C(ll x)
{
    ll needed=0;
    for(ll i=1;i<=N;i++)
    {
        if(a[i]<x) needed+=x-a[i];
        else needed-=(a[i]-x)/2;
    }
    return (needed<=0);
}
int main()
{
    scanf("%I64d",&T);
    while(T--)
    {
        scanf("%I64d",&N);
        ll mx=-INF;
        for(ll i=1;i<=N;i++) 
        {
            scanf("%I64d",&a[i]);
            mx=max(mx,a[i]);
        }
        if(mx<0) {puts("-1"); continue;}
        ll l=-1,r=mx+1;
        while(r-l>1)
        {
            ll mid=(l+r)/2;
            if(C(mid)) l=mid; else r=mid;
        }
        printf("%I64d\n",l);
    }
    return 0;
}

