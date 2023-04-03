#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,c,d,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&c,&d);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        vector<int> v;
        v.push_back(a[1]);
        for(int i=2;i<=n;i++)
            if(a[i]!=a[i-1]) v.push_back(a[i]);
        ll ans=d+1LL*n*c;
        int need=0,last=0;
        for(int i=0;i<(int)v.size();i++){
            need+=(v[i]-last-1);
            last=v[i];
            ans=min(ans,1LL*(n-i-1)*c+1LL*need*d);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

