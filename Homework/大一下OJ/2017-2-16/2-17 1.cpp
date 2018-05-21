#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#define MAXN 1000
using namespace std;
int n,m,f,s=0,a[MAXN][MAXN];
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
          scanf("%d",&a[i][j]);
    for(int i=0;i<n;i++)
    {
        f=0;
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==1) f=1;
            if(a[i][j]==0&&f) s++;
        }
        f=0;
        for(int j=m-1;j>=0;j--)
        {
            if(a[i][j]==1) f=1;
            if(a[i][j]==0&&f) s++;
        }
    }
    for(int j=0;j<m;j++)
    {
        f=0;
        for(int i=0;i<n;i++)
        {
            if(a[i][j]==1) f=1;
            if(a[i][j]==0&&f) s++;
        }
        f=0;
        for(int i=n-1;i>=0;i--)
        {
            if(a[i][j]==1) f=1;
            if(a[i][j]==0&&f) s++;
        }
    }
    printf("%d\n",s);
    return 0;
}
