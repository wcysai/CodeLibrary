#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 35
#define MAXM 605
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
int dp[MAXN][MAXM],ndp[MAXN][MAXM];
int comb[MAXN][MAXN];
int pow_mod(int a,int i){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    comb[0][0]=1;
    for(int i=1;i<=30;i++){
        comb[i][0]=comb[i][i]=1;
        for(int j=1;j<i;j++){
            comb[i][j]=comb[i-1][j];
            add(comb[i][j],comb[i-1][j-1]);
        }
    }
    
    scanf("%d%d",&n,&m);
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        memset(ndp,0,sizeof(ndp));
        int maxi=i*(i-1)/2;
        for(int j=0;j<=i;j++)
            for(int k=0;k<=maxi;k++){
                if(!dp[j][k]) continue;
                //add to S
                for(int t=0;t<=j;t++)
                    add(ndp[j+1][k+t],1LL*comb[j][t]*dp[j][k]%MOD);
                //add to T
                for(int t=0;t<=i-j;t++)
                    add(ndp[j][k+t+j],1LL*comb[i-j][t]*dp[j][k]%MOD);
            }
        swap(dp,ndp);
    }
    int ans=0;
    for(int i=1;i<=n;i++) add(ans,dp[i][m]);
    printf("%d\n",ans);
    return 0;
}

