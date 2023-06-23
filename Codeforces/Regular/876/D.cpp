#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,c[MAXN];
int dp[MAXN][MAXN],ndp[MAXN][MAXN];
void upd(int &a,int b) {a=max(a,b);}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&c[i]);
        for(int i=0;i<=n;i++) 
            for(int j=0;j<=n;j++)
                dp[i][j]=-INF;
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int i=0;i<=n;i++) 
                for(int j=0;j<=n;j++)
                    ndp[i][j]=-INF;
            for(int seg=0;seg<=n;seg++)
                for(int last=0;last<=n;last++){
                    if(dp[seg][last]==-INF) continue;
                    upd(ndp[seg+((last==i-1)?1:0)][last],dp[seg][last]);
                    if(c[i]>c[last]) upd(ndp[seg][i],dp[seg][last]+1);
                }
            swap(dp,ndp);
        }
        for(int i=1;i<=n;i++){
            int ans=INF;
            for(int j=0;j<=i;j++) 
                for(int k=0;k<=n;k++)
                    ans=min(ans,n-dp[j][k]);
            printf("%d%c",ans,i==n?'\n':' ');
        }
    }
    return 0;
}

