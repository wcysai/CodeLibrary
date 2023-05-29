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
int t,n,k,a[MAXN],b[MAXN];
vector<int> save;
vector<int> qry;
int cnt[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        ll ans=0;
        for(int j=1;j<=650;j++){
            save.clear(); qry.clear();
            for(int i=1;i<=n;i++){
                if(a[i]==j) qry.push_back(b[i]); 
            }
            for(int i=1;i<=n;i++){
                ll res=1LL*j*a[i]-b[i];
                if(res>=1&&res<=n){
                    save.push_back(res);
                    if(a[i]>650) save.push_back(res);
                }
            }
            for(auto x:save) cnt[x]++;
            for(auto x:qry) ans+=cnt[x];
            for(auto x:save) cnt[x]--;
        }
        for(int i=1;i<=n;i++) if(1LL*a[i]*a[i]==2*b[i]) ans--;
        printf("%lld\n",ans/2);
    }
    return 0;
}

