#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,k,a[MAXN];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        ll ans=0,sum=0;
        for(int i=1;i<=n;i++){
            if(!k) break;
            ans+=1LL*min(k,m)*(sum+a[i]);
            sum+=min(k,m);
            k-=min(k,m);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

