/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-02 12:12:50
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
    scanf("%lld%lld",&n,&k);
    ll ans=0;
    ans=(n/k)*(n/k)*(n/k);
    if(k%2==0)
    {
        if(n>=k/2)
        {
            ll cnt=(n-k/2)/k+1;
            ans+=cnt*cnt*cnt;
        }
    }
    printf("%lld\n",ans);
    return 0;
}

