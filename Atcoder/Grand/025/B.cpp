/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-03 20:07:31
 ************************************************************************/

#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define MAXN 300005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a,b;
ll k;
int fact[MAXN],invf[MAXN];
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int main()
{
    scanf("%d%d%d%lld",&n,&a,&b,&k);
    fact[0]=invf[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=1LL*fact[i-1]*i%MOD;
    invf[n]=pow_mod(fact[n],MOD-2);
    for(int i=n-1;i>=1;i--)
        invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    int ans=0;
    for(int i=0;i<=n;i++)
    {
        if((k-1LL*i*a)%b!=0) continue;
        ll numa=i,numb=(k-1LL*i*a)/b;
        if(min(numa,numb)>n) continue;
        
    }
    return 0;
}

