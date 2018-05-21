#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#define MAXN 100000
using namespace std;
int a,b,p,n;
int count(int x,int y)
{
    int s=0;
    while(x>0)
    {
        if(y==x%10) s++;
        x=x/10;
    }
    return s;
}
int main()
{
    scanf("%d",&n);
    for(int j=0;j<n;j++)
    {
    scanf("%d %d %d",&a,&b,&p);
    int sum=0;
    for(int i=a;i<=b;i++)
    {
        sum+=count(i,p);
    }
    printf("%d\n",sum);
    }
    return 0;
}
