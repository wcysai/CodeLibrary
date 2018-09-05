#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,k;
int a[MAXN],b[MAXN];
int num[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<n;i++)
        num[i-1]=a[i]>a[i-1]?0:1;
    if(b[n-2]==b[n-1]) num[n-1]=1; else num[n-1]=0;
    for(int i=0;i<n;i++)
        printf("%d",num[i]);
    return 0;
}

