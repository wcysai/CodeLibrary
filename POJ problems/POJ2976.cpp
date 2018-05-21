#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MAXN 1001
#define INF 1000000000
using namespace std;
struct mark
{
    long long a;
    long long b;
};
mark test[MAXN];
double c[MAXN];
int n,k;
bool C(double x)
{
    double sum=0;
    for(int i=0;i<n;i++)
        c[i]=test[i].a-test[i].b*x;
    sort(c,c+n);
    for(int i=0;i<n-k;i++)
        sum+=c[n-i-1];
    return sum>=0;
}
int main()
{
    scanf("%d %d",&n,&k);
    while(n!=0||k!=0)
    {
      for(int i=0;i<n;i++)
      {
          scanf("%lld",&test[i].a);
          test[i].a*=100;
      }
      for(int i=0;i<n;i++)
        scanf("%lld",&test[i].b);
      double left=0,right=INF;
     while(right-left>1e-4)
      {
          double mid=(left+right)/2;
          if(C(mid)) left=mid;
          else right=mid;
      }
      printf("%.0f\n",right);
      scanf("%d %d",&n,&k);
    }
    return 0;
}
