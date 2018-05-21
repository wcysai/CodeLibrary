#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,k;
int a[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        bool f=true;
        for(int j=0;j<n;j++)
        {
            if(i!=j&&max(a[i]-a[j],a[j]-a[i])<=k)
            {
                f=false;
                break;
            }
        }
        if(f) cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
