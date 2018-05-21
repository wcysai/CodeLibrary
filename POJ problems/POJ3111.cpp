#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MAXN 100001
#define INF 10000000
using namespace std;
struct mark
{
    int a;
    int b;
};
struct jewel
{
    int num;
    double value;
};
bool cmp(jewel x,jewel y)
{
    return x.value>y.value;
}
mark test[MAXN];
jewel c[MAXN];
int n,k;
bool C(double x)
{
    double sum=0;
    for(int i=0;i<n;i++)
    {
        c[i].value=test[i].a-test[i].b*x;
        c[i].num=i+1;
    }
    sort(c,c+n,cmp);
    for(int i=0;i<k;i++)
        sum+=c[i].value;
    return sum>=0;
}
int main()
{
    scanf("%d %d",&n,&k);
      for(int i=0;i<n;i++)
          scanf("%d %d",&test[i].a,&test[i].b);
      double left=0,right=INF;
     while(right-left>1e-6)
      {
          double mid=(left+right)/2;
          if(C(mid)) left=mid;
          else right=mid;
      }
      for(int i=0;i<k;i++)
        printf("%d ",c[i].num);
    return 0;
}