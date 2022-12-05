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
int n,k,a[MAXN];
int p2[MAXN],p3[MAXN],fact[MAXN],invf[MAXN];
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
    p2[0]=p3[0]=fact[0]=invf[0]=1;
    for(int i=1;i<=1000000;i++) p2[i]=2LL*p2[i-1]%MOD;
    for(int i=1;i<=1000000;i++) p3[i]=3LL*p3[i-1]%MOD;
    for(int i=1;i<=1000000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[1000000]=pow_mod(fact[1000000],MOD-2);
    for(int i=999999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d",&n,&k);
    if(k==0) {printf("%d\n",p3[n]); return 0;}
    int ans=0;
    for(int i=1;i<=k;i++)
    {
        int way=1LL*comb(k-1,i-1)*p3[k-i]%MOD;
        //touch nothng
        if(n-k>=i+1) add(ans,3LL*way*comb(n-k-1,i)%MOD*p3[n-k-(i+1)]%MOD);
        //touch first/last
        if(n-k>=i) add(ans,4LL*way*comb(n-k-1,i-1)%MOD*p3[n-k-i]%MOD);
        //touch both
        if(i>1&&n-k>=i-1) add(ans,1LL*way*comb(n-k-1,i-2)%MOD*p3[n-k-(i-1)]%MOD);
    }
    printf("%d\n",ans);
    return 0;
}

