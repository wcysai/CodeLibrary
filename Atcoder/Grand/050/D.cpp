#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 45
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,num;
int dp[MAXN][MAXN][MAXN][MAXN];
//dp[i][j][k][l]:
//i people remaining
//first people moved j times
//k last people out of i moved j+1 times
//you are currently at l
int inv[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int solve(int i,int j,int k,int l)
{
    if(n-i>=num) return 0;
    if(j>=num) return 0;
    if(dp[i][j][k][l]!=-1) return dp[i][j][k][l];
    if(k==i) return dp[i][j][k][l]=solve(i,j+1,0,l);
    int items=num-(n-i),prob=1LL*inv[num-j]*items%MOD;
    int res=0;
    if(l==1)
    {
        add(res,prob); add(res,1LL*(MOD+1-prob)*solve(i,j,k+1,i)%MOD);
        return dp[i][j][k][l]=res;
    }
    add(res,1LL*prob*solve(i-1,j,k,l-1)%MOD);
    add(res,1LL*(MOD+1-prob)*solve(i,j,k+1,l-1)%MOD);
    return dp[i][j][k][l]=res;
}
int main()
{
    inv[1]=1;
    for (int i=2;i<=40;i++)
        inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;
    scanf("%d%d",&n,&num);
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++) printf("%d\n",solve(n,0,0,i));
    return 0;
}

