#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<assert.h>
#define MAXN 2005
using namespace std;
int n;
int sg[MAXN];
int grundy(int x)
{
    if(x<0) return 0;
    if(sg[x]>=0) return sg[x];
    int s[MAXN]={0};
    for(int i=1;i<=x;i++)
        s[grundy(i-3)^grundy(x-i-2)]=1;
    int g=0;
    while(s[g]) g++;
    return sg[x]=g;
}
int main()
{
    memset(sg,-1,sizeof(sg));
    while(scanf("%d",&n)==1)
        if(grundy(n)==0) printf("2\n"); else printf("1\n");
    return 0;
}
