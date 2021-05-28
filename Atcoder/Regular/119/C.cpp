#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
map<ll,int> cnt;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    ll cur=0,ans=0;
    cnt[cur]++;
    for(int i=1;i<=n;i++)
    {
        if(i&1) cur+=a[i]; else cur-=a[i];
        ans+=cnt[cur];
        cnt[cur]++;
    }
    printf("%lld\n",ans);
    return 0;
}