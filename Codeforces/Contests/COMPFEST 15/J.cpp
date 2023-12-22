#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 405
#define INF 1000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x,y,a[MAXN],c[MAXN];
ll dp[MAXN][MAXN],dp1[MAXN][MAXN],dp2[MAXN][MAXN];//dp1: moves to right, dp2: moves to left
bool same[MAXN][MAXN];
int main(){
    scanf("%d%d%d",&n,&x,&y);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n;i++){
        same[i][i]=true;
        for(int j=i+1;j<=n;j++)
            if(c[j]==c[j-1]) same[i][j]=same[i][j-1]; else same[i][j]=false;
    }
    for(int len=1;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            if(c[i]!=c[j]){
                dp1[i][j]=dp2[i][j]=INF;
            }
            else if(same[i][j]){
                dp1[i][j]=1LL*y*(j-i+1)+x; dp2[i][j]=x;
            }
            else{
                dp1[i][j]=dp2[i][j]=INF;
                for(int p=i+1;p<=j;p++) if(c[p]==c[i]) dp1[i][j]=min(dp1[i][j],y+dp[i+1][p-1]+dp1[p][j]);
                for(int p=i+1;p<=j;p++) if(c[p]==c[i]) dp2[i][j]=min(dp2[i][j],y*2+dp[i+1][p-1]+dp2[p][j]);
            }
            dp[i][j]=INF;
            for(int p=i;p<j;p++) dp[i][j]=min(dp[i][j],dp[i][p]+dp[p+1][j]);
            if(c[i]==c[j]) dp[i][j]=min(dp[i][j],min(dp1[i][j],dp2[i][j]));
            //printf("i=%d j=%d dp=%lld dp1=%lld dp2=%lld\n",i,j,dp[i][j],dp1[i][j],dp2[i][j]);
        }
    }
    printf("%lld\n",dp[1][n]);
    return 0;
}

