#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,k;
int a[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<2*n;i++)
        scanf("%d",&a[i]);
    int cnt=0;
    for(int i=0;i<2*n;i+=2)
        if(a[i]==1) cnt++;
    printf("%d\n",min(cnt,n-cnt));
    return 0;
}

