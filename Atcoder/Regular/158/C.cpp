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
int n;
ll a[MAXN],ans;
int bit[2*MAXN];
int sum(int i){
    int s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x){
    while(i<=2*n){
        bit[i]+=x;
        i+=i&-i;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        ll tmp=a[i];
        while(tmp){
            ans+=(2*n)*(tmp%10);
            tmp/=10;
        }
    }
    ll s=1;
    for(int i=1;i<=15;i++){
        s*=10;
        vector<ll> v;
        for(int j=1;j<=n;j++){
            v.push_back(a[j]%s);
            v.push_back(s-a[j]%s);
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        for(int j=1;j<=2*n;j++) bit[j]=0;
        for(int j=1;j<=n;j++){
            int id=lower_bound(v.begin(),v.end(),a[j]%s)-v.begin()+1;
            add(id,1);
        }
        for(int j=1;j<=n;j++){
            int id=lower_bound(v.begin(),v.end(),s-a[j]%s)-v.begin()+1;
            ans-=(n-sum(id-1))*9;
        }
    }
    printf("%lld\n",ans);
    return 0;
}

