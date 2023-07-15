#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int dp[MAXN][(1<<10)];
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
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    dp[0][1]=1;
    for(int i=0;i<n;i++){
        for(int mask=0;mask<(1<<10);mask++){
            if(!dp[i][mask]) continue;
            for(int j=1;j<=min(a[i+1],9);j++){
                int nmask=(mask|(mask<<j));
                if(nmask&(1<<10)) continue;
                add(dp[i+1][nmask&((1<<10)-1)],dp[i][mask]);
            }
            if(a[i+1]>10) add(dp[i+1][mask],1LL*(a[i+1]-10)*dp[i][mask]%MOD);
        }
    }
    int ans=0;
    for(int mask=0;mask<(1<<10);mask++) add(ans,dp[n][mask]);
    int res=1;
    for(int i=1;i<=n;i++) res=1LL*res*a[i]%MOD;
    ans=1LL*ans*pow_mod(res,MOD-2)%MOD;
    ans=(MOD+1-ans)%MOD;
    printf("%d\n",ans);
    return 0;
}

