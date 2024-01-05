#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
ll k,a[MAXN];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%lld",&n,&k);
        ll mini=INF,maxi=-INF;
        for(int i=1;i<=n;i++) {
            scanf("%lld",&a[i]);
            mini=min(mini,a[i]); maxi=max(maxi,a[i]);
        }
        if(mini==maxi) {puts("0"); continue;}
        if(maxi<k){
            ll g=0,ans=0;
            for(int i=1;i<=n;i++) g=__gcd(g,k-a[i]);
            for(int i=1;i<=n;i++) ans+=(k-a[i])/g-1;
            printf("%lld\n",ans);
        }
        else if(mini>k){
            ll g=0,ans=0;
            for(int i=1;i<=n;i++) g=__gcd(g,a[i]-k);
            for(int i=1;i<=n;i++) ans+=(a[i]-k)/g-1;
            printf("%lld\n",ans);
        }
        else puts("-1");
    }
    return 0;
}

