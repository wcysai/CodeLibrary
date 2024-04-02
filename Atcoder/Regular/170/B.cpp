#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
const int threshold=20;
int cnt[11];
bool check(int l,int r){
    memset(cnt,0,sizeof(cnt));
    for(int i=l;i<=r;i++) cnt[a[i]]++;
    cnt[a[l]]--;
    for(int i=l+1;i<r;i++){
        cnt[a[i]]--;
        for(int j=l;j<i;j++) {
            int x=2*a[i]-a[j];
            if(x>=1&&x<=10&&cnt[x]) return true;
        }
    }
    return false;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    ll ans=0;
    for(int i=3;i<=min(threshold,n);i++){
        for(int j=1;i+j-1<=n;j++) if(check(j,j+i-1)) ans++;
    }
    if(n>threshold){
        ans+=1LL*(n-threshold)*(1+n-threshold)/2;
    }
    printf("%lld\n",ans);
    return 0;
}

