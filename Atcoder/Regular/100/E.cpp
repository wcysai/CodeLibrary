#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
P dp[MAXN];
int ans[MAXN];
void merge(P &x,P y)
{
    if(x.S>=y.F) return;
    if(y.S>=x.F) {x=y; return;}
    if(x.F>y.F) {x.S=y.F; return;}
    x.S=x.F; x.F=y.F; return;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<(1<<n);i++) scanf("%d",&a[i]);
    for(int i=0;i<(1<<n);i++) dp[i]=P(a[i],0);
    for(int i=0;i<n;i++)
        for(int mask=0;mask<(1<<n);mask++)
            if((mask&(1<<i))) merge(dp[mask],dp[mask^(1<<i)]);
    for(int i=0;i<(1<<n);i++)
    {
        ans[i]=dp[i].F+dp[i].S;
        if(i) ans[i]=max(ans[i],ans[i-1]);
        if(i) printf("%d\n",ans[i]);
    }
    return 0;
}

