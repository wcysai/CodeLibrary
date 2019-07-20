#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 80
#define INF 1000000000
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,K,MOD;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int f[MAXN][MAXN];
int g[2][MAXN][MAXN][MAXN];
int main()
{
    scanf("%d%d%d",&n,&K,&MOD);
    if(K%2==0)
    {
        f[0][0]=1;
        for(int i=0;i<75;i++)
            for(int j=0;j<=min(i,K/2);j++)
            {
                if(!f[i][j]) continue;
                if(j!=K/2) add(f[i+1][j+1],f[i][j]);
                add(f[i+1][0],f[i][j]);
            }
        int sum1=0,sum2=0;
        for(int i=0;i<=K/2;i++) add(sum1,f[(n+1)/2][i]),add(sum2,f[n/2][i]);
        printf("%lld\n",1LL*sum1*sum2%MOD);
    }
    else
    {
        dp[0][0][0][K+1]=1;
        for(int i=0;i<n;i++)
        {
            int now=(i+1)&1,nxt=now^1;
            memset(nxt,0,sizeof(nxt));
            if(i&1)
            {

            }
            else
            {
                for(int j=0;j<i/2+1;j++)
                    for(int k=0;k<=j;k++)
                        for(int l=0;l<=K+1;l++)
                        {
                            if(!g[now][j][k][l]) continue;
                            if(l!=0)
                            {
                                int cur=i/2+1;
                                int cnt1=cur-j,cnt2=cur-1-k;
                            }
                        }
            }
        }
    }
    return 0;
}

