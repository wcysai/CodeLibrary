#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#define MAXN 1005
using namespace std;
bool cmp(int m,int n)
{
    return m<n;
}
int main()
{
   int r,n,army[MAXN],cnt,k,t;
   scanf("%d %d",&r,&n);
   while(r!=-1||n!=-1)
   {
   for(int i=0;i<n;i++)
      scanf("%d",&army[i]);
   cnt=0;
   k=0;
   sort(army,army+n);
   while(k<n)
   {
       t=k;
       cnt++;
       while(army[k]<=army[t]+r)
         k++;
       k--;
       t=k;
       while(army[k]<=army[t]+r)
         k++;
   }
   printf("%d\n",cnt);
   scanf("%d %d",&r,&n);
   }
   return 0;
}