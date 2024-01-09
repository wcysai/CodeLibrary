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
int n,k,a[MAXN],b[MAXN];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) b[i]=a[i]-a[i-1];
    ll pos=0,neg=0;
    for(int i=1;i<=n;i++) if(b[i]>=0) neg+=(b[i]+1);
    ll ans=neg;
    for(int i=1;i<=n;i++){
        if(b[i]>=0) neg-=(b[i]+1);
        if(b[i]<=0) pos+=(-b[i]+1);
        ans=min(ans,max(neg,pos));
    }
    printf("%lld\n",ans);
    return 0;
}

