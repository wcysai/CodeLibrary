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
int t,n,k,a[MAXN],b[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) {b[i]=(a[i]-a[i-1])%k; if(b[i]<0) b[i]+=k;}
        ll ans=0,cur=0;
        multiset<int> ms;
        for(int i=1;i<=n;i++){
            int need=(k-b[i])%k;
            if(!need) continue;
            cur-=need; ms.insert(b[i]);
            if(cur<0){
                cur+=k;
                auto it=ms.begin();
                ms.erase(ms.begin());
                ans+=*it;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

