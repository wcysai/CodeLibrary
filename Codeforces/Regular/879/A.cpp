#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int cnt=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]==1) cnt++;
        }
        int need=(n+1)/2,ans=0;
        if(cnt<need) {ans+=need-cnt; cnt=need;}
        if((n-cnt)&1) ans++;
        printf("%d\n",ans);
    }
    return 0;
}

