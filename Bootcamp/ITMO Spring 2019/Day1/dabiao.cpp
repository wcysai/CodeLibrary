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
int fact[MAXN],invf[MAXN],cat[MAXN],ans[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
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
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=200;i++) fact[i]=1LL*i*fact[i-1]%MOD;
    invf[200]=pow_mod(fact[200],MOD-2);
    for(int i=199;i>=1;i--) invf[i]=1LL*(i+1)*invf[i+1]%MOD;
    for(int i=1;i<=100;i++) cat[i]=1LL*comb(2*i,i)*pow_mod(i+1,MOD-2)%MOD;
    ans[0]=ans[1]=1;
    for(int i=2;i<=200;i++) 
        for(int j=1;j<=i;j++)
        {
            add(ans[i],1LL*comb(i,j)*ans[j-1]%MOD*ans[i-j]%MOD);
        }
    for(int i=1;i<=20;i++) printf("%d %d %d\n",i,cat[i],ans[i]);
    return 0;
}

