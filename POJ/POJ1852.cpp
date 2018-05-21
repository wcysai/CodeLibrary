#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define INF 10000000
using namespace std;
int main()
{
    int l,n,ant,t;
    scanf("%d",&t);
    for(int j=1;j<=t;j++)
    {
      scanf("%d %d",&l,&n);
      int maxi,mini;
      maxi=-INF;
      mini=-INF;
      for(int i=0;i<n;i++)
      {
         scanf("%d",&ant);
         maxi=max(maxi,max(ant,l-ant));
         mini=max(mini,min(ant,l-ant));
      }
      printf("%d %d\n",mini,maxi);
    }
    return 0;
}