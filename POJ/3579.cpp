#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MAXN 100001
#define INF 1000000000
using namespace std;
int n;
int num[MAXN];
long long C(int x)
{
    long long cnt=0;
    for(int i=0;i<n;i++)
    {
        cnt+=lower_bound(num,num+n,num[i]+x)-upper_bound(num,num+n,num[i]-x)-1;
    }
    return cnt;
}
int main()
{
    while(scanf("%d",&n)==1)
    {
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    sort(num,num+n);
    int left=0,right=num[n-1]-num[0];
    while(right-left>1)
    {
        int mid=(left+right)/2;
        if(C(mid)>=n*(n-1)/2) right=mid;
        else left=mid;
    }
    printf("%d\n",left);
    }
    return 0;
}