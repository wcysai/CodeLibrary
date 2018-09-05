#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
int n,k;
int a[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int s=0;
    for(int i=1;i<n-1;i++)
        s+=a[i];
    printf("%d\n",s/(n-2));
    return 0;
}
