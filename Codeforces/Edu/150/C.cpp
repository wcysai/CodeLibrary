#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
#define MAXN 200005
#define INF 10000000000000LL
#define MOD 1000000007
#define F first
#define S second
#define ing long long
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
char s[MAXN];
int dp[MAXN][5][2];
int val[5]={1,10,100,1000,10000};
void upd(int &a,int b) {a=max(a,b);}
signed main()
{
    scanf("%lld",&t);
    while(t--){
        scanf("%s",s+1);
        n=strlen(s+1);
        for(int i=1;i<=n+1;i++)
            for(int j=0;j<5;j++)
                for(int k=0;k<2;k++)
                    dp[i][j][k]=-INF;
        dp[n+1][0][0]=0;
        for(int i=n+1;i>=2;i--){
            for(int j=0;j<5;j++)
                for(int k=0;k<2;k++){
                    if(dp[i][j][k]==-INF) continue;
                    printf("%lld %lld %lld %lld\n",i,j,k,dp[i][j][k]);
                    int x=s[i-1]-'A';
                    upd(dp[i-1][max(j,x)][k],dp[i][j][k]+(j>x?-val[x]:val[x]));
                    if(!k){
                        for(int z=0;z<5;z++){
                            upd(dp[i-1][max(j,z)][1],dp[i][j][k]+(j>z?-val[z]:val[z]));
                        }
                    }
                }
        }
        int ans=-INF;
        for(int i=0;i<5;i++)
            for(int j=0;j<2;j++)
                upd(ans,dp[1][i][j]);
        printf("%lld\n",ans);
    }
    return 0;
}

