#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<queue>
#define MAXN 100005
using namespace std;
struct cow
{
    int t;
    int d;
};
bool cmp(cow x,cow y)
{
    return (x.d*y.t>x.t*y.d);
}
int main()
{
    int n,sum;
    long long sum2;
    cow a[MAXN];
    long long sum1;
    scanf("%d",&n);
    sum=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&a[i].t,&a[i].d);
        a[i].t*=2;
        sum+=a[i].d;
    }
    sort(a,a+n,cmp);
    sum2=0;
    for(int i=0;i<n;i++)
    {
        sum2+=a[i].t*(sum-a[i].d);
        sum-=a[i].d;
    }
    printf("%lld\n",sum2);
    return 0;
}