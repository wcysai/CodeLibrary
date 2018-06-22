/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-22 19:01:46
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
int n,k,a[MAXN];
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
    scanf("%d",&n);
    fact[0]=invf[0]=1;
    n--;
    for(int i=1;i<=n;i++)
        fact[i]=1LL*fact[i-1]*i%MOD;
    invf[n]=pow_mod(fact[n],MOD-2);
    for(int i=n-1;i>=1;i--)
        invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    int ans=0;
    for(int i=0;2*i<=n;i+=2)
    {
        int res=((1LL*fact[n]*invf[i]%MOD)*invf[i]%MOD)*invf[n-2*i]%MOD;
        ans=(ans+res)%MOD;
    }
    printf("%d\n",ans);
    return 0;
}

