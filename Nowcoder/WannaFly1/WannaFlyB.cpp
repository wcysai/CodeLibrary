#include<bits/stdc++.h>
#define MAXN 1005
using namespace std;
int n,a[MAXN],xr[MAXN],save[MAXN*MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    xr[0]=0;
    for(int i=1;i<=n;i++)
        xr[i]=xr[i-1]^a[i-1];
    int k=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<=n;j++)
        {
            save[k]=xr[j]^xr[i];
            k++;
        }
    sort(save,save+k);
    long long ans=0;
    for(int i=0;i<k;i++)
        ans+=upper_bound(save,save+k,-save[k])-lower_bound(save,save+k,-save[k]);
    ans/=2;
    printf("%lld\n",ans);
    return 0;
}
