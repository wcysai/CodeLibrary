#include<bits/stdc++.h>
#define MAXN 1000001
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n,num[MAXN],mu[MAXN];
ll ans[MAXN],ret[MAXN],mid[MAXN];
void getMu(int n)
{
    for(int i=1;i<=n;i++)
    {
        int target=i==1?1:0;
        int delta=target-mu[i];
        mu[i]=delta;
        for(int j=i+i;j<=n;j+=i)
            mu[j]+=delta;
    }
    return;
}
void sieve(int n)
{
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j+=i)
            num[j]++;
}
void sieve2(int n)
{
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j+=i)
            mid[j]=(mid[j]+mu[i]*ans[j/i]-mu[i]*ans[j/i-1])%MOD;
}
int main()
{
     memset(num,0,sizeof(num));
    memset(ans,0,sizeof(ans));
    memset(mu,0,sizeof(mu));
    getMu(MAXN-1);
    sieve(MAXN-1);
     ans[0]=0;
     ans[1]=1;
    for(int i=2;i<=MAXN-1;i++)
        ans[i]=(ans[i-1]+num[i-1]+1)%MOD;
    for(int i=2;i<=MAXN-1;i++)
        ans[i]=(ans[i]+ans[i-1])%MOD;
    sieve2(MAXN-1);
    ret[1]=1;
      for(int i=2;i<=MAXN-1;i++)
        ret[i]=(ret[i-1]+mid[i]+MOD)%MOD;
   while( scanf("%d",&n)==1)
   {
   printf("%lld\n",ret[n]);
   }
    return 0;
}
