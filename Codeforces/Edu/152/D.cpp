#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int dp[MAXN][3];
void upd(int &a,int b) {a=min(a,b);}
//0: just fine
//1: need help
//2: have one more
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=2;j++)
            dp[i][j]=INF;
    dp[0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            if(dp[i][j]==INF) continue;
            //paint it
            if(j==1&&a[i+1]==0) continue;
            int x=a[i+1]-(j==1?1:0);
            upd(dp[i+1][x?2:0],dp[i][j]+1);
            //use from left
            if(j==2){
                upd(dp[i+1][a[i+1]?2:0],dp[i][j]);
            }
            //use from right
            upd(dp[i+1][1],dp[i][j]);
        }
    }
    printf("%d\n",min(dp[n][0],dp[n][2]));
    return 0;
}

