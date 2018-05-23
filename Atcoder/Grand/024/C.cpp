/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-23 14:41:27
 ************************************************************************/

#include<bits/stdc++.h>
#define MAXN 200005
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
    for(ll i=0;i<n;i++)
        scanf("%lld",&a[i]);
    for(ll i=1;i<n;i++)
        if(a[i]-a[i-1]>1) 
        {
            puts("-1");
            return 0;
        }
    if(a[0]!=0) 
    {
        puts("-1");
        return 0;
    }
    ll ans=0;
    for(ll i=1;i<n;i++)
        if(a[i]!=a[i-1]+1) ans+=a[i-1];
    ans+=a[n-1];
    printf("%lld\n",ans);
    return 0;
}

