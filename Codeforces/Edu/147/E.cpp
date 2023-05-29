#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,tot,n,k,a[MAXN];
ll dp[MAXN][6][6];
char str[MAXN];
void upd(ll &a,ll b) {a=min(a,b);}
// 0 1 2 3 1 2 2 1 1 2
//
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&k);
        scanf("%s",str+1);
        n=strlen(str+1); tot=0;
        int cnt=0;
        for(int i=n;i>=1;i--){
            if(str[i]==')') {cnt++; a[++tot]=cnt-1;} else cnt--;
        }
        //for(int i=1;i<=tot;i++) printf("%d ",a[i]);
        //puts("");
        a[tot+1]=0;
        for(int i=0;i<=tot+1;i++)
            for(int open=0;open<=k;open++)
                for(int closed=0;closed<=k;closed++)
                    dp[i][open][closed]=INF;
        dp[0][0][0]=0;
        for(int i=0;i<=tot;i++){
            for(int open=0;open<=k;open++)
                for(int closed=0;closed<=open;closed++){
                    if(dp[i][open][closed]==INF) continue;
                    for(int newly_open=0;open+newly_open<=k;newly_open++){
                        if(open+newly_open-closed>a[i+1]) continue;
                        upd(dp[i+1][open+newly_open][closed],dp[i][open][closed]+a[i+1]-open-newly_open+closed);
                    }
                    for(int newly_closed=0;closed+newly_closed<=open;newly_closed++){
                        if(open-closed-newly_closed>a[i+1]) continue;
                        upd(dp[i+1][open][closed+newly_closed],dp[i][open][closed]+a[i+1]-open+closed+newly_closed);
                    }
                }
        }
        ll ans=INF;
        for(int i=0;i<=k;i++) ans=min(ans,dp[tot+1][i][i]);
        printf("%lld\n",ans);
    }
    return 0;
}

