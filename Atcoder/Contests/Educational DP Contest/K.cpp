#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define MAXK 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int dp[MAXK];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(dp,0,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=k;i++)
    {
        bool f=false;
        for(int j=1;j<=n;j++)
            if(i>=a[j]&&dp[i-a[j]]==0) f=true;
        if(f) dp[i]=1; else dp[i]=0;
    }
    if(dp[k]) puts("First"); else puts("Second");
    return 0;
}

