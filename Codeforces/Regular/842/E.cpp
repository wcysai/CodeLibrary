#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 3000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,M;
void add(int &a,int b) {a+=b; if(a>=M) a-=M;}
void dec(int &a,int b) {a-=b; if(a<0) a+=M;}
int pow_mod(int a,int i){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%M;
        a=1LL*a*a%M;
        i>>=1;
    }
    return s;
}
int fact[MAXN],invf[MAXN];
int comb(int n,int k){
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%M*invf[n-k]%M;
}
int main()
{
    scanf("%d%d",&n,&M);
    fact[0]=invf[0]=1;
    for(int i=1;i<=3000000;i++) fact[i]=1LL*fact[i-1]*i%M;
    invf[3000000]=pow_mod(fact[3000000],M-2);
    for(int i=2999999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%M;
    //once
    int once=(2LL*fact[2*n]-fact[n]-1+2*M)%M;
    int ans=(2LL*fact[2*n]-fact[n]-1+2*M)%M;
    //twice
    int twice=0;
    for(int i=0;i<=n;i++){
        int rep=1LL*comb(n,i)*comb(n,n-i)%M;
        rep=1LL*rep*(comb(2*n,n)+M)%M; 
        rep=1LL*rep*fact[n]%M*fact[n]%M*fact[n]%M;
        add(twice,rep);
    }
    for(int i=0;i<=n;i++){
        int rep=1LL*comb(n,i)*comb(n,n-i)%M;
        rep=1LL*rep*(comb(2*n,n)+M-comb(2*n-i,n))%M;
        rep=1LL*rep*fact[n]%M*fact[n]%M*fact[n]%M;
        add(twice,rep);
    }
    dec(twice,once); dec(twice,1);
    add(ans,2LL*twice%M);
    int thrice=fact[3*n];
    dec(thrice,1); dec(thrice,once); dec(thrice,twice);
    add(ans,3LL*thrice%M);
    printf("%d\n",ans);
    return 0;
}

