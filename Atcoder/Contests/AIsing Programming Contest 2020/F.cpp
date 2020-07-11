#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N;
int fact[20],invf[20];
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
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=15;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[15]=pow_mod(fact[15],MOD-2);
    for(int i=14;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        int ans=0;
        for(int i=0;i<=11;i++)
        {
            if(N-5-i>=0&&(N-5-i)%2==0)
            {
                int j=(N-5-i)/2;
                int res=comb(11,i);
                res=1LL*res*invf[15]%MOD;
                for(int k=j+1;k<=j+15;k++) res=1LL*res*k%MOD;
                add(ans,res);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}