#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
int n,k,a[MAXN];
ll sum[MAXN];
ll dp[MAXN];
bitset<200001> bs;
vector<ll> add[MAXN],rem[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    bs.set(1);
    for(int i=1;i<=n;i++){
        bs|=(bs>>i)<<(i+a[i]);
    }
    ll s=0,ans=0;
    for(int i=1;i<=n;i++){
        s+=a[i];
        if(bs[i]) ans=max(ans,s-(i-1));
    }
    for(int i=n;i<=200000;i++){
        if(bs[i]) ans=max(ans,s-(i-1));
    }
    printf("%lld\n",ans);
    return 0;
}

