#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 405
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int T,N;
ll ans;
ll dp[MAXN][MAXN];
int opt[MAXN][MAXN];
ll sum[MAXN];
deque<int> v;
void solve()
{
    for(int i=0;i<N;i++)
        for(int j=i;j<N;j++)
            dp[i][j]=INF;
    sum[0]=0;
    for(int i=0;i<N;i++) sum[i+1]=sum[i]+v[i];
    for(int i=0;i<N;i++) dp[i][i]=0,opt[i][i]=i;
    for(int len=2;len<=N;len++)
    {
        for(int i=0;i+len-1<N;i++)
        {
            int j=i+len-1;
            for(int k=opt[i][j-1];k<=min(j,opt[i+1][j]);k++)
            {
                if(dp[i][k]+dp[k+1][j]+sum[j+1]-sum[i]<dp[i][j])
                {
                    dp[i][j]=dp[i][k]+dp[k+1][j]+sum[j+1]-sum[i];
                    opt[i][j]=k;
                }
            }
        }
    }
    ans=min(ans,dp[0][N-1]);
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        v.clear();
        for(int i=0;i<N;i++)
        {
            int x;
            scanf("%d",&x);
            v.push_back(x);
        }
        ans=INF;
        for(int i=0;i<N;i++)
        {
            solve();
            int x=v.front();
            v.pop_front();
            v.push_back(x);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

