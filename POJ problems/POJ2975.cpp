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
#define MAXN 1005
using namespace std;
int n;
int a[MAXN];
int main()
{
    while(scanf("%d",&n)==1)
    {
        if(!n) break;
        int x=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            x^=a[i];
        }
        if(x==0) {printf("0\n"); continue;}
        int cnt=0;
        for(int i=0;i<n;i++)
            if((a[i]^x)<a[i]) cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
