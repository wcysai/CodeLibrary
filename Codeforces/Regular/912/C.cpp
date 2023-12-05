#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
ll sum[MAXN];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sum[n+1]=0;
        for(int i=n;i>=1;i--) sum[i]=sum[i+1]+a[i];
        ll ans=sum[1];
        for(int i=2;i<=n;i++) if(sum[i]>0) ans+=sum[i];
        printf("%lld\n",ans);
    }
    return 0;
}

