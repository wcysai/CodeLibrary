#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define MAXN 50005
#define INF 1000000000000000
using namespace std;
struct cow
{
    int wt;
    int str;
};
bool cmp(cow x,cow y)
{
    return x.wt+x.str>y.wt+y.str;
}
cow acro[MAXN];
int main()
{
    int n;
    long long ans,sum;
    sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&acro[i].wt,&acro[i].str);
        sum+=acro[i].wt;
    }
    sort(acro,acro+n,cmp);
    ans=-INF;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,sum-acro[i].wt-acro[i].str);
        sum-=acro[i].wt;
    }
    printf("%lld\n",ans);
    return 0;
}