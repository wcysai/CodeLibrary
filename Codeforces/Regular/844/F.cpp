#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,p,q;
int p2[MAXN],invp2[MAXN],p23[MAXN],p13[MAXN],fact[MAXN],invf[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int comb(int n,int k){
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int f[MAXN][MAXN],g[MAXN][MAXN];
int ffact[MAXN],invff[MAXN];
int main()
{
    fact[0]=invf[0]=p2[0]=p13[0]=invp2[0]=ffact[0]=invff[0]=ffact[1]=invff[1]=1;
    for(int i=1;i<=500;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    for(int i=2;i<=1000;i++) ffact[i]=1LL*ffact[i-2]*i%MOD;
    invff[1000]=pow_mod(ffact[1000],MOD-2); invff[999]=pow_mod(ffact[999],MOD-2);
    for(int i=998;i>=2;i--) invff[i]=1LL*invff[i+2]*(i+2)%MOD;
    invf[500]=pow_mod(fact[500],MOD-2);
    for(int i=499;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    int inv=pow_mod(10000,MOD-2);
    for(int i=1;i<=500;i++) p2[i]=2LL*p2[i-1]%MOD;
    int inv2=pow_mod(2,MOD-2),inv3=pow_mod(3,MOD-2);
    for(int i=1;i<=500;i++) invp2[i]=1LL*inv2*invp2[i-1]%MOD;
    for(int i=1;i<=500;i++) p13[i]=1LL*inv3*p13[i-1]%MOD;
    scanf("%d%d",&n,&q);
    p=1LL*q*inv%MOD;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(j>=i) f[i][j]=1;
            else{
                for(int x=0;x<=i-1;x++){
                    add(f[i][j],1LL*p*comb(i-1,x)%MOD*invff[2*i-1]%MOD*ffact[2*x]%MOD*(x==i-1?1:ffact[2*(i-1-x)-1])%MOD*g[x][j]%MOD*f[i-1-x][j+1]%MOD);
                    if(j) add(f[i][j],1LL*(MOD+1-p)*comb(i-1,x)%MOD*invff[2*i-1]%MOD*ffact[2*x]%MOD*(x==i-1?1:ffact[2*(i-1-x)-1])%MOD*g[x][j]%MOD*f[i-1-x][j-1]%MOD);
                }
            }
            if(j>=i) g[i][j]=1;
            else{
                for(int x=0;x<=i;x++){
                    add(g[i][j],1LL*comb(i,x)*invff[2*i]%MOD*(x==0?1:ffact[2*x-1])%MOD*(x==i?1:ffact[2*(i-x)-1])%MOD*f[x][j]%MOD*f[i-x][j]%MOD);
                }

            }
        }
        f[i][n+1]=g[i][n+1]=1;
    }
    printf("%d\n",f[n][0]);
    return 0;
}

