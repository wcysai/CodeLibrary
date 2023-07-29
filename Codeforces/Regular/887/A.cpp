#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 100000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
bool check(ll x){
    int now=n;
    for(int i=1;i<=k;i++){
        while(now>=1&&a[now]>x) now--;
        x-=now;
        if(!x) return false;
    }
    return true;
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        ll l=0,r=INF;
        while(r-l>1){
            ll mid=(l+r)/2;
            if(check(mid)) r=mid; else l=mid;
        }
        printf("%lld\n",r);
    }
    return 0;
}

