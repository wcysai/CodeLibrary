#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
bool is_prime(long long x)
{
    for(int i=2;i*i<=x;i++)
        if(x%i==0) return false;
    return true;
}
bool pseudo(long long x,long long y)
{
    long long res=1;
    long long mod=y;
    long long t=x;
    while(y>0)
    {
        if(y&1) res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    if(res==t) return true; else return false;
}
int main()
{
    long long a,p;
    scanf("%lld %lld",&p,&a);
    while(p!=0&&a!=0)
    {
      if(pseudo(a,p)&&!is_prime(p)) printf("yes\n"); else printf("no\n");
      scanf("%lld %lld",&p,&a);
    }
    return 0;
}