#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int a[MAXN];
int t,n,k;
int main()
{
   scanf("%d",&t);
   for(int i=0;i<t;i++)
   {
       scanf("%d %d",&n,&k);
       for(int j=0;j<n;j++)
          scanf("%d",&a[j]);
       sort(a,a+n);
       int cnt=1;
       for(int j=n-2;j>=0;j--)
        if(a[j]>=a[j+1]-k) cnt++; else break;
       printf("%d\n",cnt);
   }
   return 0;
}
