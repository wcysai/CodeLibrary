#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1505
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,K,a[MAXN];
vector<int> pos;
ll dp[751][MAXN];
void add(ll &a,ll b) {a+=b; if(a>=INF) a%=MOD;}
int main()
{
    scanf("%d%d",&n,&K);
    int cnt=0;
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        if(a[i]) cnt++;
    }
    if(cnt>=n/2){
        for(int i=1;i<=n;i++) a[i]=1-a[i];
    }
    for(int i=1;i<=n;i++) if(a[i]) pos.push_back(i);
    int sz=(int)pos.size();
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=min(i,sz);j>=max(0,sz-(n-i));j--){
            int val;
            if(j!=sz) val=max(i+1-pos[j],pos[j]-(i+1));
            for(int k=K;k>=0;k--){
                if(!dp[j][k]) continue;
                if(j!=sz&&k+val<=K) add(dp[j+1][k+val],dp[j][k]);
            }
        }
    }
    ll ans=0;
    for(int i=(K&1);i<=K;i+=2) add(ans,dp[sz][i]);
    printf("%lld\n",ans%MOD);
    return 0;
}

