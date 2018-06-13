/*************************************************************************
    > File Name: 121.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-13 16:46:54
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
ll p,q;
ll a[20];
void dfs(ll now,ll taken)
{
    if(now==16)
    {
        if(taken<=7) return;
        ll res=1;
        for(ll i=1;i<=15;i++)
            if(!a[i]) res*=i;
        p+=res;
        return;
    }
    a[now]=0;
    dfs(now+1,taken);
    a[now]=1;
    dfs(now+1,taken+1);
}
bool C(ll x)
{
    return p*x<=q;
}
int main()
{
    p=0;q=1;
    for(ll i=2;i<=16;i++)
        q*=i;
    dfs(1,0);
    printf("%lld %lld\n",p,q);
    ll l=0,r=q/p+1;
    while(r-l>1)
    {
        ll mid=(l+r)/2;
        if(C(mid)) l=mid; else r=mid;
    }
    printf("%lld\n",l);
    return 0;
}

