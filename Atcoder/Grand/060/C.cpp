#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a,b;
int p2[MAXN];
int dp[MAXN][MAXN];
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
int calc_mag(int a,int b){
    int x=p2[a]; dec(x,1);
    int y=p2[b]; dec(y,1);
    int z=x; add(z,y);
    return 1LL*x*pow_mod(z,MOD-2)%MOD;
}
int main()
{
    p2[0]=1;
    for(int i=1;i<=5000;i++) p2[i]=2LL*p2[i-1]%MOD;
    scanf("%d%d%d",&n,&a,&b);
    for(int i=n-a;i<=n-1;i++)
        for(int j=n-b;j<=n-1;j++){
            int l=calc_mag(i,j);
            int r=1; dec(r,l);
            int res=1LL*l*(i==n-a?1:dp[i-1][j])%MOD;
            add(res,1LL*r*(j==n-b?0:dp[i][j-1])%MOD);
            dp[i][j]=res;
        }
    printf("%d\n",dp[n-1][n-1]);
    return 0;
}

