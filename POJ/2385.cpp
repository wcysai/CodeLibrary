#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=1005;
int a[N],dp[N][35];
int solve(int T,int W){
    int count;
    if(T<W)W=T;
    for(int i=0;i<=W;i++)dp[0][i]=0;
    for(int i=1;i<=T;i++){
        dp[i][0]=dp[i-1][0]+2-a[i];
        for(int j=1;j<=W&&j<=i;j++){
            if(j%2)count=a[i]-1;
            else   count=2-a[i];
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+count;
        }
    }
    count=0;
    for(int i=0;i<=W;i++)
        if(dp[T][i]>count)
            count=dp[T][i];
    return count;
}
int main()
{
    int T,W;
    while(scanf("%d %d",&T,&W)!=EOF){
        for(int i=1;i<=T;i++)
            scanf("%d",&a[i]);
        printf("%d\n",solve(T,W));
    }
    return 0;
}