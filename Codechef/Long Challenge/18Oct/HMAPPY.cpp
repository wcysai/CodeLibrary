/*************************************************************************
    > File Name: HMAPPY.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-07 03:39:52
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll N,M,A[MAXN],B[MAXN];
bool C(ll x)
{
    ll now=0;
    for(ll i=0;i<N;i++)
    {
        if(B[i]==0) now+=A[i];
        else now+=max(0LL,A[i]-x/B[i]);
    }
    return now<=M;
}
int main()
{
    scanf("%lld%lld",&N,&M);
    for(ll i=0;i<N;i++) scanf("%lld",&A[i]);
    for(ll i=0;i<N;i++) scanf("%lld",&B[i]);
    ll l=-1,r=INF;
    while(r-l>1)
    {
        ll mid=(l+r)/2;
        if(C(mid)) r=mid; else l=mid;
    }
    printf("%lld\n",r);
    return 0;
}

