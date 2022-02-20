#include<bits/stdc++.h>
#define MAXN 20
#define INF 1000000000000000000LL
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int num[MAXN][MAXN*MAXN];
int coef[MAXN];
int n;
ll m;
ll d[MAXN];
int comb[MAXN*MAXN][MAXN*MAXN];
ll pre[(1<<16)];
int dp[(1<<16)];
int main()
{
    scanf("%d%lld",&n,&m);
    for(int i=0;i<n;i++) scanf("%lld",&d[i]);
    memset(num,0,sizeof(num));
    comb[0][0]=1;
    for(int i=1;i<=n*n;i++)
    {
        comb[i][0]=comb[i][i]=1;
        for(int j=1;j<i;j++)
        {
            comb[i][j]=comb[i-1][j];
            add(comb[i][j],comb[i-1][j-1]);
        }
    }
    num[1][0]=1; coef[1]=1;
    for(int i=2;i<=n;i++)
    {
        coef[i]=0;
        for(int j=i-1;j<=i*(i-1)/2;j++)
        {
            num[i][j]=comb[i*(i-1)/2][j];
            for(int k=1;k<=i-1;k++)
            {
                for(int l=0;l<=j;l++)
                {
                    dec(num[i][j],1LL*comb[i-1][k-1]*num[k][l]%MOD*comb[(i-k)*(i-k-1)/2][j-l]%MOD);
                }
            }
            if(j&1) dec(coef[i],num[i][j]); else add(coef[i],num[i][j]);
        }
    }
    for(int mask=1;mask<(1<<n);mask++)
    {
        ll cur=1;
        for(int j=0;j<n;j++)
        {
            if(mask&(1<<j))
            {
                ll g=__gcd(cur,d[j]);
                cur/=g;
                if(INF/cur<d[j])
                {
                    cur=m+1;
                    break;
                }
                else cur*=d[j];
            }
        }
        pre[mask]=(m/cur)%MOD;
    }
    dp[0]=1;
    for(int i=1;i<(1<<n);i++)
    {
        int lbit=__builtin_ffs(i)-1;
        int nmask=i^(1<<lbit);
        int sub=nmask;
        do
        {
            add(dp[i],1LL*coef[__builtin_popcount(sub)+1]*dp[i^sub^(1<<lbit)]%MOD*pre[sub^(1<<lbit)]%MOD);
            sub=(sub-1)&nmask;
        }while(sub!=nmask);
    }
    printf("%d\n",dp[(1<<n)-1]);
    return 0;
}