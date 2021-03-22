#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int dp[MAXN];
int main()
{
    for(int i=1;i<=100000;i++)
    {
        dp[i]=max(dp[i],1);
        for(int j=2*i;j<=100000;j+=i) dp[j]=max(dp[j],dp[i]+1);
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++) printf("%d%c",dp[i],i==n?'\n':' ');
    return 0;
}