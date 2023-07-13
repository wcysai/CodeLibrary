#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int cnt=0;
    for(int i=3;i<=n;i++) if(a[i]>=a[1]&&a[i]<=a[2]) cnt++;
    if(cnt>=m) {puts("0"); return 0;}
    vector<int> v;
    for(int i=3;i<=n;i++) v.push_back(a[i]);
    ll ans=INF;
    sort(v.begin(),v.end());
    for(int i=0;i<=n-2-m;i++){
        ll need=max(0,a[1]-v[i]);
        need+=max(0,v[i+m-1]-a[2]);
        ans=min(ans,need);
    }
    printf("%lld\n",ans);
    return 0;
}

