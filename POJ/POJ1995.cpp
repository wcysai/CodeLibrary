#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
long long rpa(long long x,long long y,long long mod)
{
    long long res=1;
    while(y>0)
    {
        if(y&1) res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
   return res;
}
int main()
{
    long long a,p,sum,m;
    int h,t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
    sum=0;
    scanf("%lld",&m);
    scanf("%d",&h);
    for(int i=1;i<=h;i++)
    {
      scanf("%lld %lld",&p,&a);
      sum=(sum+rpa(p,a,m))%m;
    }
    printf("%lld\n",sum);
    }
    return 0;
}
