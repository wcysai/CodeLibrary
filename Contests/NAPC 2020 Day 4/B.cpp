#include<bits/stdc++.h>
#define MAXN 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
int cnt[MAXN],a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            cnt[a[i]]++;
        }
        for(int i=0;i<20;i++)
            for(int j=0;j<(1<<20);j++)
                if(j&(1<<i)) cnt[j]+=cnt[j^(1<<i)];
        ll ans=0;
        for(int i=1;i<=n;i++) ans+=cnt[a[i]];
        printf("%lld\n",ans);
    }
    return 0;
}