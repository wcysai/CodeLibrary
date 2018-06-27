#include<bits/stdc++.h>
#define MAXN 300005
using namespace std;
int n,m,t,a[MAXN],bit[MAXN];
int main()
{
    scanf("%d",&t);
    for(int k=0;k<t;k++)
    {
    scanf("%d %d",&n,&m);
    memset(bit,0,sizeof(bit));
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int s=1;
    while(2*s<=m) s*=2;
    while(s>0)
    {
        for(int i=s+1;i<=n;i++)
            a[i]^=a[i-s];
        m-=s;
        while(s>m) s/=2;
    }
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}
