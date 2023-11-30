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
int t,n,k,a[MAXN],cnt[MAXN];
int solve(int now,int rem,int need,int maxi){
    if(now==n){
        return cnt[now]=min(maxi,rem/(a[now]-need));
    }
    else{
        if(a[now]==a[now+1]){
            return solve(now+1,rem,need,maxi);
        }
        int all=min(maxi,rem/(a[now]-need));
        cnt[now]=all-solve(now+1,rem-all*(a[now]-need),a[now],all);
        return all;
    }
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=n-1;i>=1;i--) a[i]=min(a[i],a[i+1]);
        scanf("%d",&k);
        int cur=0;
        for(int i=1;i<=n;i++) cnt[i]=0;
        solve(1,k,0,INF);
        for(int i=n-1;i>=1;i--) cnt[i]+=cnt[i+1];
        for(int i=1;i<=n;i++) printf("%d%c",cnt[i],i==n?'\n':' ');
    }
    return 0;
}

