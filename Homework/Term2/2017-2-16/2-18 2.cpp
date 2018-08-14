#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXN 100+1
using namespace std;
int a[MAXN],n;
int main()
{
    scanf("%d",&n);
    n++;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            if(a[i]==-1) printf("-");
            else if(a[i]!=0&&a[i]!=1) printf("%d",a[i]);
        }
            else
            if(i==n-1)
            {
                if(a[i]>0) printf("+%d",a[i]);
                if(a[i]<0) printf("%d",a[i]);
            }
            else
            {
                if(a[i]>0&&a[i]!=1) printf("+%d",a[i]);
                if(a[i]<0&&a[i]!=-1) printf("%d",a[i]);
                if(a[i]==1) printf("+");
                if(a[i]==-1) printf("-");
            }
        if(i==n-2) printf("x");
        else if(i!=n-1&&a[i]!=0) printf("x^%d",n-i-1);
    }
    printf("\n");
    return 0;
}
