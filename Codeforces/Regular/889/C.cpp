#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define INV 500000004
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
int dp[MAXN][MAXN];
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
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m+1;i++){
        dp[i][i]=0;
        dp[i][m+1]=m+1-i;
    }
    for(int i=m;i>=1;i--)
        for(int j=m;j>=i+1;j--){
            dp[i][j]=dp[i+1][j];
            add(dp[i][j],1);
            add(dp[i][j],dp[i][j+1]);
            dp[i][j]=1LL*dp[i][j]*INV%MOD;
            //printf("i=%d  j=%d dp=%d\n",i,j,dp[i][j]);
        }
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int ans=0;
    for(int i=1;i<=n-1;i++) add(ans,dp[a[i]][a[i+1]]);
    add(ans,dp[a[n]][m+1]);
    //ans=1LL*ans*n%MOD*INV%MOD;
    printf("%d\n",ans);
    return 0;
}

