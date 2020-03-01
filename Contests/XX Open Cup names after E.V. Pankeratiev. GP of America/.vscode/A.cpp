#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
int f[MAXN],g[MAXN];
//f[i]: answer when you know s
//g[i]: answer when you don't
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
    scanf("%d%d",&n,&k);
    if(n==1) puts("3");
    else if(k==1) printf("%d\n",pow_mod(3,n));
    else
    {
        f[0]=1; g[0]=1; g[1]=1; 
        for(int i=1;i<=n;i++)
        {
            f[i]=1LL*f[i-1]*(2*k+1)%MOD;
            if(i!=1) g[i]=(1LL*k*f[i-1]+g[i-1])%MOD;
        }
        printf("%d\n",g[n]);
    }
    return 0;
}