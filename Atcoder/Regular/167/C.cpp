#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],fact[MAXN],invf[MAXN],sum[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
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
int main(){
    fact[0]=invf[0]=1;
    for(int i=1;i<=5000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[5000]=pow_mod(fact[5000],MOD-2);
    for(int i=4999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    sum[n]=a[n]%MOD;
    for(int i=n-1;i>=1;i--) {
        sum[i]=(sum[i+1]+a[i])%MOD;
    }
    int ans=0;
    for(int i=2;i<=n;i++){
        int len=min(i-1,k);
        for(int j=1;j<=n;j++){
            int x=j-1,y=n-j;
            add(ans,1LL*comb(n-j,len-1)*fact[len]%MOD*x%MOD*a[j]%MOD*fact[n-len-1]%MOD);
            add(ans,1LL*comb(n-j-1,len-1)*fact[len]%MOD*sum[j+1]%MOD*fact[n-len-1]%MOD);
        }
    }
    printf("%d\n",ans);
    return 0;
}

