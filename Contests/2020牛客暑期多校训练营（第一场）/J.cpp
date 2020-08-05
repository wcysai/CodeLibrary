#include<bits/stdc++.h>
#define MAXN 2000005
#define INF 1000000000
#define MOD 998244353
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
int comb(int n,int k)
{
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=2000000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[2000000]=pow_mod(fact[2000000],MOD-2);
    for(int i=1999999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    while(scanf("%d",&n)==1)
    {
        int res=1LL*fact[n]*fact[n]%MOD*invf[2*n+1]%MOD;
        printf("%d\n",res);
    }
    return 0;
}