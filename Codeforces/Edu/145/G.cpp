#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],dp[MAXN];
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
int fact[MAXN],invf[MAXN];
int main(){
    fact[0]=invf[0]=1;
    for(int i=1;i<=1000000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[1000000]=pow_mod(fact[1000000],MOD-2);
    for(int i=999999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    reverse(a+1,a+n+1);
    if(a[1]-a[2]<=k){
        puts("0"); return 0;
    }
    dp[1]=1;
    for(int i=1;i<n;i++){
        if(!dp[i]) continue;
        add(dp[i+1],1LL*dp[i]*i%MOD);
        int l=i,r=n+1;
        while(r-l>1){
            int mid=(l+r)/2;
            if(a[mid]>=a[i+1]-k) l=mid; else r=mid;
        }
        //printf("i=%d dp=%d l=%d\n",i,dp[i],l);
        //put a[i+2]-a[l] together
        //i*(i+1)*...*(l-2)
        add(dp[l],1LL*dp[i]*fact[l-2]%MOD*invf[i-1]%MOD);
    }
    printf("%d\n",dp[n]);
    return 0;
}

