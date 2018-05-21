#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MAXN 50005
#define INF 1000000000
using namespace std;
int l,n,m;
int stone[MAXN];
bool C(int d)
{
    int t=m;
    int last=0;
    int crt=1;
    if (l<d) return false;
    while(t>=0)
    {
        if(stone[crt]-stone[last]<d)
        {
            t--;
            crt++;
        }
        else
        {
            last=crt;
            crt++;
        }
        if(t<0) return false;
        if(crt>n+1) return true;
    }
}
int main()
{
  scanf("%d %d %d",&l,&n,&m);
  for(int i=1;i<=n;i++)
    scanf("%d",&stone[i]);
  stone[0]=0;
  stone[n+1]=l;
  sort(stone,stone+n+2);
  int left=0,right=INF;
  while(right-left>1)
  {
      int mid=(left+right)/2;
      if(C(mid)) left=mid;
      else right=mid;
  }
  printf("%d\n",left);
  return 0;
}