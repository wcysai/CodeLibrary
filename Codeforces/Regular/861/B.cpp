#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
vector<int> col[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++){
            col[i].clear();
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++){
                int x; scanf("%d",&x);
                col[j].push_back(x);
            }
        }
        ll ans=0;
        for(int i=1;i<=m;i++){
            sort(col[i].begin(),col[i].end());
            ll sum=0;
            for(auto x:col[i]) sum+=x;
            ll s=0; 
            int cnt=0;
            for(auto x:col[i]){
                ans+=(sum-s-x)-1LL*(n-1-cnt)*x;
                ans+=1LL*cnt*x-s;
                cnt++; s+=x;
            }
        }
        printf("%lld\n",ans/2);
    }
    return 0;
}

