#include<bits/stdc++.h>
#define MAXN 1005
#define MOD 1000000007
using namespace std;
int t,n,k;
int l,r;
int a[MAXN];
char str[2*MAXN];
int main()
{
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d%d",&n,&k);
        for(int j=0;j<n;j++)
            scanf("%d",&a[j]);
        l=0,r=0;
        for(int j=0;j<n;j++)
        {
            scanf("%s",str);
            if(str[0]=='D')
            {
                l-=a[j];
            }
            else if(str[0]=='L')
            {
                r+=a[j];
            }
            else
            {
                l-=a[j];
                r+=a[j];
            }
        }
        if(k>=l&&k<=r) printf("yes\n"); else printf("no\n");
    }
    return 0;
}
