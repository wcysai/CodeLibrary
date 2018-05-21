#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define INF 100000000000
using namespace std;
long long n,m;
long long Ci(long long x)
{
    long long cnt=0;
    for(long long i=1;i<=n;i++)
    {
        long long left1=0,right1=n+1;
        long long mid1;
        while(right1-left1>1)
        {
            mid1=(left1+right1)/2;
            if(mid1*mid1+i*i+100000*mid1-100000*i+mid1*i<x) left1=mid1;
            else right1=mid1;
        }
        cnt+=left1;
    }
    return cnt;
}
int main()
{
    long long k;
    scanf("%I64d",&k);
    for(long long j=0;j<k;j++)
    {
    scanf("%I64d %I64d",&n,&m);
    long long left=-100000*n;
    long long right=3*n*n+100000*n;
    while(right-left>1)
    {
        long long mid=(left+right)/2;
        if(Ci(mid)<m) left=mid;
        else right=mid;
    }
    printf("%I64d\n",left);
    }
    return 0;
}