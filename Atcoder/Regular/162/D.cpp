#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,d[MAXN],fact[MAXN],invf[MAXN],inv[MAXN];
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
int dp[MAXN][2*MAXN],ndp[MAXN][2*MAXN];
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=500;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[500]=pow_mod(fact[500],MOD-2);
    for(int i=499;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    for(int i=1;i<=500;i++) inv[i]=1LL*invf[i]*fact[i-1]%MOD;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&d[i]);
    d[1]--;
    int num=fact[n-2];
    for(int i=1;i<=n;i++) num=1LL*num*invf[d[i]]%MOD;
    int ans=num;
    for(int i=2;i<=n;i++) if(d[i]==0) add(ans,num);
    dp[0][500]=1;
    for(int i=1;i<=n-1;i++){
        memset(ndp,0,sizeof(ndp));
        for(int chosen=0;chosen<=n-1;chosen++){
            for(int sum=-500;sum<=500;sum++){
                if(!dp[chosen][sum+500]) continue;
                add(ndp[chosen][sum+500],dp[chosen][sum+500]);
                add(ndp[chosen+1][sum+500+d[i+1]-1],1LL*(chosen?1:(d[i+1]))*dp[chosen][sum+500]%MOD);
            }
        }
        swap(dp,ndp);
    }
    for(int i=2;i<=n-1;i++){
        add(ans,1LL*dp[i][499]*num%MOD*invf[n-2]%MOD*fact[i-2]%MOD*fact[n-i-1]%MOD);
    }
    printf("%d\n",ans);
    return 0;
}

