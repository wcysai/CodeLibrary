#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define double long double
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
double dp[MAXN][MAXN];
void upd(double &a,double b) {a=min(a,b);}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            dp[i][j]=1e9;
    dp[0][0]=0.0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            if(dp[i][j]==1e9) continue;
            for(int k=1;j+k*(n-i)<=m;k++) upd(dp[i+1][j+k],dp[i][j]+1.0*j/k);
        }
    }
    printf("%.10Lf\n",n+2.0*dp[n][m]);
    return 0;
}

