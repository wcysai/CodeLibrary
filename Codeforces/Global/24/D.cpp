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
int n,p;
void add(int &a,int b) {a+=b; if(a>=p) a-=p;}
void dec(int &a,int b) {a-=b; if(a<0) a+=p;} 
int dp[MAXN][MAXN],sum[MAXN][MAXN],res[MAXN];
int fact[MAXN];
int main()
{
    scanf("%d%d",&n,&p);
    fact[0]=1;
    for(int i=1;i<=n;i++) fact[i]=1LL*fact[i-1]*i%p;
    int lim=n/2;
    dp[1][0]=1; sum[1][0]=1;
    res[1]=fact[n-3];
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=i-1;j++)
        {
            if(i==j+1&&i<=lim) dp[i][j]=1;
            add(dp[i][j],sum[i-1][j]);
            if(i>1-lim&&j>lim) dec(dp[i][j],sum[i-1-lim-1][j-lim-1]);
            sum[i][j]=sum[i-1][j-1];
            //printf("i=%d j=%d dp=%d\n",i,j,dp[i][j]);
            add(sum[i][j],dp[i][j]);
        }
        if(n-2-i>=0)
        {
            for(int j=0;j<=i-1;j++)
                add(res[i],1LL*dp[i][j]*fact[n-2-i+j]%p);
        }
    }
    int ans=0;
    for(int i=1;i<=lim;i++)
        for(int j=1;j<=lim;j++)
            if(i+j>lim&&n-(i+j)>=1) add(ans,res[n-(i+j)]);
    ans=1LL*ans*n%p;
    if(n%2==0) add(ans,1LL*n*fact[n-2]%p);
    printf("%d\n",ans);
    return 0;
}

