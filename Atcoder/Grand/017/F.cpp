#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 20
#define MAXM (1<<20)
#define MAXK 405
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
int n,m,k,a[MAXK],b[MAXK],c[MAXK];
int go[MAXM][MAXN][2];
bool ban[MAXM][MAXN][2];
int dp[MAXN][MAXM];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    n--;
    memset(ban,false,sizeof(ban));
    for(int i=0;i<k;i++) 
    {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        ban[a[i]][b[i]][1-c[i]]=true;
    }
    for(int mask=0;mask<(1<<n);mask++)
    {
        for(int i=0;i<n;i++)
        {
            if(mask&(1<<i))
            {
                go[mask][i][0]=-1;
                go[mask][i][1]=mask;
            }
            else
            {
                go[mask][i][0]=mask;
                int newmask=mask^(1<<i);
                for(int j=i+1;j<n;j++) 
                {
                    if(newmask&(1<<j))
                    {
                        newmask^=(1<<j);
                        break;
                    }
                }
                go[mask][i][1]=newmask;
            }
        }
    }
    memset(dp,0,sizeof(dp));
    dp[n][0]=1;
    for(int i=1;i<=m;i++)
    {
        for(int mask=0;mask<(1<<n);mask++) dp[0][mask]=dp[n][mask];
        for(int pos=1;pos<=n;pos++)
            for(int mask=0;mask<(1<<n);mask++)
                dp[pos][mask]=0;
        for(int pos=0;pos<n;pos++)
        {
            for(int mask=0;mask<(1<<n);mask++)
            {
                if(!dp[pos][mask]) continue;
                if(!ban[i][pos+1][0]&&go[mask][pos][0]!=-1)
                {
                    int newmask=go[mask][pos][0];
                    add(dp[pos+1][newmask],dp[pos][mask]);
                }
                if(!ban[i][pos+1][1]&&go[mask][pos][1]!=-1)
                {
                    int newmask=go[mask][pos][1];
                    add(dp[pos+1][newmask],dp[pos][mask]);
                }
            }
        }
    }
    int ans=0;
    for(int mask=0;mask<(1<<n);mask++) add(ans,dp[n][mask]);
    printf("%d\n",ans);
    return 0;
}

