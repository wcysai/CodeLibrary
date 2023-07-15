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
int t,n,k,a[MAXN];
int maxi[MAXN],dp[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++) maxi[i]=-INF;
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1];
            dp[i]=max(dp[i],maxi[a[i]]+i+1);
            maxi[a[i]]=max(maxi[a[i]],dp[i-1]-i);
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}

