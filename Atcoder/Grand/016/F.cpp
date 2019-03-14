#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 18
#define MAXM 150
#define MASK (1<<15)
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
int n,m;
P a[MAXM];
int dp[MASK];
int pos[MAXN];
int p2[300];
vector<int> v[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int solve(int mask)
{
    if(__builtin_popcount(mask)==1) return 1;
    if(dp[mask]!=-1) return dp[mask];
    int &ans=dp[mask];
    ans=1;
    int sub=mask;
    do
    {
        sub=(sub-1)&mask;
        int sup=mask^sub;
        if(sub==0) break;
        int rem=(sub&3);
        if(rem==1||rem==2) continue;
        int res=1;
        for(int j=0;j<n;j++)
        {
            if(sub&(1<<j))
            {
                int cnt=__builtin_popcount(pos[j]&sup);
                if(!cnt)
                {
                    res=0;
                    break;
                }
                else res=1LL*res*(p2[cnt]-1)%MOD;
            }
            else if(sup&(1<<j))
            {
                int cnt=__builtin_popcount(pos[j]&sub);
                res=1LL*res*p2[cnt]%MOD;
            }
        }
        add(ans,1LL*res*solve(sub)%MOD);
    }while(sub!=mask);
    return ans;
}
int main()
{
    p2[0]=1;
    for(int i=1;i<=250;i++) p2[i]=2LL*p2[i-1]%MOD;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&a[i].F,&a[i].S);
        a[i].F--;a[i].S--;
        pos[a[i].F]|=(1<<a[i].S);
    }
    memset(dp,-1,sizeof(dp));
    int ans=p2[m];
    dec(ans,solve((1<<n)-1));
    printf("%d\n",ans);
    return 0;
}

