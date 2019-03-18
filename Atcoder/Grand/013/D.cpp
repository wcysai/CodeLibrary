#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 3005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,m;
int dp[MAXN][MAXN][2];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int main()
{
    scanf("%d%d",&n,&m);
    n--;m--;
    for(int i=1;i<=n;i++) dp[0][i][0]=1;
    dp[0][0][1]=1;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            for(int k=0;k<2;k++)
            {
                if(!dp[i][j][k]) continue;
                add(dp[i+1][j][k],2LL*dp[i][j][k]%MOD);
                if(j>0)
                {
                    if(k==0&&j==1) add(dp[i+1][j-1][1],dp[i][j][k]);
                    else add(dp[i+1][j-1][k],dp[i][j][k]);
                }
                if(j!=n) add(dp[i+1][j+1][k],dp[i][j][k]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++) add(ans,dp[m][i][1]);
    ans=4LL*ans%MOD;
    printf("%d\n",ans);
    return 0;
}

