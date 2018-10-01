/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-01 16:33:58
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
ll n,m;
ll pow_(ll a,ll i)
{
    ll s=1;
    while(i)
    {
        if(i&1) s=s*a;
        a=a*a;
        i>>=1;
    }
    return s;
}
int main()
{
    scanf("%lld%lld",&n,&m);
    n=pow_(10,n);m=pow_(10,m);m--;
    while(m!=0)
    {
        printf("%lld\n",n/m);
        n-=m*(n/m);swap(n,m);
    }
    return 0;
}

