#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,k,fact[MAXN],invf[MAXN],inv[MAXN];
int ways[MAXN][MAXN];
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
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=5000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[5000]=pow_mod(fact[5000],MOD-2);
    for(int i=4999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    for(int i=1;i<=5000;i++) inv[i]=1LL*invf[i]*fact[i-1]%MOD;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        int round=n/(k+1);
        int cur=n-round*(k+1);
        if(cur==0)
        {
            for(int i=1;i<=n;i++) printf("%d%c",0,i==n?'\n':' ');
            continue;
        }
        for(int i=1;i<=cur;i++) ways[0][i]=1;
        for(int i=1;i<=round;i++)
        {
            cur+=(k+1);
            for(int j=1;j<=cur;j++)
            {
                if(j==1) ways[i][j]=0;
                else
                {
                    ways[i][j]=0;
                    for(int pre=0;pre<=min(k,j-2);pre++) add(ways[i][j],1LL*comb(j-2,pre)*comb(cur-j,k-pre)%MOD*ways[i-1][j-1-pre]%MOD);
                }      
            }
        }
        int all=1;
        for(int i=1;i<=round;i++) all=1LL*all*comb(n-(i-1)*k-i,k)%MOD;
        all=pow_mod(all,MOD-2);
        for(int i=1;i<=n;i++) printf("%d%c",1LL*ways[round][i]*all%MOD,i==n?'\n':' ');
    }
    return 0;
}