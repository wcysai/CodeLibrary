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
int cnt[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        if(a[1]==a[n])
        {
            printf("%d\n",n/2);
            continue;
        }
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            if(i<n&&a[i]==a[i+1]) continue;
            ans=max(ans,1LL*i*(n-i));
        }
        printf("%lld\n",ans);
    }
    return 0;
}

