#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
  int n,m,t,a[15],b[15],c[15];
  scanf("%d %d",&n,&m);
  for(int i=0;i<n;i++)
    a[i]=i+1;
  do
  {
      if(n==1)
      {
          printf("1");
          return 0;
      }
      for(int i=0;i<n;i++)
        c[i]=a[i];
      t=n;
      while(t>1)
      {
          for(int i=0;i<t-1;i++)
            b[i]=c[i]+c[i+1];
          for(int i=0;i<t-1;i++)
            c[i]=b[i];
          t--;
      }
      if(b[0]==m)
      {
          for(int i=0;i<n;i++)
            printf("%d ",a[i]);
          return 0;
      }
  }
  while(next_permutation(a,a+n));
  return 0;
}