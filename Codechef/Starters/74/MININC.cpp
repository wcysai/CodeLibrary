#pragma GCC optimize(3)
#include<iostream>
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,a[MAXN],cnt1[MAXN],cnt2[MAXN];
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) cnt1[i]=cnt2[i]=0;
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]); cnt1[a[i]]++;}
        ll ans=0,sum=0;
        for(int i=n;i>=1;i--){
            sum+=cnt1[a[i]+1];
            sum-=cnt2[a[i]-1];
            cnt1[a[i]]--; cnt2[a[i]]++;
            ans=max(ans,sum);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

