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
int n,k,a[MAXN];
int main(){
    scanf("%d",&n);
    ll sum=0;
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]); sum+=a[i];}
    ll ans=sum/3;
    for(int i=1;i<=n;i++) if(a[i]>2*(sum-a[i])) ans=sum-a[i];
    printf("%lld\n",ans);
    return 0;
}

