#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXN 10000000
using namespace std;
int n,a[MAXN];
int main()
{
    scanf("%d",&n);
    int maxv=0,maxind=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>maxv)
        {
            maxv=a[i];
            maxind=i;
        }
    }
    int sum=0,h=0;
    for(int i=0;i<maxind;i++)
    {
        if(a[i]>h) h=a[i];
        else sum+=h-a[i];
    }
    h=0;
     for(int i=n-1;i>maxind;i--)
    {
        if(a[i]>h) h=a[i];
        else sum+=h-a[i];
    }
    printf("%d\n",sum);
    return 0;
}
