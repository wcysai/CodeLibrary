#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define MAXK 205
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
int n,x,s[MAXN];
int fact[MAXN],invf[MAXN];
int dp[MAXK][MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
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
int comb(int n,int k) 
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=200;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[200]=pow_mod(fact[200],MOD-2);
    for(int i=199;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++) scanf("%d",&s[i]);
    sort(s+1,s+n+1);
    for(int j=0;j<=x;j++) dp[0][j]=j;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            add(dp[i][j],dp[i-1][j%s[i]]);
            add(dp[i][j],1LL*(i-1)*dp[i-1][j]%MOD);
        }
    }
    printf("%d\n",dp[n][x]);
    return 0;
}

