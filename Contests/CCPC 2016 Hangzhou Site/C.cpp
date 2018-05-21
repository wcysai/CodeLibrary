#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
int query,n;
int a[MAXN],d[MAXN];
int main()
{
    scanf("%d",&query);
    int t=query;
    while(query--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<n;i++)
            d[i]=i==0?a[i]:a[i]-a[i-1];
        ll s=1,x=1;
        for(int i=n-1;i>0;i--)
        {
            x=(ll)ceil((double)(x*d[i-1])/d[i]);
            s+=x;
        }
         printf("Case #%d: %lld\n",t-query,s);
    }
    return 0;
}
