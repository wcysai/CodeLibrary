#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 25
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
bool con[MAXN][MAXN];
int nb[MAXN];
int dp[(1<<20)][20];
int ans[MAXN];
int st;
bool check(int mask){
    for(int i=0;i<n;i++){
        if(mask&(1<<i)) continue;
        if(!(nb[i]&mask)) return false; 
    }
    return true;
}
void construct_sol(int mask,int i,int j){
    //printf("mask=%d i=%d j=%d\n",mask,i,j);
    puts("Yes");
    int nmask=(1<<n)-1-mask;
    ans[j]=i;
    int cur=j;
    while(nmask||mask){
        for(int k=0;k<n;k++){
            if((nmask&(1<<k))&&(nb[k]&(1<<cur))){
                ans[k]=cur;
                nmask^=(1<<k);
            }
        }
        if(mask==(1<<i)) break;
        for(int k=0;k<n;k++){
            if((mask&(1<<k))&&(dp[mask^(1<<cur)][i]&(1<<k))&&(nb[k]&(1<<cur))){
                ans[k]=cur;
                mask^=(1<<cur);
                cur=k;
                break;     
            }
        }
    }
    for(int k=0;k<n;k++) printf("%d%c",ans[k]+1,k==n-1?'\n':' ');
    exit(0);
}
void solve(){
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++) dp[(1<<i)][i]=(1<<i);
    for(int mask=0;mask<(1<<n);mask++){
        for(int ed=0;ed<n;ed++){
            if(!dp[mask][ed]) continue;
            //printf("mask=%d ed=%d dp=%d\n",mask,ed,dp[mask][ed]);
            for(int i=0;i<n;i++)
                if((!(mask&(1<<i)))&&(dp[mask][ed]&nb[i])) dp[mask^(1<<i)][ed]|=(1<<i);
        }
    }
    for(int mask=1;mask<(1<<n);mask++){
        if(__builtin_popcount(mask)<=1) continue;
        if(!check(mask)) continue;
        //printf("Mask=%d\n",mask);
        for(int i=0;i<n;i++){
          //  printf("Mask=%d i=%d dp=%d\n",mask,i,dp[mask][i]);
            if(!dp[mask][i]) continue;
            for(int j=0;j<n;j++){
                if(!(dp[mask][i]&(1<<j))) continue;
                if(!(nb[j]&(1<<i))) continue;
                construct_sol(mask,i,j);
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v); u--; v--;
        nb[u]|=(1<<v); nb[v]|=(1<<u);
    }
    solve();
    puts("No");
    return 0;
}

