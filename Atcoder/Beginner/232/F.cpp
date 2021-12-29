#include<bits/stdc++.h>
#define MAXN 18
#define INF 8000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],b[MAXN];
ll x,y;
ll dp[(1<<18)];
void upd(ll &x,ll y) {x=min(x,y);}
int get_inv(int mask,int pos)
{
    int cnt=0;
    for(int i=0;i<pos;i++) if(!(mask&(1<<i))) cnt++;
    return cnt;
}
int main()
{
    scanf("%d%lld%lld",&n,&x,&y);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    for(int i=0;i<(1<<n);i++) dp[i]=INF;
    dp[0]=0;
    for(int mask=0;mask<(1<<n);mask++)
    {
        int nxt=__builtin_popcount(mask);
        for(int i=0;i<n;i++)
        {
            if(mask&(1<<i)) continue;
            upd(dp[mask^(1<<i)],dp[mask]+get_inv(mask,i)*y+1LL*max(b[nxt]-a[i],a[i]-b[nxt])*x);
        }
    }
    printf("%lld\n",dp[(1<<n)-1]);
    return 0;
}