#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N,K,a[MAXN];
bool check(ll x){
    ll sum=0;
    for(int i=1;i<=N;i++) sum+=min(x,1LL*a[i]);
    return sum>=1LL*K*x;
}
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&K);
        ll s=0;
        for(int i=1;i<=N;i++) {scanf("%d",&a[i]); s+=a[i];}
        ll l=0,r=s/K+1;
        while(r-l>1){
            ll mid=(l+r)/2;
            if(check(mid)) l=mid; else r=mid;
        }
        printf("%lld\n",l);
    }
    return 0;
}

