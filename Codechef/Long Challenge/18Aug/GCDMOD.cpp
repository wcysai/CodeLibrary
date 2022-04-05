/*************************************************************************
    > File Name: GCDMOD.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-05 11:31:25
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
ll t,a,b,n;
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&a,&b,&n);
        if(a<b) swap(a,b);
        ll x=a-b,ans=1;
        if(x%2==0) {x/=2; ans=2;}
        ll g=gcd(b,x);
        if(g==1) {printf("%lld\n",ans); continue;}
        for(ll i=1;i<=n;i++)
        {
            if(g==1) break;
            ans=1LL*ans*g%MOD;
            x=x/g;
            g=gcd(b,x);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

