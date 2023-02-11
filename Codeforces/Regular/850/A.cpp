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
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int need=1;
        ll ans=0;
        for(int i=1;i<=n;i++){
            if(a[i]<need) continue;
            else if(a[i]==need) need++;
            else{
                ans+=a[i]-need;
                need++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

