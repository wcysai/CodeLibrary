/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-07 15:58:31
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
ll dp[25][15][2][2];
ll solve(ll now,ll last,ll equal,ll zero)
{
    if(now==0) return 1;
    if(dp[now][last][equal][zero]!=-1) return dp[now][last][equal][zero];
    ll res=0;
    if(zero)
    {
        ll lim=equal?a[now]:9;
        for(ll i=0;i<=lim;i++)
            res+=solve(now-1,i,equal&&(i==a[now]),i==0);
        return dp[now][last][equal][zero]=res;
    }
    if(!equal)
    {
        if(last!=9) res+=solve(now-1,last+1,equal,zero);
        res+=solve(now-1,last,equal,zero);
        if(last!=0) res+=solve(now-1,last-1,equal,zero);
        return dp[now][last][equal][zero]=res;
    }
    else
    {
        if(last!=9&&last+1<=a[now]) res+=solve(now-1,last+1,(last+1==a[now]),zero);
        if(last<=a[now]) res+=solve(now-1,last,(last==a[now]),zero);
        if(last!=0&&last-1<=a[now]) res+=solve(now-1,last-1,(last-1==a[now]),zero);
        return dp[now][last][equal][zero]=res;
    }
}
ll calc(ll x)
{
    ll t=0;
    while(x) {t++; a[t]=x%10; x/=10;}
    memset(dp,-1,sizeof(dp));
    return solve(t,0,1,1);
}
int main()
{
    scanf("%lld%lld",&k,&n);
    ll l=0,r=LLONG_MAX;
    ll num=calc(n)+k;
    while(r-l>1)
    {
        ll mid=((unsigned long long)l+r)/2;
        if(calc(mid)>=num) r=mid; else l=mid;
    }
    printf("%lld\n",r);
    return 0;
}

