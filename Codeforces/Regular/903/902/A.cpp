#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,c;
P a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&c);
        for(int i=1;i<=n;i++) scanf("%d",&a[i].S);
        for(int i=1;i<=n;i++) scanf("%d",&a[i].F);
        sort(a+1,a+n+1);
        ll ans=c;
        int num=1;
        for(int i=1;i<=n;i++){
            if(num<i){
                num++; ans+=c;
            }
            if(a[i].F<c){
                int need=min(n-num,a[i].S);
                ans+=1LL*a[i].F*need;
                num+=need;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

