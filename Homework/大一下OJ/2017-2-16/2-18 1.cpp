#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXN 10000
#define MAXM 100
#define INF 1000000
using namespace std;
int n,m,a[MAXM],save[MAXN];
int calc()
{
    int x,y;
    x=INF;
    y=0;
    for(int i=0;i<m;i++)
    {
        if(a[i]<x)
        {
            x=a[i];
            y=i;
        }
    }
    return y;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&save[i]);
        if(i<m) a[i]=save[i];
    }
    for(int i=m;i<n;i++)
    {
        a[calc()]+=save[i];
    }
     int x;
    x=-INF;
    for(int i=0;i<m;i++)
    {
        if(a[i]>x) x=a[i];
    }
    printf("%d\n",x);
    return 0;
}

