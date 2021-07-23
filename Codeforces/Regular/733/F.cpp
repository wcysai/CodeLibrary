#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma") 
#define MAXN 25
#define INF 1000000000
#define MOD 31607
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int a[MAXN][MAXN];
int dp[(1<<21)][2][2][2],ndp[(1<<21)][2][2][2];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
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
int main()
{
    freopen("F.in","r",stdin);
    clock_t startTime,endTime;
      startTime = clock();
    scanf("%d",&n);
    int inv=pow_mod(10000,MOD-2);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            a[i][j]=a[i][j]*inv%MOD;
        }
    dp[0][0][0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<n;j++)
        {
            memset(ndp,0,sizeof(ndp));
            for(int mask=0;mask<(1<<n);mask++)
            {
                for(int row=0;row<2;row++)
                {
                    for(int diag=0;diag<2;diag++)
                    {
                        for(int adiag=0;adiag<2;adiag++)
                        {
                            if(!dp[mask][row][diag][adiag]) continue;
                            int val=dp[mask][row][diag][adiag];
                            int ndiag,nadiag;
                            if(j+1==i) ndiag=1; else ndiag=0;
                            if(j+1+i==n+1) nadiag=1; else nadiag=0; 
                            //fill
                            add(ndp[mask][row][diag][adiag],val*a[i][j+1]%MOD);
                            //not fill
                            add(ndp[mask|(1<<j)][1][diag|ndiag][adiag|nadiag],val*(MOD+1-a[i][j+1])%MOD);
                        }
                    }
                }
            }
            swap(dp,ndp);
        }
        memset(ndp,0,sizeof(ndp));
        for(int mask=0;mask<(1<<n);mask++)
            for(int diag=0;diag<2;diag++)
                for(int adiag=0;adiag<2;adiag++)
                    add(ndp[mask][0][diag][adiag],dp[mask][1][diag][adiag]);
        swap(dp,ndp);
    }
    int ans=MOD+1-dp[(1<<n)-1][0][1][1];
    if(ans>=MOD) ans-=MOD;
    printf("%d\n",ans);
    endTime = clock();//计时结束
     cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}