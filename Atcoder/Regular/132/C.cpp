#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,d,a[MAXN],dp[MAXN][(1<<11)];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int mask=0;mask<(1<<(2*d+1));mask++)
        {
            if(!dp[i][mask]) continue;
            for(int nxt=i+1-d;nxt<=i+1+d;nxt++)
            {
                if(nxt<1||nxt>n) continue;
                if(a[i+1]!=-1&&nxt!=a[i+1]) continue;
                if(nxt-i+d<=2*d&&((mask>>(nxt-i+d))&1)) continue;
                if(i>=d+1&&!(mask&1)) continue;
                int nmask=(mask>>1)|(1<<(nxt-(i+1)+d));
                add(dp[i+1][nmask],dp[i][mask]);
            }
        }
    }
    printf("%d\n",dp[n][(1<<(d+1))-1]);
    return 0;
}