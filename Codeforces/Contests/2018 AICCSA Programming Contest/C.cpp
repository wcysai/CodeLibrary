/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-01 18:07:22
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,k,a[MAXN];
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
int comb(int n,int k)
{
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=1000001;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[1000001]=pow_mod(fact[1000001],MOD-2);
    for(int i=1000000;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int ans=0;
        for(int i=1;i<=n;i++) 
        {
            ans=(ans+1LL*a[i]*(comb(n+1,i)-1))%MOD;
            if(ans<0) ans+=MOD;
        }
        if(ans<0) ans+=MOD;
        printf("%d\n",ans);
    }
    return 0;
}

