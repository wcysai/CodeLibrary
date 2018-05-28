#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int main()
{
    while(scanf("%d",&n)==1)
    {
    int s=n;
    while(n>=7)
    {
        s+=n/7;
        n=n/7+n%7;
    }
    printf("%d\n",s);
    }
    return 0;
}
