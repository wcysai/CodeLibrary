#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k;
ll a[MAXN];
bool check(ll x){
    ll p1=-1,p2=-1;
    for(int i=1;i<=n;i++){
        ll r=a[i]%x;
        if(p1==-1) p1=r;
        else if(p1==r) continue;
        else if(p2==-1) p2=r;
        else if(p2!=r) return false;
    }
    if(p2==-1) return false; else return true;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(ll x=2;;x*=2){
            if(check(x)) {printf("%lld\n",x); break;}
        }
    }
    return 0;

}

