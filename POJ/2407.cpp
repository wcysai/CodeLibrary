#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<assert.h>
#define MAXN 100005
using namespace std;
int n;
int phi(int n)
{
    int res=n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            res=res/i*(i-1);
            for(;n%i==0;n/=i);
        }
    }
    if(n!=1) res=res/n*(n-1);
    return res;
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        if(n==0) break;
        printf("%d\n",phi(n));
    }
    return 0;
}
