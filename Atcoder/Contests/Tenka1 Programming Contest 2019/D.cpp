#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 305
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
int dp[MAXN][2*MAXN*MAXN];
int dp2[MAXN][MAXN*MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int main()
{
    scanf("%d",&n);
    int sum=0;
    for(int i=0;i<n;i++) 
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    dp[0][300*300]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=2*300*300;j++)
        {
            if(!dp[i][j]) continue;
            add(dp[i+1][j-a[i]],dp[i][j]);
            add(dp[i+1][j+a[i]],2LL*dp[i][j]%MOD);
        }
    }
    dp2[0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=300*300;j++)
        {
            if(!dp2[i][j]) continue;
            add(dp2[i+1][j],dp2[i][j]);
            add(dp2[i+1][j+a[i]],dp2[i][j]);
        }
    }
    int ans=pow_mod(3,n);
    for(int j=0;j<=300*300;j++) dec(ans,3LL*dp[n][j]%MOD);
    if(sum%2==0) add(ans,3LL*dp2[n][sum/2]%MOD);
    printf("%d\n",ans);
    return 0;
}

