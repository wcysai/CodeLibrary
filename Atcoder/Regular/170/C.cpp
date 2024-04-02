#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN],s[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int dp[MAXN][MAXN];
int main(){
    scanf("%d%d",&n,&m);
    dp[0][0]=1;
    for(int i=1;i<=n;i++) scanf("%d",&s[i]);
    int lim=min(m+1,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<=min(m+1,i);j++){
            if(!dp[i][j]) continue;
            if(s[i+1]==1){
                if(j<m+1) add(dp[i+1][j+1],dp[i][j]);
            }
            else{
                add(dp[i+1][j+1],1LL*dp[i][j]*(m+1-j-1)%MOD);
                add(dp[i+1][j],1LL*dp[i][j]*j%MOD);
            }
        }
    }
    int ans=0;
    for(int i=0;i<=min(m+1,n);i++) add(ans,dp[n][i]);
    printf("%d\n",ans);
    return 0;
}

