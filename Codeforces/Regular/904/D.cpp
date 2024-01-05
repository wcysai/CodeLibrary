#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int num[MAXN];
ll cnt[MAXN],res[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) cnt[i]=num[i]=res[i]=0;
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]); num[a[i]]++;}
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j+=i)
                cnt[i]+=num[j];
            cnt[i]=1LL*cnt[i]*(cnt[i]-1)/2;
        }
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j+=i)
                res[j]+=num[i];
        for(int i=n;i>=1;i--)
            for(int j=2*i;j<=n;j+=i)
                cnt[i]-=cnt[j];
        ll ans=0;
        for(int i=1;i<=n;i++) if(!res[i]) ans+=cnt[i];
        printf("%lld\n",ans);
    }
    return 0;
}

