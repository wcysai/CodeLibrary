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
int n,p;
int dp[MAXN][2*MAXN],sum[MAXN][MAXN];
void add(int &a,int b) {a+=b; if(a>=p) a-=p;}
void dec(int &a,int b) {a-=b; if(a<0) a+=p;}
int get_len(int x)
{
    if(x<=9) return 1;
    else if(x<=99) return 2;
    else if(x<=999) return 3;
    else return 4;
}
int main()
{
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=2*i;j++)
        {
            if(get_len(i)+1==j) dp[i][j]=26; else dp[i][j]=0;
            int tl=1,tr=10;
            for(int k=0;k<4;k++)
            {
                int l=tl,r=min(tr-1,i-1);
                //printf("i=%d j=%d k=%d l=%d r=%d\n",i,j,k,l,r);
                if(l<=r&&j>2+k) {add(dp[i][j],25LL*sum[i-l][j-(2+k)]%p); dec(dp[i][j],25LL*sum[i-r-1][j-(2+k)]%p);}
                tl*=10; tr*=10;
            }
            //printf("i=%d j=%d dp=%d\n",i,j,dp[i][j]);
            sum[i][j]=dp[i][j];
            add(sum[i][j],sum[i-1][j]);
        }
    int ans=0;
    for(int j=1;j<n;j++) add(ans,dp[n][j]);
    printf("%d\n",ans);
    return 0;
}

