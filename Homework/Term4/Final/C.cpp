/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-06 09:26:27
 ************************************************************************/

#include<bits/stdc++.h>
#define MAXN 12
#define MAXK 18
#define INF 1e6
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
double m;
double dp[MAXN][MAXN][MAXN][MAXN][MAXK]; 
int a[MAXN][MAXN],sum[MAXN][MAXN];
double _pow(double x) {return x*x;} 
//dp[x1][y1][x2][y2][k]:minimal contribution to the standard deviation when (x1,y1) to (x2,y2) to be cut into k pieces
double solve(int x1,int y1,int x2,int y2,int k)
{
    if(dp[x1][y1][x2][y2][k]!=-1) return dp[x1][y1][x2][y2][k];
    if(k==1) 
    {
        if(x1>x2||y1>y2) return dp[x1][y1][x2][y2][k]=_pow(m);
        //printf("%d %d %d %d %d\n",x1,y1,x2,y2,sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1]);
        return dp[x1][y1][x2][y2][k]=_pow((double)sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1]-m);
    }
    double ans=INF;
    //[x1,i) [i,x2]
    for(int i=x1;i<=x2+1;i++)
    {
        ans=min(ans,solve(x1,y1,i-1,y2,1)+solve(i,y1,x2,y2,k-1));
        ans=min(ans,solve(x1,y1,i-1,y2,k-1)+solve(i,y1,x2,y2,1));
    }
    //[y1,i) [i,y2]
    for(int i=y1;i<=y2+1;i++)
    {
        ans=min(ans,solve(x1,y1,x2,i-1,1)+solve(x1,i,x2,y2,k-1));
        ans=min(ans,solve(x1,y1,x2,i-1,k-1)+solve(x1,i,x2,y2,1));
    }
    return dp[x1][y1][x2][y2][k]=ans;

}
int main()
{
    scanf("%d",&n);
    int s=0;
    for(int i=1;i<=8;i++)
        for(int j=1;j<=8;j++)
        {
            scanf("%d",&a[i][j]);
            s+=a[i][j];
        }
    for(int i=1;i<=8;i++)
        for(int j=1;j<=8;j++)
            sum[i][j]=a[i][j]+sum[i][j-1];
    for(int j=1;j<=8;j++)
        for(int i=1;i<=8;i++)
            sum[i][j]+=sum[i-1][j];
    /*for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=8;j++)
            printf("%d ",sum[i][j]);
        puts("");
    }*/
    m=s/(double)n;
    for(int i=1;i<=8;i++)
        for(int j=1;j<=8;j++)
            for(int k=1;k<=8;k++)
                for(int l=1;l<=8;l++)
                    for(int p=1;p<=n;p++)
                        dp[i][j][k][l][p]=-1;
    /*printf("%.3f\n",m);
    printf("%.3f\n",solve(1,1,8,3,1));
    printf("%.3f\n",solve(1,4,8,8,2));
    printf("%.3f\n",solve(1,4,4,8,1));
    printf("%.3f\n",solve(5,4,8,8,1));*/
    printf("%.3f\n",sqrt(solve(1,1,8,8,n)/n));
    return 0;
}

