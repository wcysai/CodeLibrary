#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 65
#define MAXK 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
ll a[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    ll sum=0;
    set<ll> bad;
    for(int i=1;i<=min(1LL*n*k,a[1]-1);i++){
        bad.insert(i);
    }
    sum=a[1];
    for(int i=2;i<=n;i++){
        set<ll> tmp;
        for(auto x:bad){
            if(x<a[i]||bad.count(x-a[i])) tmp.insert(x);
        }
        if(sum<a[i]){
            for(ll j=sum+1;j<=min(sum+n*k,a[i]-1);j++) tmp.insert(j);
        }
        for(auto x:bad) if(x+a[i]>sum||bad.count(x+a[i])) tmp.insert(x+a[i]);
        while(tmp.size()>n*k) tmp.erase(*(--tmp.end()));
        swap(tmp,bad);
        //for(auto x:bad) printf("%lld ",x);
        //printf("\n");
        sum+=a[i];
    }
    while(bad.size()<k) {bad.insert(sum+1); sum++;}
    for(int i=0;i<k;i++){
        printf("%lld ",*bad.begin());
        bad.erase(bad.begin());
    }
    return 0;
}

