#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,p[MAXN],h[MAXN],dp[MAXN][MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
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
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            p[i]=1LL*x*pow_mod(y,MOD-2)%MOD;
        }
        for(int i=0;i<=n;i++) {scanf("%d",&h[i]); dp[0][i]=h[i];}
        for(int i=1;i<=n;i++)
            for(int j=0;j<=n-i;j++){
                dp[i][j]=1LL*p[i]*dp[i-1][max(1,j+1)]%MOD;
                add(dp[i][j],1LL*(MOD+1-p[i])*dp[i-1][max(0,j-1)]%MOD);
            }
        for(int i=1;i<=n;i++) printf("%d%c",dp[i][0],i==n?'\n':' ');
    }
    return 0;
}

