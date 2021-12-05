#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
int dp[MAXN][10];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    dp[0][a[1]]=1;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<=9;j++)
        {
            if(!dp[i][j]) continue;
            //add
            add(dp[i+1][(j+a[i+2])%10],dp[i][j]);
            //mult
            add(dp[i+1][j*a[i+2]%10],dp[i][j]);
        }
    }
    for(int i=0;i<=9;i++) printf("%d\n",dp[n-1][i]);
    return 0;
}