#include<bits/stdc++.h>
#define MAXN 9000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int fact[MAXN],invf[MAXN];
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
    for(int i=1;i<=9000000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[9000000]=pow_mod(fact[9000000],MOD-2);
    for(int i=8999999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    int a,b,c,d;
    int ans=0;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    for(int i=0;i<=c-a;i++)
        for(int j=0;j<=d-b;j++)
        {
            int rem=(c-i)*(d-j)-a*b;
            printf("%d %d %d %d\n",i,j,rem,1LL*comb(c-a,i)*comb(d-b,j)%MOD*comb(rem,c+d-a-b)%MOD);
            if((i+j)&1) dec(ans,1LL*comb(c-a,i)*comb(d-b,j)%MOD*comb(rem,c+d-a-b)%MOD);
            else add(ans,1LL*comb(c-a,i)*comb(d-b,j)%MOD*comb(rem,c+d-a-b)%MOD);
        }
    printf("%d\n",ans);
    return 0;
}