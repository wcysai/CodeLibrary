#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int dp[MAXN][4];
void upd(int &a,int b) {a=max(a,b);}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=0;i<=n;i++)
            for(int j=0;j<4;j++)
                dp[i][j]=-INF;
        dp[0][0]=0;
        for(int i=0;i<n;i++){
            //for(int j=0;j<4;j++) printf("%d %d %d\n",i,j,dp[i][j]);
            if(dp[i][0]!=-INF){
                upd(dp[i+1][0],dp[i][0]);
                upd(dp[i+1][1],dp[i][0]+a[i+1]-1);
            }
            if(dp[i][1]!=-INF){
                upd(dp[i+1][1],dp[i][1]-1);
                upd(dp[i+1][2],dp[i][1]+a[i+1]-1);
            }
            if(dp[i][2]!=-INF){
                upd(dp[i+1][2],dp[i][2]-1);
                upd(dp[i+1][3],dp[i][2]+a[i+1]-1);
            }
            if(dp[i][3]!=-INF){
                upd(dp[i+1][3],dp[i][3]);
            }
        }
        printf("%d\n",dp[n][3]+1);
    }
    return 0;
}

