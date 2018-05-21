#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int m1,m2,n1,n2;
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    while(scanf("%d %d %d %d",&m1,&m2,&n1,&n2)==4)
    {
      int denom1=m2*n2/gcd(m2,n2),denom2=denom1;
      int num1=m1*denom1/m2+n1*denom1/n2;
      int x=gcd(num1,denom1);
      x=max(x,-x);
      num1/=x,denom1/=x;
      int num2=m1*denom2/m2-n1*denom2/n2;
        x=gcd(num2,denom2);
        x=max(x,-x);
        num2/=x,denom2/=x;
      if (denom1>1&&num1!=0) printf("%d/%d ",num1,denom1); else printf("%d ",num1);
      if (denom2>1&&num2!=0) printf("%d/%d ",num2,denom2); else printf("%d ",num2);
      int denom3=gcd(m1*n1,m2*n2);
      if (m2*n2/denom3>1&&m1*n1/denom3!=0) printf("%d/%d ",m1*n1/denom3,m2*n2/denom3); else printf("%d ",m1*n1/denom3);
      int denom4=gcd(m1*n2,m2*n1);
      if (m2*n1/denom4>1&&m1*n2/denom4!=0) printf("%d/%d ",m1*n2/denom4,m2*n1/denom4); else printf("%d ",m1*n2/denom4);
      if(num2<0) printf("true\n"); else printf("false\n");
    }
    return 0;
}
