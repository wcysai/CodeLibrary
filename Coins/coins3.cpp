/*************************************************************************
    > File Name: coins3.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-19 10:28:54
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN];
ll st[MAXN],t;
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(ll i=1;i<=n;i++)
    {
        st[t++]=a[i];
        while(t>2&&st[t-2]>=st[t-1]&&st[t-2]>=st[t-3])
        {
            ll x=st[t-1]+st[t-3]-st[t-2];
            t-=3;st[t++]=x;
        }
    }
    ll l=0,r=t-1,ans=0,now=1;
    while(l<=r)
    {
        if(st[l]>st[r]) {ans+=now*st[l]; l++;}
        else {ans+=now*st[r]; r--;}
        now*=-1;
    }
    if(ans>0) puts("Alice"); else if(ans<0) puts("Bob"); else puts("Draw");
    return 0;
}

