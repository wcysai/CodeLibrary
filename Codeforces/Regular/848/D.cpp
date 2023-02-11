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
int t,n;
int inv[MAXN];
P dp[MAXN];
char a[MAXN],b[MAXN];
int pow_mod(int a,int i){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int main()
{
    inv[1]=1;
    for(int i=2;i<=1000000;i++) inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        dp[0]=P(0,0); dp[1]=P(1,0);
        for(int i=1;i<=n-1;i++){
            dp[i+1].F=1LL*n*inv[n-i]%MOD*dp[i].F%MOD;
            dec(dp[i+1].F,1LL*i*inv[n-i]%MOD*dp[i-1].F%MOD);
            dp[i+1].S=1LL*n*inv[n-i]%MOD*dp[i].S%MOD;
            dec(dp[i+1].S,1LL*i*inv[n-i]%MOD*dp[i-1].S%MOD);
            dec(dp[i+1].S,1LL*n*inv[n-i]%MOD);
        }
        int cf=dp[n].F; dec(cf,dp[n-1].F);
        int res=dp[n-1].S; add(res,1); dec(res,dp[n].S);
        int x=1LL*res*pow_mod(cf,MOD-2)%MOD;
        scanf("%s",a+1);
        scanf("%s",b+1);
        int cnt=0;
        for(int i=1;i<=n;i++) if(a[i]!=b[i]) cnt++;
        int ans=1LL*dp[cnt].F*x%MOD;
        add(ans,dp[cnt].S);
        printf("%d\n",ans);
    }
    return 0;
}

