#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 300005
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
int n;
char str[MAXN];
int dp[MAXN][8];
//0: nothing
//1: 0
//2: 1
//3: 10
//4: 100
//5: 01
//6: 11
//7: 00
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
    scanf("%s",str+1);
    n=strlen(str+1);
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        bool f1=true,f2=true;
        if(str[i+1]=='0') f2=false;
        if(str[i+1]=='1') f1=false;
        if(f1)
        {
            add(dp[i+1][1],dp[i][0]);
            add(dp[i+1][7],dp[i][1]);
            add(dp[i+1][3],dp[i][2]);
            add(dp[i+1][4],dp[i][3]);
            add(dp[i+1][3],dp[i][4]);
            add(dp[i+1][1],dp[i][5]);
            add(dp[i+1][6],dp[i][6]);
            add(dp[i+1][1],dp[i][7]);
        }
        if(f2)
        {
            add(dp[i+1][2],dp[i][0]);
            add(dp[i+1][5],dp[i][1]);
            add(dp[i+1][6],dp[i][2]);
            add(dp[i+1][2],dp[i][3]);
            add(dp[i+1][3],dp[i][4]);
            add(dp[i+1][2],dp[i][5]);
            add(dp[i+1][6],dp[i][6]);
            add(dp[i+1][1],dp[i][7]);
        }
    }
    int ans=dp[n][2];
    add(ans,dp[n][6]);
    printf("%d\n",ans);
    return 0;
}

