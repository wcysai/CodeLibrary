#include<bits/stdc++.h>
#define MAXN 100005
int t,n;
int a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=(n+1)/2;i++)
            a[i*2-1]=i;
        for(int i=(n+1)/2+1;i<=n;i++)
            a[2*(i-(n+1)/2)]=i;
        for(int i=1;i<=n;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}
