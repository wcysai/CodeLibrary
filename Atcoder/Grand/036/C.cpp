#include<bits/stdc++.h>
#define MAXN 3000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int fact[MAXN],invf[MAXN];
int N,M;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
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
    for(int i=1;i<=3000000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[3000000]=pow_mod(fact[3000000],MOD-2);
    for(int i=2999999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d",&N,&M);
    int ans=0;
    for(int i=0;i<=M;i++) if((3*M-i)%2==0) add(ans,1LL*comb(N,i)*comb((3*M-i)/2+N-1,N-1)%MOD);
    for(int i=0;i<=M;i++) if((M-i)%2==0) dec(ans,1LL*N*comb(N,i)%MOD*comb((M-i)/2+N-1,N-1)%MOD);
    for(int i=0;i<=M;i++) if((M-i)%2==0) add(ans,1LL*N*comb(N-1,i)%MOD*comb((M-i)/2+N-2,N-2)%MOD);
    printf("%d\n",ans);
    return 0;
}
