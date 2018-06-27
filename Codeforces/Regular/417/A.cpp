#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[4][4];
int main()
{
   for(int i=0;i<4;i++)
     for(int j=0;j<4;j++)
       scanf("%d",&a[i][j]);
   if(a[0][3])
   {
       if(a[0][0]||a[0][1]||a[0][2]||a[1][0]||a[3][2])
       {
           printf("YES\n");
           return 0;
       }
   }
   if(a[1][3])
   {
       if(a[1][0]||a[1][1]||a[1][2]||a[2][0]||a[0][2])
       {
           printf("YES\n");
           return 0;
       }
   }
   if(a[2][3])
   {
       if(a[2][0]||a[2][1]||a[2][2]||a[3][0]||a[1][2])
       {
           printf("YES\n");
           return 0;
       }
   }
   if(a[3][3])
   {
       if(a[3][0]||a[3][1]||a[3][2]||a[0][0]||a[2][2])
       {
           printf("YES\n");
           return 0;
       }
   }
   printf("NO\n");
   return 0;
}
