#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 22
#define MAXM 4000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN][MAXN],dp[MAXN][MAXM];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(1<<n);j++)
        {
            if(!dp[i][j]) continue;
            for(int k=1;k<=n;k++) 
            {
                if(j&(1<<(k-1))) continue;
                if(!a[i+1][k]) continue;
                add(dp[i+1][j|(1<<(k-1))],dp[i][j]);
            }
        }
    }
    printf("%d\n",dp[n][(1<<n)-1]);
    return 0;
}

