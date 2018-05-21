#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MAXN 100000
#define INF 1000000000
using namespace std;
int n,c;
int stall[MAXN];
bool C(int x)
{
    int last=0;
    for(int i=1;i<c;i++)
    {
        int crt=last+1;
        while(crt<n&&stall[crt]-stall[last]<x)
            crt++;
        if(crt==n) return false;
        last=crt;
    }
    return true;
}
int main()
{
    scanf("%d %d",&n,&c);
    for(int i=0;i<n;i++)
        scanf("%d",&stall[i]);
    sort(stall,stall+n);
    int left=0,right=INF;
    while(right-left>1)
    {
        int mid=(left+right)/2;
        if(C(mid)) left=mid;
        else right=mid;
    }
    printf("%d\n",left);
    return 0;
}