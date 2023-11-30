#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int cnt[MAXN];
int maxi,match[MAXN],dp[MAXN];
vector<int> pos[MAXN];
void clear(){
    for(int j=1;j<=maxi;j++) cnt[j]=0;
    maxi=0;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    ll ans=0;
    maxi=0;
    for(int l=1;l<=n;l++){
        clear();
        for(int i=l;i<=n;i++){
            if(a[i]>1&&(!cnt[a[i]-1])) {clear(); break;}
            else{
                ans++;
                maxi=max(maxi,a[i]);
                if(a[i]==1) cnt[1]++; else {cnt[a[i]-1]--; cnt[a[i]]++;}
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}

