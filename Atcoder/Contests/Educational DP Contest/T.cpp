#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,dp[MAXN][MAXN],sum[MAXN];
char str[MAXN+1];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    scanf("%d",&n);
    scanf("%s",str+2);
    str[1]='<';
    dp[0][n]=1;
    for(int i=1;i<=n;i++)
    {
        memset(sum,0,sizeof(sum));
        sum[0]=dp[i-1][0];
        for(int j=1;j<=n;j++) 
        {
            sum[j]=sum[j-1];
            add(sum[j],dp[i-1][j]);
        }
        for(int j=0;j<=n-i;j++)
        {
            if(str[i]=='<') dp[i][j]=(sum[n]-sum[j]+MOD)%MOD;
            else dp[i][j]=sum[j];
        }
    }
    printf("%d\n",dp[n][0]);
    return 0;
}

