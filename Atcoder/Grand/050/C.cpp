#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 1000005
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
int n,dp[23][MAXN],sum[23][MAXN];
char str[MAXN];
int last[MAXN];
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
    int cnt=0;
    scanf("%s",str+1);
    n=strlen(str+1);
    reverse(str+1,str+n+1);
    for(int i=1;i<=n;i++) if(str[i]=='?') cnt++;
    int ans=pow_mod(2,cnt),res=0;
    for(int i=1;i<=n;i++) if(str[i]=='B') last[i]=i; else last[i]=last[i-1];
    for(int i=1;i<=n;i++) if(str[i]!='S'&&last[i-1]==0) dp[1][i]=1; else dp[1][i]=0;
    for(int i=1;i<=n;i++) 
    {
        sum[1][i]=sum[1][i-1];
        add(sum[1][i],dp[1][i]);
    }
    for(int i=2;i<=22;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(str[j]=='S') continue;
            int len=1<<(i-2);
            if(j-len-1<1||last[j-1]>j-len-1) continue;
            add(dp[i][j],sum[i-1][j-len-1]);
            if(last[j-1]) dec(dp[i][j],sum[i-1][last[j-1]-1]);
        }
        for(int j=1;j<=n;j++)
        {
            sum[i][j]=sum[i][j-1];
            add(sum[i][j],dp[i][j]);
        }
    }
    if(last[n]==0) add(res,1);
    for(int i=n;i>=1;i--)
    {
        if(str[i]=='S') continue;
        for(int j=1;j<=22;j++) add(res,dp[j][i]);
        if(str[i]=='B') break;
    }
    dec(ans,res);
    printf("%d\n",ans);
    return 0;
}

