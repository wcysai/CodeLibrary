/*************************************************************************
    > File Name: XORIER.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-11 16:53:09
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
ll t,n,k,a[MAXN],num[MAXN];
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        memset(num,0,sizeof(num));
        scanf("%lld",&n);
        ll even=0,odd=0;
        for(ll i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);num[a[i]]++;
            if(a[i]&1) odd++; else even++;
        }
        ll ans=0;
        for(ll i=0;i<n;i++)
        {
            if(a[i]&1) ans+=odd-num[a[i]^2]-num[a[i]];
            else ans+=even-num[a[i]^2]-num[a[i]];
        }
        printf("%lld\n",ans/2);
    }
    return 0;
}

