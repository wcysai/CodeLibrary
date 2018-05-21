#include<bits/stdc++.h>
#define MAXN 80005
using namespace std;
int n,x,y,t,same,_same;
char a[MAXN],b[MAXN];
int main()
{
    scanf("%d",&t);
    for(int j=0;j<t;j++)
    {
    scanf("%d %d %d",&n,&x,&y);
    scanf("%s",a);
    scanf("%s",b);
    same=_same=0;
    for(int i=0;i<n;i++)
        if(a[i]==b[i]) same++; else _same++;
    if(_same<max(x-y,y-x)||2*same+_same<x+y)
    {
        printf("Lying\n");
        continue;
    }
    printf("Not lying\n");
    }
    return 0;
}
