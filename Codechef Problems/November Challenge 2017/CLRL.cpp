#include<bits/stdc++.h>
#define MAXN 1000005
using namespace std;
int n,r,t,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        bool flag=true;
        scanf("%d%d",&n,&r);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int lb=0,rb=1e9+7;
        for(int i=0;i<n;i++)
        {
            if(a[i]>rb||a[i]<lb)
            {
                printf("NO\n");
                flag=false;
                break;
            }
            if(a[i]>r) rb=a[i];
            else lb=a[i];
        }
        if(flag) printf("YES\n");
    }
    return 0;
}
