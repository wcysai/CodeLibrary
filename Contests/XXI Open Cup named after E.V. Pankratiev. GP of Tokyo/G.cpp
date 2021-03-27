#include<bits/stdc++.h>
#define MAXN (7*7*7*7*7*7*7)
#define MAXM 105
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXM],g=3;
ll k;
int w[7];
int f[MAXN];
int pow_mod(int a,ll i)
{
    int s=1;
    while(i>0)
     {
         if(i&1) s=(1LL*s*a)%MOD;
         a=(1LL*a*a)%MOD;
         i>>=1;
     }
     return s;
}
void dft(int n,int inv)
{
    static int tmp[7];
    for(int i=1;i<n;i*=7)
    {
        for(int l=0;l<n;l+=i*7)
        {
            for(int j=l;j<l+i;j++)
            {
                for(int a=0;a<7;a++) 
                    for(int b=tmp[a]=0;b<7;b++) 
                        tmp[a]=(tmp[a]+1LL*f[j+b*i]*w[b*(7+inv*a)%7])%MOD;
                for(int a=0;a<7;a++) f[j+a*i]=tmp[a];
            }
        }
    }
	if(inv==-1)
    {
        int x=pow_mod(n,MOD-2);
        for(int i=0;i<n;i++) f[i]=1LL*f[i]*x%MOD;
    }
}
int main()
{
    int omega=pow_mod(3,(MOD-1)/7);
    w[0]=1;
    for(int i=1;i<7;i++) w[i]=1LL*w[i-1]*omega%MOD;
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        int mask=0;
        for(int j=0;j<7;j++)
            mask=mask*7+((a[i]>>j)&1);
        f[mask]++;
    }
    dft(MAXN,1);
    for(int i=0;i<MAXN;i++) f[i]=pow_mod(f[i],k);
    dft(MAXN,-1);
    printf("%d\n",f[0]);
    return 0;
}