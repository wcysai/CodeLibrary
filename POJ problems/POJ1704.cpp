#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<assert.h>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#define MAXN 100005
using namespace std;
int n,t;
int a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        if(n&1) a[n++]=0;
        sort(a,a+n);
        int x=0;
        for(int i=0;i<n-1;i+=2)
            x^=(a[i+1]-a[i]-1);
        if(x==0) puts("Bob will win");
        else puts("Georgia will win");
    }
    return 0;
}
