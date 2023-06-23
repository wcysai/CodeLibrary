#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int dp[MAXN][MAXN],ndp[MAXN][MAXN];
char s[MAXN];
int inv[MAXN];
int pow_mod(int a,int i){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int main()
{
    for(int i=1;i<=500;i++) inv[i]=pow_mod(i,MOD-2);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        scanf("%s",s+1);
        memset(dp,0,sizeof(dp));
        dp[1][n]=1;
        for(int i=1;i<=k;i++){
            memset(ndp,0,sizeof(ndp));
            if(s[i]=='L'){
                for(int l=1;l<=n;l++){
                    for(int r=l;r<=n;r++){
                        if(!dp[l][r]) continue;
                        if(l==r) {add(ndp[l][r],dp[l][r]); dec(ndp[l][r+1],dp[l][r]); continue;}
                        int tmp=1LL*inv[r-l]*dp[l][r]%MOD;
                        dec(ndp[l][r],tmp); add(ndp[l][l],tmp);
                    }
                }
                for(int l=1;l<=n;l++)
                    for(int r=1;r<=n;r++)
                        add(ndp[l][r],ndp[l][r-1]);
            }
            else{
                for(int l=1;l<=n;l++){
                    for(int r=l;r<=n;r++){
                        if(!dp[l][r]) continue;
                        if(l==r) {add(ndp[l][r],dp[l][r]); dec(ndp[l-1][r],dp[l][r]); continue;}
                        int tmp=1LL*inv[r-l]*dp[l][r]%MOD;
                        dec(ndp[l][r],tmp); add(ndp[r][r],tmp);
                    }
                }
                for(int r=1;r<=n;r++)
                    for(int l=n;l>=1;l--)
                        add(ndp[l][r],ndp[l+1][r]);
            }
            swap(dp,ndp);
        }
        int ans=0;
        for(int l=1;l<=n;l++){
            int sum=0;
            for(int r=l;r<=n;r++){
                add(sum,a[r]);
                add(ans,1LL*sum*dp[l][r]%MOD);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

