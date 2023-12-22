#include<bits/stdc++.h>
#define MAXN 200005
#define F first
#define S second
using namespace std;
typedef long long ll;
int t,n,c;
ll a[MAXN];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&c);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        multiset<pair<ll,ll> > s;
        for(int i=2;i<=n;i++) s.insert(make_pair(1LL*i*c-a[i],a[i]));
        ll now=a[1];
        while(s.size()){
            if(s.begin()->F>now){
                break;
            }
            now+=s.begin()->S;
            s.erase(s.begin());
        }
        if(s.size()) puts("NO"); else puts("YES");
    }
}
