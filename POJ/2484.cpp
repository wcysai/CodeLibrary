#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#define MAXN 100005
using namespace std;
int n,k;
int a[MAXN];
int main()
{
    while(scanf("%d",&n)==1)
    {
        if(n==0) break;
        if(n<=2) puts("Alice");
        else puts("Bob");
    }
    return 0;
}
