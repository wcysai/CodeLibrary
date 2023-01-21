#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN],p[MAXN];
int dp[MAXN][2];
int pre[MAXN][2];
int ans[MAXN];
void upd(int &x,int y) {x=min(x,y);}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&p[i]);
        dp[1][0]=dp[1][1]=-INF;
        for(int i=2;i<=n;i++){
            for(int j=0;j<2;j++)
            {
                dp[i][j]=INF;
                int x=(j==0?p[i]:-p[i]);
                if(x>p[i-1]&&dp[i-1][0]<dp[i][j]) {dp[i][j]=dp[i-1][0]; pre[i][j]=0;}
                if(x>-p[i-1]&&dp[i-1][1]<dp[i][j]) {dp[i][j]=dp[i-1][1]; pre[i][j]=1;}
                if(x>dp[i-1][0]&&p[i-1]<dp[i][j]) {dp[i][j]=p[i-1]; pre[i][j]=0;}
                if(x>dp[i-1][1]&&-p[i-1]<dp[i][j]) {dp[i][j]=-p[i-1]; pre[i][j]=1;} 
            }
        }
        if(dp[n][0]==INF&&dp[n][1]==INF) {puts("NO"); continue;}
        puts("YES");
        int x=n,y=(dp[n][0]==INF?1:0);
        while(x>=1){
            ans[x]=y;
            y=pre[x][y];
            x--;
        }
        for(int i=1;i<=n;i++) printf("%d%c",ans[i]?-p[i]:p[i],i==n?'\n':' ');
    }
    return 0;
}

