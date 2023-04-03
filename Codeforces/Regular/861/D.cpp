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
vector<int> pos[MAXN][2];
int s,t,st[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        pos[a[i]][i&1].push_back(i);
    }
    ll ans=1LL*(k-1)*(n-k+1)/2;
    for(int i=1;i<=200000;i++){
        for(int j=0;j<2;j++){
            for(auto x:pos[i][j]){
                int lb=max(x-k+1,1),rb=x-2;
                rb=min(rb,n-k+1+(n-x));
                lb=max(lb,1+(k-x));
                if(lb>rb) continue;
                int num=lower_bound(pos[i][j].begin(),pos[i][j].end(),rb+1)-lower_bound(pos[i][j].begin(),pos[i][j].end(),lb);
                ans-=num;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}

