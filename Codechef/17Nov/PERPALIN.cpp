#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int t,p,n;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&p);
        int x=n/p;
        if(p==1||p==2)
        {
            printf("impossible\n");
            continue;
        }
        for(int i=0;i<x;i++)
        {
            printf("a");
            for(int i=0;i<p-2;i++)
                printf("b");
            printf("a");
        }
        printf("\n");
    }
    return 0;
}
