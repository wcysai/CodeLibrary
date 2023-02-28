#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,c[MAXN],t[MAXN],sum[MAXN],cnt[MAXN],fact[MAXN],invf[MAXN];
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
int dp[MAXN],ndp[MAXN];
int main(){
    fact[0]=invf[0]=1;
    for(int i=1;i<=200;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[200]=pow_mod(fact[200],MOD-2);
    for(int i=199;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d",&n);
    int cf=1;
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n;i++){
        scanf("%d",&t[i]);
        sum[t[i]]+=c[i]; 
        cnt[t[i]]++;
    }
    for(int i=1;i<=n;i++) cf=1LL*cf*fact[sum[i]]%MOD;
    for(int i=1;i<=n;i++) cf=1LL*cf*invf[c[i]]%MOD;
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=1;i<=n;i++){
        memset(ndp,0,sizeof(ndp));
        for(int j=0;j<=n;j++){
            if(!dp[j]) continue;
            for(int k=0;j+k<=n&&k<=cnt[i]&&k<=sum[i];k++){
                add(ndp[j+k],1LL*comb(cnt[i],k)*dp[j]%MOD*invf[sum[i]-k]%MOD);
            }
        }
        swap(dp,ndp);
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        if(i&1) dec(ans,1LL*dp[i]*cf%MOD*fact[n-i]%MOD);
        else add(ans,1LL*dp[i]*cf%MOD*fact[n-i]%MOD);
    }
    printf("%d\n",ans);
    return 0;
}

