/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-15 00:06:45
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
ll n,k,a[MAXN];
int main()
{
    scanf("%lld",&n);
    ll ans=0;
    for(ll i=2;i<=n;i++) ans+=i*(n/i-1);
    printf("%lld\n",ans*4);
    return 0;
}

