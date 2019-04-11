#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int p,m;
int getphi(int x)
{
    int dummy=x,phi=1;
    for(int i=2;i<=10;i++)
    {
        int cnt=0;
        while(dummy%i==0) {dummy/=i; cnt++;}
        if(cnt>0)
        {
            phi*=(i-1);
            for(int j=0;j<cnt-1;j++) phi*=i;
        }
    }
    return phi;
}
int pow_mod(int a,int i,int mod)
{
    int s=1%mod;
    while(i)
    {
        if(i&1) s=1LL*s*a%mod;
        a=1LL*a*a%mod;
        i>>=1;
    }
    return s;
}
int solve(int mod)
{
    if(mod==1) return 0;
    return pow_mod(p,solve(getphi(mod))+getphi(mod),mod);
}
int main()
{
    freopen("limit.in","r",stdin);
    freopen("limit.out","w",stdout);
    scanf("%d%d",&p,&m);
    int fact=1;
    for(int i=1;i<=m;i++) fact=fact*i;
    printf("%d\n",solve(fact));
    return 0;
}
