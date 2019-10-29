#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
int cnt[MAXN];
int solve(int buses)
{
    int ret=0;
    int alone=2*buses-k;
    for(int i=k;i>=k-alone+1;i--) ret=max(ret,cnt[i]);
    int i=1,j=k-alone;
    while(i<j)
    {
        ret=max(ret,cnt[i]+cnt[j]);
        i++; j--;
    }
    return ret;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    sort(cnt+1,cnt+k+1);
    ll ans=INF;
    for(int i=(k+1)/2;i<=k;i++) ans=min(ans,1LL*i*solve(i));
    printf("%lld\n",ans);
    return 0;
}
