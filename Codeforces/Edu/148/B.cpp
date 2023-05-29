#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
ll sum[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
        ll ans=0;
        for(int i=0;i<=k;i++){
            int l=1+2*i,r=n-(k-i);
            ans=max(ans,sum[r]-sum[l-1]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

