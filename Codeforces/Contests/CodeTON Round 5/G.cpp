#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,v,a[MAXN];
int dp[MAXN][MAXN],inv[MAXN];
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
int main()
{
    scanf("%d%d%d",&n,&m,&v);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) inv[i]=pow_mod(i,MOD-2);
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(!dp[i][j]) continue;
            add(dp[i+1][j],1LL*dp[i][j]*a[i+1]%MOD);
            add(dp[i+1][j],1LL*j*dp[i][j]%MOD*v%MOD);
            add(dp[i+1][j+1],1LL*(m-j)*dp[i][j]%MOD*v%MOD*(i+1)%MOD*inv[n]%MOD);
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++) add(ans,dp[n][i]);
    printf("%d\n",ans);
    return 0;
}

