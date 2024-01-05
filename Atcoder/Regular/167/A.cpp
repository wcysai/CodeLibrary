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
int n,m,a[MAXN];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int single=m*2-n,db=n-single;
    ll ans=0;
    for(int i=1;i<=db/2;i++) ans+=1LL*(a[i]+a[db+1-i])*(a[i]+a[db+1-i]);
    for(int i=db+1;i<=n;i++) ans+=1LL*a[i]*a[i];
    printf("%lld\n",ans);
    return 0;
}

