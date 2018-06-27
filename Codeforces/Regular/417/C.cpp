#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#define MAXN 100000
using namespace std;
int cost[MAXN],save[MAXN];
int n,S;
int C(int x)
{
    for(int i=0;i<n;i++)
    {
        save[i]=cost[i]+x*(i+1);
    }
    sort(save,save+n);
    int s=0;
    for(int i=0;i<x;i++)
        s+=save[i];
    if(s<=S) return s; else return -1;
}
int main()
{
    scanf("%d %d",&n,&S);
    for(int i=0;i<n;i++)
        scanf("%d",&cost[i]);
    int lb=0,ub=n+1;
    while(ub-lb>1)
    {
        int mid=(lb+ub)/2;
        if(C(mid)>=0) lb=mid; else ub=mid;
    }
    printf("%d %d\n",lb,C(lb));
    return 0;
}
