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
int n,q,a[MAXN];
vector<P> v;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        int cnt=1,x=a[i];
        while(x%2==0) {x/=2; cnt*=2;}
        v.push_back(P(x,cnt));
    }
    int now=0;
    ll s=0;
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        ll x;
        scanf("%lld",&x);
        while(s+v[now].S<x) {s+=v[now].S; now++;}
        printf("%d\n",v[now].F);

    }
    return 0;
}

