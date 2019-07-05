#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 1005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,k,a[MAXN];
int dp[MAXN][MAXN];
int rpos[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
vector<P> v;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) rpos[i]=i+1;
    sort(a+1,a+n+1);
    dp[n+1][0]=1;
    for(int i=n;i>=1;i--) 
    {
        dp[i][0]=1;
        for(int j=1;j<=k;j++) 
        {
            add(dp[i][j],dp[i+1][j]);
            add(dp[i][j],dp[i+1][j-1]);
        }
    }
    int cur=0;
    int ans=0;
    int last=0;
    while(true)
    {
        int mini=INF;
        for(int i=1;i<=n;i++)
        {
            if(rpos[i]<=n) mini=min(mini,a[rpos[i]]-a[i]);
        }
        if(mini==INF) break;
        cur=mini;
        v.push_back(P(dp[1][k],cur));
        printf("%d %d\n",dp[1][k],cur);
        for(int i=n;i>=1;i--)
            while(rpos[i]<=n&&a[rpos[i]]-a[i]==cur)rpos[i]++;
        for(int i=n;i>=1;i--) 
        {
            dp[i][0]=1;
            for(int j=1;j<=k;j++) 
            {
                dp[i][j]=0;
                add(dp[i][j],dp[i+1][j]);
                add(dp[i][j],dp[rpos[i]][j-1]);
            }
        }
    }
    for(int i=(int)v.size()-1;i>=0;i--) 
    {
        add(ans,1LL*v[i].S*(v[i].F+MOD-last)%MOD);
        last=v[i].F;
    }
    printf("%d\n",ans);
    return 0;
}

