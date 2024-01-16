#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000000000005LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN],b[MAXN];
bool check(ll x){
    ll cnt=0;
    for(int i=1;i<=n;i++){
        if(1LL*m*a[i]>=x){
            cnt+=m-(x+a[i]-1)/a[i];
        }
        else{
            cnt-=(x-1LL*m*a[i]+b[i]-1)/b[i];
        }
        if(cnt<=-1LL*n*m) return false;
    }
    return (cnt>=0)?true:false;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) {scanf("%d",&b[i]); a[i]=max(a[i],b[i]);}
    ll l=-1,r=INF;
    while(r-l>1){
        ll mid=(l+r)/2;
        if(check(mid)) l=mid; else r=mid;
    }
    printf("%lld\n",l);
    return 0;
}

